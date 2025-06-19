/**
 * file: token.cpp
 *
 * date: 6/18/2025
 *
 * author: Sutinder S. Saini ( https://github.com/ssaini456123 )
 *
 */

#include "token.h"

bool slot_available(int pos, int expressionLen) {
    int next = pos + 1;

    if (expressionLen < next) {
        return false;
    }

    return true;
}

std::vector<Token> tokenize(std::string expression) {
    int pos = 0;
    int expressionLen = expression.length();
    std::vector<Token> tokens;

    while (pos < expressionLen) {
        char c = expression[pos];

        bool ischar = isalpha(c);

        std::string identifier;
        int next = pos;

        bool identScanned = false;

        while (ischar && slot_available(pos, expressionLen)) {
            char nextChar = expression[next];

            if (isspace(nextChar) || nextChar == '\n') {
                // either end of line or the macro definition begins
                identScanned = true;
                break;
            }

            identifier += nextChar;

            next++;
        }

        if (identScanned) {

            pos = next;

            Token t = {
                .type = IDENT,
                .value = identifier
            };

            tokens.push_back(t);

            continue;
        }

        switch (c) {
            case '#': {
                Token t = {
                    .type = POUND,
                    .value = "#"
                };

                tokens.push_back(t);
            }
            default: {
                Token t = {
                    .type = FOREIGN,
                    .value = "?"
                };

                tokens.push_back(t);
            }
        }

        pos++;
    }

    return tokens;
}

std::string tyToStr(TokenType t) {
    switch (t) {
        case FOREIGN:
            return "FOREIGN";
        case POUND:
            return "POUND";
        case IDENT:
            return "IDENT";
    }
}
