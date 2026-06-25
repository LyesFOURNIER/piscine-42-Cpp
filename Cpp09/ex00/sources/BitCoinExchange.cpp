/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:02:50 by lfournie          #+#    #+#             */
/*   Updated: 2026/06/25 14:59:43 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

bool	is_leap_year(int);
bool	data_check(std::string, std::string, std::string);
bool	key_format_check(std::string);
bool	value_format_check(std::string);

BitCoinExchange::BitCoinExchange(void)
{
	std::fstream	file("data.csv");
	std::string		buf, key, value;
	size_t			i;
	
	if (!file.is_open())
	{
		std::cout << "Error: database is missing" << std::endl;
		return;
	}
	getline(file, buf);
	while(1)
	{
		i = 0;
		if(!getline(file, buf))
			break;
		while (i < buf.size() && buf[i] != ',')
		{
			key.append(1, buf[i]);
			i++;
		}
		i++;
		while (i < buf.size())
		{
			value.append(1, buf[i]);
			i++;
		}
		_db.insert(std::pair<std::string, float>(key, static_cast<float>(atof(value.c_str()))));
		key.clear();
		value.clear();
	}
	// for(std::map<std::string, float >::const_iterator it = _db.begin(); it != _db.end(); ++it)
	// {
	//     std::cout << it->first << " " << it->second << "\n";
	// }
	std::cout << "BitCoinExchange default constructor called" << std::endl;
	return;
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange &copy)
{
	if (_db != copy._db)
	{
		_db.clear();
		for(std::map<std::string, float >::const_iterator it = copy._db.begin(); it != copy._db.end(); ++it)
		{
			_db.insert(std::pair<std::string, float>(it->first, it->second));
		}
	}
	std::cout << "BitCoinExchange copy constructor called" << std::endl;
	return;
}

BitCoinExchange &BitCoinExchange::operator=(const BitCoinExchange &copy)
{
	if (_db != copy._db)
	{
		_db.clear();
		for(std::map<std::string, float >::const_iterator it = copy._db.begin(); it != copy._db.end(); ++it)
		{
			_db.insert(std::pair<std::string, float>(it->first, it->second));
		}
	}
	std::cout << "BitCoinExchange assigment operator called" << std::endl;
	return *this;
}

bool	is_leap_year(int year)
{
	if (year % 4 != 0 || (year % 4 == 0 && (year % 100 == 0 && year % 400 != 0)))
		return false;
	return true;
}

bool	date_check(std::string year, std::string month, std::string day)
{
	int	i_year = atoi(year.c_str()), i_month = atoi(month.c_str()), i_day = atoi(day.c_str());
	
	if (!(i_year >= 0 && i_year <= 9999)
	|| !(i_month >= 1 && i_month <= 12))
	return false;
	
	int daysInMonth[] =
	{
    	0, 31, 28, 31, 30, 31, 30,
    	31, 31, 30, 31, 30, 31
	};
	
	if (is_leap_year(i_year))
		daysInMonth[2] = 29;
		
	if (i_day > daysInMonth[i_month])
		return false;
		
	return true;
}

bool	key_format_check(std::string key)
{
	int			i = 0, sep_check = 0;
	std::string	year, month, day;

	if (key.empty())
		return false;
	while (i != -1)
	{
		i = key.find('-', i + 1);
		if (!(i == 4 || i == 7 || i == -1))
			return false;
		if (i != -1)
			sep_check++;
	}
	if (sep_check != 2)
	{
		return false;
	}
	i = 0;
	while (static_cast<size_t>(i) < key.size() && key[i] != '-')
	{
		year.append(1, key[i]);
		i++;
	}
	i++;
	while (static_cast<size_t>(i) < key.size() && key[i] != '-')
	{
		month.append(1, key[i]);
		i++;
	}
	i++;
	while (static_cast<size_t>(i) < key.size() && key[i] != '-')
	{
		day.append(1, key[i]);
		i++;
	}
	if (!date_check(year, month, day))
		return false;
	return true;
}

bool	value_format_check(std::string value)
{
	if (value.empty())
		return false;
		
	float	f_value = static_cast<float>(atof(value.c_str()));
	
	if (f_value < 0 || f_value > 1000)
		return false; 
	
	return true;
}

void	BitCoinExchange::parseInput(const char *path)
{
	std::string		buf, key, value;
	bool			is_first_line = true;
	size_t			i = 0;
	std::fstream	file(path);
	std::map<std::string, float>::iterator it;

	if (!file.is_open())
	{
		std::cout << "Error: can't open file" << std::endl;
		return;
	}
	while (1)
	{
		
		if (!getline(file, buf))
			break;
		i = 0;
		key.clear();
		value.clear();
		if (buf.find('|') == std::string::npos || (buf.length() < 10 && !is_first_line))
		{
			std::cout << "Error: invalid format; valid format is: date | value" << std::endl;
			if (is_first_line)
				is_first_line = false;
			continue;
		}
		else
		{	
			if (is_first_line)
			{
				is_first_line = false;
				continue;
			}
			while (i < buf.size() && buf[i] != '|')
			{
				key.append(1, buf[i]);
				i++;
			}
			if (!key_format_check(key))
			{
				std::cout << "Error: invalid date => " << key << "; valid date format is Year-Month-Day"<< std::endl;
				continue;
			}
			i++;
			while (i < buf.size())
			{
				value.append(1, buf[i]);
				i++;
			}
			if (!value_format_check(value))
			{
				std::cout << "Error: invalid value; valid value format is a float between 0 and 1000" << std::endl;
				continue;
			}
			it = _db.lower_bound(key);

			if (it == _db.end() || it->first != key)
			{
			    if (it == _db.begin())
			    {
			        std::cout << "Error: no earlier date found" << std::endl;
			        continue;
			    }
			    --it;
			}
			std::cout	<< key << " => " << value << " = "
						<< it->second * static_cast<float>(atof(value.c_str())) << std::endl;
		}
	}
}

BitCoinExchange::~BitCoinExchange(void)
{
	std::cout << "BitCoinExchange destructor called" << std::endl;
	return;
}