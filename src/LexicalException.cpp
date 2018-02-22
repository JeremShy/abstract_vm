#include <LexicalException.hpp>
#include <iostream>

LexicalException::LexicalException() : _what("Not defined")
{
}

LexicalException::LexicalException(const char *what)
{
	strncpy(_what, what, sizeof(_what) - 1);
}

const char * LexicalException::what() const throw()
{
	return _what;
}
