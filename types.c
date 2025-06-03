#include "types.h"

TOKEN parse_token(char* _token) {
    TOKEN res;
    logf("parsing %s\n", _token);

    if (!strcmp(_token, "+")) {
        logf("type: plus\n");
        res.type = TOKEN_PLUS;
        res.val = 0;
    } else if (!strcmp(_token, "-")) {
        logf("type: minus\n");
        res.type = TOKEN_MINUS;
        res.val = 0;
    } else {
        logf("type: int\n");
        res.type = TOKEN_INT;
        res.val = atoi(_token);
    }

    return res;
}