#ifndef OPERANDTEMPLATE_HPP
# define OPERANDTEMPLATE_HPP
#include <IOperand.hpp>

template <typename T>
class OperandTemplate {
public:
	IOperand const * operator+( IOperand const & rhs ) const; //Sum
	IOperand const * operator-( IOperand const & rhs ) const; //Difference
	IOperand const * operator*( IOperand const & rhs ) const; //Product
	IOperand const * operator/( IOperand const & rhs ) const; //Quotient
	IOperand const * operator%( IOperand const & rhs ) const; //Modulo

	std::string const & toString( void ) const; // String representation of the instance

protected:
	T _value;
};

template <typename T>
std::string const & OperandTemplate<T>::toString(void) const
{
	std::to_string(_value);
}

template <typename T>
IOperand const * OperandTemplate<T>::operator+( IOperand const & rhs ) const
{
}

template <typename T>
IOperand const * OperandTemplate<T>::operator-( IOperand const & rhs ) const
{
}

template <typename T>
IOperand const * OperandTemplate<T>::operator*( IOperand const & rhs ) const
{
}

template <typename T>
IOperand const * OperandTemplate<T>::operator/( IOperand const & rhs ) const
{
}

template <typename T>
IOperand const * OperandTemplate<T>::operator%( IOperand const & rhs ) const
{
}

#endif
