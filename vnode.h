#include "types.h"

#include <stdlib.h>

#ifndef VERLANG_NODE
#define VERLANG_NODE

typedef struct VNode {
    TokenType op;
    VERLANG_INT res;
    int calc;
    struct VNode* left;
    struct VNode* right;
} VNode;

VNode* make_VNode(TokenType op, VNode* left, VNode* right);
VNode* make_int(VERLANG_INT val);
VERLANG_INT calc_VNode(VNode* node);

#endif