#include "vnode.h"
#include "lexer.h"

#include "stdio.h"
#include "stdlib.h"

#ifndef VERLANG_PARSER
#define VERLANG_PARSER

VNode* parse(TOKEN_LIST* parsed);

#endif