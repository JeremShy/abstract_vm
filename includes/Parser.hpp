#ifndef PARSER_HPP
# define PARSER_HPP

# include <Token.hpp>
# include <vector>
# include <Instruction.hpp>

enum eParserState {
	Start // Just after a separator
};

class Parser {
public:
	Parser(std::vector<Token> const & tokens);
	std::vector<Instruction> getInstructions();

	Parser(void);
	Parser(Parser const & src);
	~Parser(void);

	void setToken(std::vector<Token> const & tokens);

	Parser & operator=(Parser const & rhs);

private:

	std::vector<Token> _tokens;
	eParserState _state;
	std::vector<Token>::iterator _iterator;
};

#endif
