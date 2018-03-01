#ifndef PARSER_HPP
# define PARSER_HPP

# include <Token.hpp>
# include <Instruction.hpp>
# include <LexicalException.hpp>
# include <vector>
# include <map>

enum eParserState {
	Start, // Just after a separator
	ExpectingValue, // after a push or an assert.
	ExpectingOpeningBracket // I think this is quite clear.
};

class Parser {

	// typedef void (Parser::t_ParserStateFunction)(void);

public:
	Parser(std::vector<Token> const & tokens);
	std::vector<Instruction> getInstructions();

	Parser(void);
	Parser(Parser const & src);
	~Parser(void);

	void setToken(std::vector<Token> const & tokens);

	Parser & operator=(Parser const & rhs);

private:

	static std::map<eParserState, void (Parser::*)(void)> _stateMap;

	std::vector<Token> _tokens;
	eParserState _state;
	std::vector<Token>::iterator	_iterator;
	std::vector<Token>::iterator	_currentInstructionSpecifier;
	std::vector<Token>::iterator	_currentTypeSpecifier;

	std::vector<Instruction> _instructions;


	void	stateStart(void);
	void	stateExpectingValue(void);
	void	stateExpectingOpeningBracket(void);
};

#endif
