#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "regex.h"

#include "exceptions.h"

#if VERLANG_LOGS
#define logf(...) { printf(" \e[1;30m~ " __VA_ARGS__); printf("\e[0;37m"); }
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
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_FUCK,
    TOKEN_UNKNOWN,
    TOKEN_TYPE_COUNT
} TokenType;

typedef struct
{
    TokenType type;
    const char* pattern;
    regex_t regex;
} TokenPattern;

typedef struct {
    TokenType type;
    VERLANG_INT val;
} TOKEN;

extern TokenPattern TokenPatterns[];
extern const char* TokenTypeChar[];

void compile_patterns();
int check_pattern(TokenType TOKEN, char* _token);
TOKEN parse_token(char* _token);

#endif