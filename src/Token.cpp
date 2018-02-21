#include <Token.hpp>

Token::Token(void) {
}

Token::Token(tokentype_t type) : _type(type) {
}

Token::Token(tokentype_t type, std::string content) : _type(type), _content(content) {
	std::cout << "Creation d'un Token avec pour contenu : [" << content << "]. type = " << type << std::endl;
}


Token::Token(Token const & src) : _type(src._type), _content(src._content) {
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
	return (*this);
}