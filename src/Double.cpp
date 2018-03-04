#include <Double.hpp>
#include <iostream>

Double::Double(void)
{
}

Double::Double(double value)
{
	this->_value = value;
	this->_stringRepresentation = std::to_string(value);
	std::cout << "Creating an Double object with value : " << _stringRepresentation << std::endl;
}

Double::Double(Double const & src)
{
	*this = src;
}

Double::~Double(void)
{
}

Double & Double::operator=(Double const & rhs)
{
	_value = rhs._value;
	return *this;
}

int	Double::getPrecision(void) const
{
	return static_cast<int>(OperandTypeDouble);
}

eOperandType	Double::getType(void) const
{
	return OperandTypeDouble;
}
