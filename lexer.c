#include "lexer.h"

TOKEN_LIST* lexer(FILE* fp) {
    TOKEN* tokens = malloc(128 * sizeof(TOKEN));
    TOKEN_LIST* list = malloc(sizeof(TOKEN_LIST));
    list->list = tokens;
    list->size = 0;

    if (tokens == NULL) {
        printf("failed to allocate memory for array\n");
        return list;
    }

    if (!fp) {
        printf("error while opening file\n");
        return list;
    }
    int last = 0;
    char _token[129];
    while (fscanf(fp, "%128s", _token) != EOF) {
        tokens[last] = parse_token(_token);
        last++;

        if (last % 128 == 0) {
            tokens = realloc(tokens, (last + 128) * sizeof(TOKEN));

            if (tokens == NULL) {
                printf("failed to extend array\n");
                return list;
            }
        }
    }

    list->list = tokens;
    list->size = last;

    return list;
}