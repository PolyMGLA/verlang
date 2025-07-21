#include "types.h"
#include "stdio.h"
#include "stdlib.h"
#include "exceptions.h"

#ifndef VERLANG_LEXER
#define VERLANG_LEXER

typedef struct TOKEN_LIST {
    TOKEN* list;
    int size;
} TOKEN_LIST;

TOKEN_LIST* lexer(FILE* f);

#endif