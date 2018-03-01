#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <eInstructionType.hpp>
# include <IOperand.hpp>

class Instruction {
public:
	Instruction(Instruction const & src);
	~Instruction(void);

	Instruction & operator=(Instruction const & rhs);
private:
	Instruction(void);

	eInstructionType _type;
	IOperand	*_value;
};

#endif
