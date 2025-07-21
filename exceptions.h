#include "stdlib.h"
#include "stdarg.h"
#include "stdio.h"

#ifndef VERLANG_EXCEPTIONS
#define VERLANG_EXCEPTIONS

typedef enum {
    _Ok,
    _InputFail,
    _UnknownToken,
    _ForbiddenToken,
    _ExceptionsCount
} VERLANG_EXCEPTION;

extern const char* VerlangExceptionsChar[];

void verlang_raise(VERLANG_EXCEPTION Exc_, ...);

#endif