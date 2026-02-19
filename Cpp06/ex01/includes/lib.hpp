/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:40:16 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/02 16:46:22 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_HPP
# define LIB_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <limits.h>
# include <cstdlib>
# include <stdint.h>
# include <math.h>

typedef struct s_data
{
	int			data1;
	char		data2;
	std::string data3;
} 	Data;

# include "../classes/Serializer.hpp"

#endif
