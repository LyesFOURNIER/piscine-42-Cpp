/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:54:06 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/05 08:22:59 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "../includes/lib.hpp"

class Brain
{
	public:

	Brain( void );
	Brain( const Brain *copy );
	Brain &operator=( const Brain &copy );
	~Brain( void );
	//GETTER
	std::string getIdea( int id ) const;
	//
	//SETTER
	void	setIdea( std::string idea, int id );
	//	
	private:

	std::string _ideas[100];
};

#endif
