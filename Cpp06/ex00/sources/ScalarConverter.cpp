/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:15:53 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/02 15:37:25 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

void	CharConvert( double value );
void	IntConvert( double value );
void	FloatConvert( double value );
void	DoubleConvert( double value );

ScalarConverter::ScalarConverter( void )
{
	std::cout << "Scalar Converter default constuctor called" << std::endl;
	return;
}

ScalarConverter::ScalarConverter( ScalarConverter &copy )
{
	(void)copy;
	std::cout << "Scalar Converter copy constuctor called" << std::endl;
	return;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &copy )
{
	(void)copy;
	std::cout << "Scalar Converter assignement operator called" << std::endl;
	return ( *this );
}

void	CharConvert( double value )
{
	std::cout << "char: ";
	if ( value >= 0 && value <= 127 )
	{
		if ( !isprint(static_cast<char>( floor(value) ) ) )
		{
			std::cout << "non displayable" << std::endl;
			return;
		}
		std::cout << static_cast<char>( floor(value) ) << std::endl;	
	}
	else
		std::cout << "impossible" << std::endl;
	return;
}

void	IntConvert( double value )
{
	std::cout << "int: ";
	if ( value >= INT_MIN && value <= INT_MAX)
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	return;
}

void	FloatConvert( double value )
{
	std::cout	<< "float: " 
				<< std::fixed << std::setprecision(1)
				<< static_cast<float>(value)
				<< "f"
				<< std::endl;
	return;
}

void	DoubleConvert( double value )
{
	std::cout	<< "double: "
				<< std::setprecision(1)
				<< value
				<< std::endl;
	return;
}

void ScalarConverter::convert( std::string toConvert )
{	
	double		value;
	char		*endptr;
	std::string invalid = "nan";
	
	if ( toConvert.size() == 1 && isalpha( toConvert[0] ) )
		value = toConvert[0] + 0;
	else 
	{
		value = strtod( toConvert.c_str(), &endptr );
	if (*endptr == 'f')
		endptr++;
	else if (*endptr != '\0')
		value = strtod( invalid.c_str(), &endptr );
	}
	CharConvert( value );
	IntConvert( value );
	FloatConvert( value );
	DoubleConvert( value );	
	return;
}

ScalarConverter::~ScalarConverter( void )
{
	std::cout << "Scalar Converter destructor called" << std::endl;
	return;
}
