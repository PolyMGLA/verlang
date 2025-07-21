#ifndef VERSION
#define VERSION "???"
#endif

#include "types.h"
#include "vnode.h"
#include "lexer.h"
#include "parser.h"
#include "exceptions.h"

#include "stdio.h"

char* greet = "VerLang, version: " VERSION "\n";

int main(int argc, char *argv[]) {
    printf("%s", greet);
    compile_patterns();

    TOKEN_LIST* parsed = lexer(stdin);

    for (int i = 0; i < parsed->size; i++) {
        logf("%s %d\n", TokenTypeChar[parsed->list[i].type], parsed->list[i].val);
    }

    VNode* par = parse(parsed);

    printf("verl output: %d\n", calc_VNode(par));

    free(parsed->list);
    verlang_raise(_Ok);
}