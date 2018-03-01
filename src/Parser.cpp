#include <Parser.hpp>

std::map<eParserState, void (Parser::*)(void)> Parser::_stateMap =
{
	{Start, &Parser::stateStart},
	{ExpectingValue, &Parser::stateExpectingValue},
	{ExpectingOpeningBracket, &Parser::stateExpectingOpeningBracket}
};

Parser::Parser(std::vector<Token> const & tokens) : _tokens(tokens), _state(Start)
{
}

std::vector<Instruction>	Parser::getInstructions()
{
	/*
		Create an instruction list from the tokens.
	*/
	std::cout << "Starting to compute the instructions from the tokens." << std::endl;
	_iterator = _tokens.begin();

	while (_iterator != _tokens.end())
	{
		std::map<eParserState, void (Parser::*)(void)>::iterator it;

		it = _stateMap.find(_state);
		if (it == _stateMap.end())
			throw LexicalException("Didn't expect this state !");
		else
			(this->*(it->second))();
		_iterator++;
	}

	return _instructions;
}

Parser::Parser(void)
{
	std::cout << "Creating a parser." << std::endl;
	_state = Start;
}

void Parser::setToken(std::vector<Token> const & tokens)
{
	std::cout << "Setting a token for the parser." << std::endl;
	_tokens = tokens;
}

Parser::Parser(Parser const & src)
{
	*this = src;
}

Parser::~Parser(void)
{
}

Parser & Parser::operator=(Parser const & rhs)
{
	_tokens = rhs._tokens;
	_state = rhs._state;
	return *this;
}
