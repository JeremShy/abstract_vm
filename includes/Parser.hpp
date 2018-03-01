#ifndef PARSER_HPP
# define PARSER_HPP

# include <Token.hpp>
# include <vector>
# include <Instruction.hpp>

enum eParserState {
	Start, // Just after a separator
	ExpectingValue // after a push or an assert.
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
	std::vector<Token>::iterator	_iterator;
	std::vector<Token>::iterator	_previousInstruction;

	std::vector<Instruction> _instructions;


	void	stateStart(void);
	void	stateExpectingValue(void);
};

#endif
