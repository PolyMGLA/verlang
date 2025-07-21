#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "regex.h"

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
    TOKEN_MINUS,
    TOKEN_UNKNOWN,
    TOKEN_TYPE_COUNT
} TokenType;

typedef struct
{
    TokenType type;
    const char* pattern;
    regex_t regex;
} TokenPattern;

typedef struct TOKEN {
    TokenType type;

    VERLANG_INT val;
} TOKEN;

extern TokenPattern TokenPatterns[];
extern const char* TokenTypeChar[];

void compile_patterns();

TOKEN parse_token(char* _token);

#endif