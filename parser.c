#include "parser.h"

VNode* parse(TOKEN_LIST* parsed) {
    VNode* par = malloc(sizeof(VNode));
    par->child[0] = make_int(parsed->list[0].val);
    par->child[1] = malloc(sizeof(VNode));
    par->op = TOKEN_PLUS;
    VNode* right = par->child[1];
    for (int i = 1; i < parsed->size; i += 2) {
        switch (parsed->list[i].type) {
            case TOKEN_PLUS:
                right->op = TOKEN_PLUS;
                right->child[0] = make_int(parsed->list[i + 1].val);
                break;
            case TOKEN_MINUS:
                right->op = TOKEN_PLUS;
                right->child[0] = make_int(-parsed->list[i + 1].val);
                break;
            default:
                // ???
                verlang_raise(_ForbiddenToken, TokenTypeChar[parsed->list[i].type]);
                break;
        }
        if (i + 2 != parsed->size) {
            right->child[1] = malloc(sizeof(VNode));
            right = right->child[1];
        } else {
            right->child[1] = make_int(0);
        }
    }

    return par;
}