# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 08:09:19 by lfournie          #+#    #+#              #
#    Updated: 2025/10/23 11:30:00 by lfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cpp01_ex05_harl
CPP = c++
CPP_FLAGS = -Werror -Wextra -Wall -std=c++98 -pedantic -I $(INC_DIR) -I $(CLSS_DIR) -g3

all: $(NAME)
SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = includes
CLSS_DIR = classes

FILES = main.cpp Harl.cpp \

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