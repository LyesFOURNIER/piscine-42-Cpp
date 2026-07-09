/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:24:29 by lfournie          #+#    #+#             */
/*   Updated: 2026/07/07 10:36:00 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

bool	mathSignsCheck(char);
bool	charCheck(char);
long		execOperation(char, long *);

RPN::RPN( void )
{
	return;
}

RPN::RPN( char *input )
{
	for (int i = 0; input[i]; i++)
	{
		_input.push_back(input[i]);
	}
	return;
}

RPN::RPN( const RPN &copy ) : _input(copy._input)
{
	return;
}

RPN &RPN::operator=( const RPN &copy )
{
	if (_input != copy._input)
	{
		_input = copy._input;
	}
	return *this;
}

bool mathSignsCheck(char c)
{
	if( c != '+'
		&& c != '-'
		&& c != '/'
		&& c != '*')
		return false;
	return true;
}

bool charCheck(char c)
{
	if (!(c >= '0' && c <= '9')
		&& !mathSignsCheck(c)
		&& c != ' ')
		return false;
	return true;
}

bool RPN::parseInput( void )
{
	std::list<char>::iterator it = _input.begin();
	std::list<char>::iterator next = it;
	
	next++;
	next++;
	if (!(*it >= '0' && *it <= '9') && !(*next >= '0' && *next <= '9'))
	{
		std::cerr << "Error: first two entries must be digits" << std::endl;
		return false;
	}
	next--;
	while (it != _input.end())
	{
		if (*it == '(' || *it == ')')
		{
			std::cerr << "Error: brackets not supported" << std::endl;
			return false;
		}
		else if ((*it >= '0' && *it <= '9') && *next == '.')
		{
			std::cerr << "Error: decimal numbers not supported" << std::endl;
			return false;
		}
		else if ((*it >= '0' && *it <= '9')
				&& (*next >= '0' && *next <= '9'))
		{
			std::cerr << "Error: only single digit values are supported" << std::endl;
			return false;
		}
		else if (*it == '-' && (*next >= '0' && *next <= '9'))
		{
			std::cerr << "Error: digits in input cannot be negative" << std::endl;
			return false;
		}
		else if (!charCheck(*it))
		{
			std::cerr << "Error: only digits and \"+-/*\" operators are supported" << std::endl;
			return false;
		}
		while (_input.back() == ' ')
			_input.pop_back();
		if (_input.back() >= '0' && _input.back() <= '9')
		{
			std::cerr << "Error: input cannot end with a digit" << std::endl;
			return false;
		}
		it++;
		next++;
	}
	return true;
}

long execOperation(char current_operator, long *operands)
{
	switch (current_operator)
	{
	case '+':
		return (operands[1] + operands[0]);
	case '-':
		return (operands[1] - operands[0]);
	case '*':
		return (operands[1] * operands[0]);
	case '/':
		return (operands[1] / operands[0]);
	default:
		return 0;
	}
}

bool RPN::execInput( void )
{
	std::list<long>				tmp;
	std::list<char>::iterator 	it = _input.begin();
	long						operands[] = { 0, 0 };
	char						current_operator;
	
	if (!RPN::parseInput())
		return false;

	while(it != _input.end())
	{
		// operand = 0;
		if (*it == ' ')
				it++;
		if (!mathSignsCheck(*it) && *it != ' ')
			tmp.push_back(static_cast<long>(*it) - '0');
		else if (mathSignsCheck(*it) && *it != ' ')
		{
			current_operator = *it;
			if (tmp.size() == 1)
			{
				std::cerr << "Error: not enought operands for operation" << std::endl;
				return false;
			}
			operands[0] = tmp.back();
			tmp.pop_back();
			operands[1] = tmp.back();
			tmp.pop_back();
			if (!(operands[0] >= -2147483648 && operands[0] <= 2147483647)
				|| !(operands[1] >= -2147483648 && operands[1] <= 2147483647))
			{
				std::cerr << "Error: too large a number" << std::endl;
				return false;
			}
			if (current_operator == '/' && (operands[0] == 0 || operands[1] == 0))
			{
				std::cerr << "Error: division by zero" << std::endl;
				return false;
			}
			tmp.push_back(execOperation(current_operator, operands));
		}
		it++;
	}
	std::cout << tmp.back() << std::endl;
	return true;	
}

void RPN::printList( void )
{
	std::list<char>::iterator it = _input.begin();

	while (it != _input.end())
	{
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
	return;
}

RPN::~RPN( void )
{
	return;	
}