#include "lexer.h"

TOKEN_LIST* lexer(FILE* fp) {
    TOKEN* tokens = malloc(128 * sizeof(TOKEN));
    TOKEN_LIST* list = malloc(sizeof(TOKEN_LIST));
    list->list = tokens;
    list->size = 0;

    if (tokens == NULL) {
        verlang_raise(_InputFail, "failed to allocate memory for array");
    }

    if (!fp) {
        verlang_raise(_InputFail, "error while opening file");
    }
    int last = 0;
    char _token[129];
    while (fscanf(fp, "%128s", _token) != EOF) {
        tokens[last] = parse_token(_token);
        if (tokens[last].type == TOKEN_UNKNOWN || tokens[last].type == TOKEN_TYPE_COUNT) {
            verlang_raise(_ForbiddenToken, TokenTypeChar[tokens[last].type]);
        }
        last++;

        if (last % 128 == 0) {
            tokens = realloc(tokens, (last + 128) * sizeof(TOKEN));

            if (tokens == NULL) {
                verlang_raise(_InputFail, "failed to extend array");
            }
        }
    }

    list->list = tokens;
    list->size = last;

    return list;
}