#include "parser.h"

VNode* parse(TOKEN_LIST* parsed) {
    VNode* par = malloc(sizeof(VNode));
    par->left = make_int(parsed->list[0].val);
    par->right = malloc(sizeof(VNode));
    par->op = TOKEN_PLUS;
    VNode* right = par->right;
    for (int i = 1; i < parsed->size; i += 2) {
        switch (parsed->list[i].type) {
            case TOKEN_PLUS:
                right->op = TOKEN_PLUS;
                right->left = make_int(parsed->list[i + 1].val);
                break;
            case TOKEN_MINUS:
                right->op = TOKEN_PLUS;
                right->left = make_int(-parsed->list[i + 1].val);
                break;
            default:
                // ???
                break;
        }
        if (i + 2 != parsed->size) {
            right->right = malloc(sizeof(VNode));
            right = right->right;
        } else {
            right->right = make_int(0);
        }
    }

    return par;
}