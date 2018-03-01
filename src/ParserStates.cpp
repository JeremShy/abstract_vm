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
	
}
