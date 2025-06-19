/**
 * file: token.h
 *
 * date: 6/18/2025
 *
 * author: Sutinder S. Saini ( https://github.com/ssaini456123 )
 *
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>

enum TokenType {
    POUND,
    IDENT,
    FOREIGN
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(std::string);

std::string tyToStr(TokenType);

bool slot_available(int, int);

#endif //TOKEN_H
