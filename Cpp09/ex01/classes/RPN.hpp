/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:24:17 by lfournie          #+#    #+#             */
/*   Updated: 2026/07/01 12:01:08 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/lib.hpp"

class RPN
{
	public:
	
	RPN( void );
	RPN( char * );
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();

	bool	parseInput();
	bool	execInput();

	void	printList();

	private:

	std::list<char> _input;
	
};