#include <SyntaxicException.hpp>
#include <iostream>

SyntaxicException::~SyntaxicException(void) throw()
{
}

SyntaxicException & SyntaxicException::operator=(SyntaxicException const & rhs)
{
	memcpy(_what, rhs._what, sizeof(_what));
	return *this;
}

SyntaxicException::SyntaxicException() : _what("Not defined")
{
}

SyntaxicException::SyntaxicException(const char *what)
{
	strncpy(_what, what, sizeof(_what) - 1);
}

SyntaxicException::SyntaxicException(std::string const & what)
{
	strncpy(_what, what.c_str(), sizeof(_what) - 1);
}

const char * SyntaxicException::what() const throw()
{
	return _what;
}
