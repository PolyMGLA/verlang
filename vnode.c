#include "vnode.h"


VNode* make_VNode(TokenType op, VNode* left, VNode* right) {
    VNode* node = malloc(sizeof(VNode));

    node->op = op;
    node->left = left;
    node->right = right;
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
            node->res = calc_VNode(node->left) + calc_VNode(node->right);
            node->calc = 1;
            break;
        case TOKEN_MINUS:
            node->res = calc_VNode(node->left) - calc_VNode(node->right);
            node->calc = 1;
            break;
        default:
            // ????
        }
    }

    return node->res;
}