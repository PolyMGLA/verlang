#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#if VERLANG_LOGS
#define logf(...) printf(__VA_ARGS__)
#else
#define logf(...)
#endif

#ifndef VERLANG_TYPES
#define VERLANG_TYPES

typedef int VERLANG_INT;

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS
} TokenType;

typedef struct TOKEN {
    TokenType type;

    VERLANG_INT val;
} TOKEN;

TOKEN parse_token(char* _token);

#endif