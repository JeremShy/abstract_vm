#include <iostream>
#include <stack>
#include <eOperandType.hpp>
#include <IOperand.hpp>
#include <lexer.hpp>
#include <Token.hpp>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter an argument" << std::endl;
		return (-1);
	}

	std::vector<Token> tokens = lexer(av[1]);
}
