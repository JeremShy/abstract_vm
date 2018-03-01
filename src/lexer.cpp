#include <lexer.hpp>
#include <LexicalException.hpp>

static bool isoperator(char c)
{
	if (c == '(' || c == ')')
		return true;
	else
		return false;
}

static bool isspace(char c)
{
	if (c == ' ')
		return true;
	else
		return false;
}

bool isseparator(char c)
{
	if (c == '\n')
		return true;
	else
		return false;
}

static void passCommentary(std::string str, size_t &i, size_t &lineNumber)
{
	while (i < str.length() and str[i] != '\n')
		i++;
	lineNumber++;
}

static void passSpaces(std::string str, size_t &i)
{
	while (i < str.length() && isspace(str[i]))
		i++;
	i--;
}


std::vector<Token> lexer(std::string arg)
{
	std::string str(arg);
	std::vector<Token> ret;
	size_t	lineNumber;

	std::cout << "Analyzing string : [" << str << "]" << std::endl;
	lineNumber = 1;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i])) //String
		{
			ret.push_back(getString(str, i, lineNumber));
		}
		else if (isdigit(str[i]) || (str[i] == '-')) //Real or integer
		{
			ret.push_back(getDigit(str, i, lineNumber));
		}
		else if (isoperator(str[i])) //operator
		{
			ret.push_back(getOperator(str, i, lineNumber));
		}
		else if (isseparator(str[i]))
		{
			ret.push_back(getSeparator(str, i, lineNumber));
		}
		else if (str[i] == ';')
		{
			passCommentary(str, i, lineNumber);
		}
		else if (isspace(str[i])) //space
		{
			passSpaces(str, i);
		}
		else
		{
			throw LexicalException("Unknow symbol [" + std::string(1, str[i]) + "] on line " + std::to_string(lineNumber));
		}
	}
	return ret;
}
