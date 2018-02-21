#ifndef LEXER_HPP
# define LEXER_HPP

# include <string>
# include <iostream>
# include <vector>
# include <Token.hpp>

Token getString(std::string str, size_t &i);
Token getDigit(std::string str, size_t &i);
Token getOperator(std::string str, size_t &i);
Token getSeparator(std::string str, size_t &i);

bool isseparator(char c);


std::vector<Token> lexer(std::string arg);

#endif
