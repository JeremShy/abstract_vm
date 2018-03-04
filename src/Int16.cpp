#include <Int16.hpp>
#include <iostream>

Int16::Int16(void)
{
}

Int16::Int16(int16_t value)
{
	this->_value = value;
	this->_stringRepresentation = std::to_string(value);
	std::cout << "Creating an Int16 object with value : " << std::to_string(_value) << std::endl;
}

Int16::Int16(Int16 const & src)
{
	*this = src;
}

Int16::~Int16(void)
{
}

Int16 & Int16::operator=(Int16 const & rhs)
{
	_value = rhs._value;
	return *this;
}

int	Int16::getPrecision(void) const
{
	return static_cast<int>(OperandTypeInt16);
}

eOperandType	Int16::getType(void) const
{
	return OperandTypeInt16;
}
