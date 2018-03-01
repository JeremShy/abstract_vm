#include <Token.hpp>

std::string Token::enumStr[TOK_SIZEOFENUM] = {
   "string",
   "integer",
   "real",
   "operator",
   "separator"
};

Token::Token(void)
{
}

Token::Token(eTokenType type, size_t lineNumber) : _type(type), _lineNumber(lineNumber)
{
}

Token::Token(eTokenType type, std::string content, size_t lineNumber) : _type(type), _content(content), _lineNumber(lineNumber)
{
	std::cout << "Creation d'un Token avec pour contenu : [" << content << "]. type = " << type << " a la ligne " << lineNumber << std::endl;
}


Token::Token(Token const & src) : _type(src._type), _content(src._content), _lineNumber(src._lineNumber)
{
}

Token::~Token(void)
{
}

Token & Token::operator=(Token const & rhs)
{
	_type = rhs._type;
	_content = rhs._content;
	_lineNumber = rhs._lineNumber;
	return *this;
}

void		Token::setContent(std::string content)
{
	_content = content;
}

eTokenType	Token::getType(void) const
{
	return _type;
}

size_t		Token::getLine(void) const
{
	return _lineNumber;
}

std::string	Token::getTypeAsStr(void) const
{
	return enumStr[_type];
}

void		Token::setType(eTokenType type)
{
	_type = type;
}

std::string const & Token::getContent(void) const
{
	return _content;
}
