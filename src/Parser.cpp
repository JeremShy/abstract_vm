#include <Parser.hpp>
#include <LexicalException.hpp>
#include <vector>

Parser::Parser(std::vector<Token> const & tokens) : _tokens(tokens), _state(Start)
{
}

void Parser::stateStart(void)
{
	if (_iterator->getType() == TOK_STRING)
	{
		eInstructionType type;

		type = _iterator->getInstructionType();;
		if (type == Push || type == Assert)
		{
			std::cout << "Push or Assert instruction. Expecting an argument..." << std::endl;
			_previousInstruction = _iterator;
			_state = ExpectingValue;
		}
		else if (type == Undefined)
			throw LexicalException("Undefined Token [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
		else if (type == Int8 || type == Int16 || type == Int32 || type == Float || type == Double)
			throw LexicalException("Unexpected value specifier [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
		else
			_instructions.push_back(Instruction(type));
	}
	else if (_iterator->getType() == TOK_SEP)
	{
		std::cout << "Separator found." << std::endl;
	}
	else
	{
		throw LexicalException("Unexpected Token [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
	}
}

void	Parser::stateExpectingValue(void)
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
		if (_state == Start)
			stateStart();
		else if (_state == ExpectingValue)
			stateExpectingValue();
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
