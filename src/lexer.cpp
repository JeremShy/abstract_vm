#include <lexer.hpp>

static bool isoperator(char c)
{
	if (c == '(' || c == ')')
		return (true);
	else
		return (false);
}

static bool isspace(char c)
{
	if (c == ' ')
		return (true);
	else
		return (false);
}

Token getString(std::string str, size_t &i)
{
	size_t		start;
	std::string content("");

	start = i;
	while (i < str.length() && (isdigit(str[i]) || isalpha(str[i])))
		i++;
	content = str.substr(start, i - start);
	Token ret(TOK_STRING, content);
	return (ret);
}

std::vector<Token> lexer(char *arg)
{
	std::string str(arg);
	std::vector<Token> ret;
	for (size_t i = 0; i < str.length(); i++)
	{
		std::cout << "	Debut de la boucle for, on en est au caractere numero " << i << " qui est : " << str[i] << std::endl;
		if (isalpha(str[i])) //String
		{
			getString(str, i);
		}
		else if (isdigit(str[i]) || (str[i] == '-')) //Real or integer
		{

		}
		else if (isoperator(str[i])) //operator
		{

		}
		else if (str[i] == ';')
		{
			if (i + 1 < str.length() && str[i + 1] == ';') // ;;
			{

			}
			else //Commentary
			{

			}
		}
		else if (isspace(str[i])) //space
		{

		}
		else //unknown (ERROR)
		{

		}
	}
	return (ret);
}
