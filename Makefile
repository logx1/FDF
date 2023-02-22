# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 17:14:06 by abdel-ou          #+#    #+#              #
#    Updated: 2023/02/18 20:25:00 by abdel-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=fdf
NAME_B=fdf_bonus
FRAEMWORKS=-L /usr/lib -lmlx -framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall

SRC=src/read_map.c src/set_param.c src/main.c src/isometric.c src/draw.c src/click_key.c src/responsiv.c get_next_line_utils.c get_next_line.c ft_split.c ft_atoi.c atoi_base.c ft_strnstr.c color.c

SRCBONUS=src/read_map.c src/set_param.c src/main.c src/isometric.c src/draw.c src/click_key_bonus.c src/responsiv.c get_next_line_utils.c get_next_line.c ft_split.c ft_atoi.c atoi_base.c ft_strnstr.c color.c


INCLUDES=-I /usr/include

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME_B)
$(NAME_B):$(OBJBONUS)
	$(CC) $(OBJBONUS) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

all	:$(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@ 

fclean:
	rm -rf $(NAME) $(NAME_B) $(OBJ) $(OBJBONUS)

clean:
	rm -rf $(OBJ) $(OBJBONUS)

re:fclean $(NAME)