/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:25:00 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 13:17:50 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main(int ac, char **av)
{
	int					pos, prev_pos;
	std::fstream		fs1, fs2;
	std::string			line, new_line, s1, s2, new_file;
	std::stringstream	ss;
	
	if (ac != 4)
	{
		std::cout << "Uses: filename, string_to_replace, string_to_add" << std::endl;
		return (0);
	}
	new_file = av[1];
	new_file.append(".replace");
	if (!av[2])
		s1 = "";
	else
		s1 = av[2];
	s2 = av[3];
	fs1.open(av[1], std::fstream::in);
	if (ss.fail())
	{
		std::cout << "failed to open file: " << av[1] << std::endl;
		return (0);
	}
	fs2.open(new_file.c_str(), std::fstream::out);
	if (ss.fail())
	{
		std::cout << "failed to create file: " << new_file << std::endl;
		fs1.close();
		return (0);
	}
	while (1)
	{
		if (!getline(fs1, line))
			break ;
		pos = line.find(s1);
		if (pos == -1)
			fs2 << line;
		else
		{
			new_line.append(line, 0, pos);
			prev_pos = pos;
		}
		while (pos != -1)
		{
			new_line.append(s2);
			prev_pos = pos;
			pos = line.find(s1, pos + s1.length());
			new_line.append(line, prev_pos + s1.length(), pos - (prev_pos + s1.length()));
			if (pos == -1)
			{
				fs2 << new_line;
				new_line.clear();
			}
		}
		fs2 << std::endl;
	}
	fs1.close();
	fs2.close();
	return (0);
}


