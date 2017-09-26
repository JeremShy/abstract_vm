#include <Token.hpp>

Token::Token(void) {
}

Token::Token(tokentype_t type) : _type(type) {
}

Token::Token(tokentype_t type, std::string content) : _type(type), _content(content) {
	std::cout << "Creation d'un Token avec pour contenu : [" << content << "]." << std::endl;
}


Token::Token(Token const & src) : _type(src._type), _content(src._content) {
}

Token::~Token(void) {
}

Token & Token::operator=(Token const & rhs) {
	_type = rhs._type;
	_content = rhs._content;
	return (*this);
}
