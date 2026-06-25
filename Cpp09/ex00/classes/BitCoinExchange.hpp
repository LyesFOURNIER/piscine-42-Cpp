/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:02:14 by lfournie          #+#    #+#             */
/*   Updated: 2026/06/25 11:17:55 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/lib.hpp"

class	BitCoinExchange
{
	public:
	
	BitCoinExchange(void);
	BitCoinExchange(const BitCoinExchange &);
	BitCoinExchange &operator=(const BitCoinExchange &);
	~BitCoinExchange();

	void	parseInput(const char *);
	
	private:
	
	std::map<std::string, float> _db;
	
};