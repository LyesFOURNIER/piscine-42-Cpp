/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:43:15 by lfournie          #+#    #+#             */
/*   Updated: 2026/07/09 14:49:04 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/lib.hpp"

class	PmergeMe
{
	public:
	
	PmergeMe( void );
	PmergeMe( std::string );
	PmergeMe( const PmergeMe & );
	PmergeMe &operator=( const PmergeMe & );
	~PmergeMe( void );

	void	vectSort();
	void	dequeSort(std::vector<int>&);

	private:
	
	std::vector<int> _seq;
};