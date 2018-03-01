#include <Parser.hpp>
#include <LexicalException.hpp>
#include <vector>

Parser::Parser(std::vector<Token> const & tokens) : _tokens(tokens), _state(Start)
{
}

std::vector<Instruction>	Parser::getInstructions()
{
	std::vector<Instruction> ret;

	/*
		Create an instruction list from the tokens.
	*/
	std::cout << "Starting to compute the instructions from the tokens." << std::endl;
	_iterator = _tokens.begin();

	while (_iterator != _tokens.end())
	{
		if (_state == Start)
		{
			if (_iterator->getType() == TOK_STRING)
			{
				std::cout << "String found." << std::endl;
			}
			else if (_iterator->getType() == TOK_SEP)
			{
				std::cout << "Separator found." << std::endl;
			}
			else
			{
				throw LexicalException("Unexpected Token of type " + _iterator->getTypeAsStr() + " on line " + std::to_string(_iterator->getLine()));
			}
		}
		_iterator++;
	}

	return ret;
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
