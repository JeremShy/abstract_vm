#include <Parser.hpp>

void Parser::stateStart(void)
{
	if (_iterator->getType() == TOK_STRING)
	{
		eInstructionType type;

		type = _iterator->getInstructionType();
		if (type == Push || type == Assert)
		{
			std::cout << "Push or Assert instruction. Expecting an argument..." << std::endl;
			_currentInstructionSpecifier = _iterator;
			_state = ExpectingValue;
		}
		else if (type == Undefined)
			throw LexicalException("Undefined Token : [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
		else if (type == TypeInt8 || type == TypeInt16 || type == TypeInt32 || type == TypeFloat || type == TypeDouble)
			throw LexicalException("Unexpected value specifier : [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
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
	if (_iterator->getType() == TOK_STRING)
	{
		eInstructionType type;

		type = _iterator->getInstructionType();
		if (type == TypeInt8 || type == TypeInt16 || type == TypeInt32 || type == TypeFloat || type == TypeDouble)
		{
			std::cout << "Got a type specifier, expecting an opening bracket." << std::endl;
			_currentTypeSpecifier = _iterator;
			_state = ExpectingOpeningBracket;
		}
		else if (type != Undefined)
			throw LexicalException("Expected value specifier but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
		else
			throw LexicalException("Undefined Token [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
	}
	else
		throw LexicalException("Unexpected Token [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
}

void	Parser::stateExpectingOpeningBracket(void)
{
	if (_iterator->getType() == TOK_OPERATOR)
	{
		if (_iterator->getContent() == "(")
		{
			eInstructionType type;

			type = _currentTypeSpecifier->getInstructionType();
			if (type == TypeDouble || type == TypeFloat)
				_state = ExpectingDecimalNumber;
			else
				_state = ExpectingRelativeNumber;
		}
		else
			throw LexicalException("Expected a `(' but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
	}
	else
		throw LexicalException("Expected a `(' but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
}

void	Parser::stateExpectingRelativeNumber(void)
{
	if (_iterator->getType() == TOK_INTEGER)
	{
		const IOperand *operand;

		operand = createCurrentOperand();
		_instructions.push_back(Instruction(_currentInstructionSpecifier->getInstructionType(), operand));
		_state = ExpectingClosingBracket;
	}
	else
	{
		throw LexicalException("Expected a relative number but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
	}
}

void	Parser::stateExpectingDecimalNumber(void)
{
	if (_iterator->getType() == TOK_REAL)
	{
		const IOperand *operand;

		operand = createCurrentOperand();
		_instructions.push_back(Instruction(_currentInstructionSpecifier->getInstructionType(), operand));
		_state = ExpectingClosingBracket;
	}
	else
	{
		throw LexicalException("Expected a decimal number but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
	}
}

void	Parser::stateExpectingClosingBracket(void)
{
	if (_iterator->getType() == TOK_OPERATOR)
	{
		if (_iterator->getContent() == ")")
		{
			_state = ExpectingSeparator;
		}
		else
			throw LexicalException("Expected a `)' but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
	}
	else
		throw LexicalException("Expected a `)' but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
}

void	Parser::stateExpectingSeparator(void)
{
	if (_iterator->getType() == TOK_SEP)
	{
		_state = Start;
	}
	else
		throw LexicalException("Expected a separator but got [" + _iterator->getContent() + "] on line " + std::to_string(_iterator->getLine()));
}
