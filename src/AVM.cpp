#include <AVM.hpp>
#include <iostream>
#include <LexicalException.hpp>

std::map<eInstructionType, void (AVM::*)(const Instruction &)> AVM::_funcMap =
{
	{Push, &AVM::ExecPush},
	{Pop, &AVM::ExecPop},
	{Dump, &AVM::ExecDump},
	{Assert, &AVM::ExecAssert},
	{Add, &AVM::ExecAdd},
	{Sub, &AVM::ExecSub},
	{Mul, &AVM::ExecMul},
	{Div, &AVM::ExecDiv},
	{Mod, &AVM::ExecMod},
	{Print, &AVM::ExecPrint},
	{Exit, &AVM::ExecExit}
};

AVM::AVM(void)
{
}

AVM::AVM(std::vector<Instruction> instructions) : _instructions(instructions)
{
}

AVM::AVM(AVM const & src)
{
	*this = src;
}

AVM::~AVM(void)
{
}

AVM & AVM::operator=(AVM const & rhs)
{
	_instructions = rhs._instructions;
	return *this;
}

void	AVM::execute(void)
{
	size_t	actualInstruction = 0;
	std::map<eInstructionType, void (AVM::*)(const Instruction &)>::iterator it;


	while (actualInstruction < _instructions.size())
	{
		it = _funcMap.find(_instructions[actualInstruction].getType());
		if (it == _funcMap.end())
		{
			throw LexicalException("Wut ? In AVM::execute()");
		}
		else
		{
			(this->*(it->second))(_instructions[actualInstruction]);
		}
		actualInstruction++;
	}
}

void	AVM::ExecPush(const Instruction & instruction)
{
	std::cout << "In ExecPush." << std::endl;
	_stack.push(instruction.getValue());
}
void	AVM::ExecPop(const Instruction & instruction)
{
	std::cout << "In ExecPop." << std::endl;
	if (_stack.size() > 0)
		_stack.pop();
	else
		throw LexicalException("Pop on empty stack.\n");
	(void)instruction;
}
void	AVM::ExecDump(const Instruction & instruction)
{
	std::cout << "In ExecDump." << std::endl;
	std::stack<const IOperand*> copy(_stack);

	int	nbr = 1;
	while (_stack.size() > 0)
	{
		const IOperand *operand = _stack.top();
		std::cout << nbr << " : " << operand->toString() << std::endl;
		nbr++;
		_stack.pop();
	}
	_stack = copy;

	(void)instruction;
}

void	AVM::ExecAssert(const Instruction & instruction)
{
	std::cout << "In ExecAssert." << std::endl;
	(void)instruction;
}

void	AVM::ExecAdd(const Instruction & instruction)
{
	std::cout << "In ExecAdd." << std::endl;
	(void)instruction;
}
void	AVM::ExecSub(const Instruction & instruction)
{
	std::cout << "In ExecSub." << std::endl;
	(void)instruction;
}
void	AVM::ExecMul(const Instruction & instruction)
{
	std::cout << "In ExecMul." << std::endl;
	(void)instruction;
}
void	AVM::ExecDiv(const Instruction & instruction)
{
	std::cout << "In ExecDiv." << std::endl;
	(void)instruction;
}
void	AVM::ExecMod(const Instruction & instruction)
{
	std::cout << "In ExecMod." << std::endl;
	(void)instruction;
}
void	AVM::ExecPrint(const Instruction & instruction)
{
	std::cout << "In ExecPrint." << std::endl;
	(void)instruction;
}
void	AVM::ExecExit(const Instruction & instruction)
{
	std::cout << "In ExecExit." << std::endl;
	(void)instruction;
}
