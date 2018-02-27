#include <Token.hpp>

Token::Token(void) {
}

Token::Token(tokentype_t type, size_t lineNumber) : _type(type), _lineNumber(lineNumber) {
}

Token::Token(tokentype_t type, std::string content, size_t lineNumber) : _type(type), _content(content), _lineNumber(lineNumber) {
	std::cout << "Creation d'un Token avec pour contenu : [" << content << "]. type = " << type << " a la ligne " << lineNumber << std::endl;
}


Token::Token(Token const & src) : _type(src._type), _content(src._content), _lineNumber(src._lineNumber) {
}

Token::~Token(void) {
}

void Token::setContent(std::string content)
{
	_content = content;
}

void Token::setType(tokentype_t type)
{
	_type = type;
}


Token & Token::operator=(Token const & rhs) {
	_type = rhs._type;
	_content = rhs._content;
	_lineNumber = rhs._lineNumber;
	return (*this);
}
