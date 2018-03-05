#include <Parser.hpp>

std::map<eParserState, void (Parser::*)(void)> Parser::_stateMap =
{
	{Start, &Parser::stateStart},
	{ExpectingValue, &Parser::stateExpectingValue},
	{ExpectingOpeningBracket, &Parser::stateExpectingOpeningBracket},
	{ExpectingRelativeNumber, &Parser::stateExpectingRelativeNumber},
	{ExpectingDecimalNumber, &Parser::stateExpectingDecimalNumber},
	{ExpectingClosingBracket, &Parser::stateExpectingClosingBracket},
	{ExpectingSeparator, &Parser::stateExpectingSeparator}
};

std::map<eInstructionType, eOperandType> Parser::_typeMap
{
	{TypeInt8, OperandTypeInt8},
	{TypeInt16, OperandTypeInt16},
	{TypeInt32, OperandTypeInt32},
	{TypeFloat, OperandTypeFloat},
	{TypeDouble, OperandTypeDouble}
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
			throw SyntaxicException("Didn't expect this state !");
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

eOperandType	Parser::instructionToOperand(eInstructionType src)
{
	std::map<eInstructionType, eOperandType>::iterator it;

	it = _typeMap.find(src);
	if (it != _typeMap.end())
		return it->second;
	throw SyntaxicException("Error !");
}

const IOperand	*Parser::createCurrentOperand()
{
	const IOperand			*operand;
	eInstructionType		instructionType;
	eOperandType			operandType;

	instructionType = _currentTypeSpecifier->getInstructionType();
	operandType = instructionToOperand(instructionType);
	operand = operandFactory.createOperand(operandType, _iterator->getContent());

	return (operand);
}
