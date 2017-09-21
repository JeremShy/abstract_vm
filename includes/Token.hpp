#ifndef TOKEN_CLASS_H
# define TOKEN_CLASS_H

# include <string>
# include <iostream>

typedef enum {
	TOK_STRING,
	TOK_INTGER,
	TOK_REAL,
	TOK_OPERATOR
} tokentype_t;

class Token {
public:
	Token(tokentype_t _type);
	Token(Token const & src);
	~Token(void);

	Token & operator=(Token const & rhs);

private:
	Token(void);
	std::string _content;
	tokentype_t _type;
};
#endif
