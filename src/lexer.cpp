#include <lexer.hpp>

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

static void passCommentary(std::string str, size_t &i)
{
	while (i < str.length() and str[i] != '\n')
		i++;
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

	std::cout << "Analyzing string : " << str << std::endl;
	for (size_t i = 0; i < str.length(); i++)
	{
		// std::cout << "	Debut de la boucle for, on en est au caractere numero " << i << " qui est : " << str[i] << std::endl;
		if (isalpha(str[i])) //String
		{
			ret.push_back(getString(str, i));
		}
		else if (isdigit(str[i]) || (str[i] == '-')) //Real or integer
		{
			ret.push_back(getDigit(str, i));
		}
		else if (isoperator(str[i])) //operator
		{
			ret.push_back(getOperator(str, i));
		}
		else if (isseparator(str[i]))
		{
			ret.push_back(getSeparator(str, i));
		}
		else if (str[i] == ';')
		{
			passCommentary(str, i);
		}
		else if (isspace(str[i])) //space
		{
			passSpaces(str, i);
		}
		else // Throw exception unknown character
		{
			std::cout << "Error ! unknown character." << std::endl;
		}
	}
	return ret;
}
