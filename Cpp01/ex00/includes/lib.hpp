/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:02:58 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 10:04:16 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_HPP
# define LIB_HPP

# include <iostream>
# include "../classes/Zombie.hpp"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif
