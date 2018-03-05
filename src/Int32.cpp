#include <Int32.hpp>
#include <iostream>

Int32::Int32(void)
{
}

Int32::Int32(int32_t value)
{
	this->_value = value;
	this->_stringRepresentation = std::to_string(value);
	std::cout << "Creating an Int32 object with value : " << std::to_string(_value) << std::endl;
}

Int32::Int32(Int32 const & src)
{
	*this = src;
}

Int32::~Int32(void)
{
}

Int32 & Int32::operator=(Int32 const & rhs)
{
	_value = rhs._value;
	return *this;
}

int	Int32::getPrecision(void) const
{
	return static_cast<int>(OperandTypeInt32);
}

eOperandType	Int32::getType(void) const
{
	return OperandTypeInt32;
}