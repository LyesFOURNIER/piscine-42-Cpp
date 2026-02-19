/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:11:30 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/23 11:34:19 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include "../includes/lib.hpp"

class Harl
{
	public:
	
	Harl( void );
	~Harl( void );

	void	complain(std::string level);
	
	private:
	
	std::string _level_tab[4];
	void 		(Harl::*_exec_tab[4])( void );
	
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif
