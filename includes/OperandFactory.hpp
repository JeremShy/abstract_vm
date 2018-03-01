#ifndef OPERAND_FACTORY_CLASS_H
# define OPERAND_FACTORY_CLASS_H

# include <string>
# include <iostream>
# include <IOperand.hpp>

// typedef IOperand const * (OperandFactory::*t_operand_factory_func)(std::string const &)const;

class OperandFactory {
public:
	OperandFactory(void);

	IOperand const * createOperand(eOperandType type, std::string const & value) const;

private:
	static IOperand const * (OperandFactory::*_hashTable[5])(std::string const &) const;

	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;

};
#endif
