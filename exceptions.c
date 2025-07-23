#include "exceptions.h"

const char* VerlangExceptionsChar[_ExceptionsCount + 1] = {
    [_Ok] = "_Ok",
    [_InputFail] = "_InputFail",
    [_UnknownToken] = "_UnknownToken",
    [_ForbiddenToken] = "_ForbiddenToken",
    [_ExceptionsCount] = "_ExceptionsCount",
};


void verlang_raise(VERLANG_EXCEPTION Exc_, ...) {
    va_list args;
    va_start(args, Exc_);
    
    printf((Exc_ ? "\e[1;31m%s: %s\n\e[1;37m" : "\e[1;32m%s: %s\e[1;37m\n"), VerlangExceptionsChar[Exc_], va_arg(args, char*));

    exit(Exc_);
}