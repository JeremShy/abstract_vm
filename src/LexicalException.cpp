#include <LexicalException.hpp>
#include <iostream>

LexicalException::~LexicalException(void) throw()
{
}

LexicalException & LexicalException::operator=(LexicalException const & rhs)
{
	memcpy(_what, rhs._what, sizeof(_what));
	return *this;
}

LexicalException::LexicalException() : _what("Not defined")
{
}

LexicalException::LexicalException(const char *what)
{
	strncpy(_what, what, sizeof(_what) - 1);
}

LexicalException::LexicalException(std::string const & what)
{
	strncpy(_what, what.c_str(), sizeof(_what) - 1);
}

const char * LexicalException::what() const throw()
{
	return _what;
}
