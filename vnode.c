#include "vnode.h"


VNode* make_VNode(TokenType op, int chcnt, VNode* child[]) {
    VNode* node = malloc(sizeof(VNode) + chcnt * sizeof(VNode*));

    node->op = op;
    for (int i = 0; i < chcnt; i++) {
        node->child[i] = child[i];
    }
    node->calc = 0;

    return node;
}

VNode* make_int(VERLANG_INT val) {
    VNode* node = malloc(sizeof(VNode));

    node->op = TOKEN_INT;
    node->res = val;
    node->calc = 1;

    return node;
}

VERLANG_INT calc_VNode(VNode* node) {
    if (!node->calc) {
        switch (node->op) {
        case TOKEN_PLUS:
            node->res = calc_VNode(node->child[0]) + calc_VNode(node->child[1]);
            node->calc = 1;
            break;
        case TOKEN_MINUS:
            node->res = calc_VNode(node->child[0]) - calc_VNode(node->child[1]);
            node->calc = 1;
            break;
        default:
            // ????
        }
    }

    return node->res;
}