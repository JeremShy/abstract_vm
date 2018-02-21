#ifndef LEXER_HPP
# define LEXER_HPP

# include <string>
# include <iostream>
# include <vector>
# include <Token.hpp>

Token getString(std::string str, size_t &i);
Token getDigit(std::string str, size_t &i);
Token getOperator(std::string str, size_t &i);

std::vector<Token> lexer(std::string arg);

#endif
