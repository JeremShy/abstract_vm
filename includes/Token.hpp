#ifndef TOKEN_CLASS_H
# define TOKEN_CLASS_H

# include <string>
# include <iostream>

typedef enum {
	TOK_STRING,
	TOK_INTEGER,
	TOK_REAL,
	TOK_OPERATOR,
	TOK_SEP,
	TOK_SIZEOFENUM
} eTokenType;

class Token {
public:

	Token(void);
	Token(eTokenType _type, size_t lineNumber);
	Token(eTokenType type, std::string content, size_t lineNumber);
	Token(Token const & src);
	~Token(void);

	Token & operator=(Token const & rhs);

	void setContent(std::string content);
	void setType(eTokenType type);

	eTokenType	getType(void) const;
	size_t		getLine(void) const;
	std::string	getTypeAsStr(void) const;
	std::string const & getContent(void) const;

private:

	static std::string enumStr[TOK_SIZEOFENUM];

	eTokenType _type;
	std::string _content;
	size_t	_lineNumber;
};
#endif
