#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <eInstructionType.hpp>
# include <IOperand.hpp>

class Instruction {
public:
	Instruction();
private:
	eInstructionType _type;
	IOperand	*value;
};

#endif
