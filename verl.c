#ifndef VERSION
#define VERSION "???"
#endif

#include "types.h"
#include "vnode.h"
#include "lexer.h"
#include "parser.h"

#include "stdio.h"

char* greet = "VerLang, version: " VERSION "\n";

const char* TokenTypeChar[] = {
    [TOKEN_INT] = "TOKEN_INT",
    [TOKEN_PLUS] = "TOKEN_PLUS",
    [TOKEN_MINUS] = "TOKEN_MINUS"
};

int main(int argc, char *argv[]) {
    printf("%s", greet);

    TOKEN_LIST* parsed = lexer(stdin);

    for (int i = 0; i < parsed->size; i++) {
        logf("%s %d\n", TokenTypeChar[parsed->list[i].type], parsed->list[i].val);
    }

    VNode* par = parse(parsed);

    printf("res: %d\n", calc_VNode(par));

    free(parsed->list);
}