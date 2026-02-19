# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 13:32:34 by lfournie          #+#    #+#              #
#    Updated: 2025/10/21 13:41:17 by lfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cpp01_ex03_violence
CPP = c++
CPP_FLAGS = -Werror -Wextra -Wall -std=c++98 -pedantic -I $(INC_DIR) -I $(CLSS_DIR)

all: $(NAME)
SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = includes
CLSS_DIR = classes

FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp \

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
O_DIRS = $(sort $(dir $(OBJ)))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(O_DIRS) $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

$(O_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re