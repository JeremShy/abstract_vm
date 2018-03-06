#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

std::string	to_string(int8_t nbr)
{
	return std::to_string(nbr);
}

std::string	to_string(int16_t nbr)
{
	return std::to_string(nbr);
}

std::string	to_string(int32_t nbr)
{
	return std::to_string(nbr);
}

std::string	to_string(float nbr)
{
	std::ostringstream	out;

	out << std::setprecision(std::numeric_limits<float>::max_digits10 - 1) << nbr;
	return (out.str());
}

std::string	to_string(double nbr)
{
	std::ostringstream	out;

	out << std::setprecision(std::numeric_limits<double>::max_digits10 - 1) << nbr;
	return (out.str());
}
