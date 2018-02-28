#ifndef PARSER_HPP
# define PARSER_HPP

# include <Token.hpp>
# include <vector>
# include <Instruction.hpp>

class Parser {
public:
	Parser(std::vector<Token> & tokens);
	std::vector<Instruction> getInstructions();
private:
	std::vector<Token> & _tokens;
};

#endif
