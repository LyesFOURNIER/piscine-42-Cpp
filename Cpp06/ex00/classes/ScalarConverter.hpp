/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:35 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/16 09:14:56 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include "../includes/lib.hpp"

class	ScalarConverter
{
	public:

	//MEMBER FUNCTIONS	
		static void	convert ( std::string toConvert );
	//
	
	private:

		ScalarConverter( void );
		ScalarConverter( ScalarConverter &copy );
		ScalarConverter &operator=( const ScalarConverter &copy );
		~ScalarConverter();
};

#endif
