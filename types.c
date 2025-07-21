#include "types.h"

TokenPattern TokenPatterns[] = {
    { TOKEN_INT,  "^[0-9]+$" },
    { TOKEN_PLUS, "^\\+$" },
    { TOKEN_MINUS, "^-$" },
    { TOKEN_FUCK, "^fuck$" },
    { TOKEN_UNKNOWN, "" },
    { TOKEN_TYPE_COUNT, "" },
};

const char* TokenTypeChar[TOKEN_TYPE_COUNT + 1] = {
    [TOKEN_INT] = "TOKEN_INT",
    [TOKEN_PLUS] = "TOKEN_PLUS",
    [TOKEN_MINUS] = "TOKEN_MINUS",
    [TOKEN_FUCK] = "TOKEN_FUCK",
    [TOKEN_UNKNOWN] = "TOKEN_UNKNOWN",
    [TOKEN_TYPE_COUNT] = "TOKEN_TYPE_COUNT",
};

void compile_patterns() {
    for (int i = 0; i < TOKEN_TYPE_COUNT; i++) {
        logf("compiling regex for %s\n", TokenTypeChar[TokenPatterns[i].type]);
        regcomp(&TokenPatterns[i].regex, TokenPatterns[i].pattern, REG_EXTENDED);
    }
}

TOKEN parse_token(char* _token) {
    TOKEN res;
    logf("parsing %s\n", _token);

    if (!regexec(&TokenPatterns[TOKEN_PLUS].regex, _token, 0, NULL, 0)) {
        res.type = TOKEN_PLUS;
        res.val = 0;
    } else if (!regexec(&TokenPatterns[TOKEN_MINUS].regex, _token, 0, NULL, 0)) {
        res.type = TOKEN_MINUS;
        res.val = 0;
    } else if (!regexec(&TokenPatterns[TOKEN_INT].regex, _token, 0, NULL, 0)) {
        res.type = TOKEN_INT;
        res.val = atoi(_token);
    } else {
        res.type = TOKEN_UNKNOWN;
        res.val = 0;
        char buffer[strlen(_token) + 1];
        snprintf(buffer, strlen(_token) + 19, "Unknown Token: %s", _token);
        verlang_raise(_UnknownToken, buffer);
    }

    return res;
}