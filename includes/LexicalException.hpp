#ifndef LEXICAL_EXCEPTION_HPP
# define LEXICAL_EXCEPTION_HPP

# include <exception>
# include <string>

class LexicalException : public std::exception
{
private:
	char _what[64];
	LexicalException();
public:
	LexicalException(const char *what);
	const char * what() const throw();
};

#endif
