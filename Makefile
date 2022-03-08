NAME = so_long

CC = gcc

flags = -Werror -Wextra -Wall

header = so_long.h 

srcs = so_long.c \
	game/ft_check_map.c \
	game/ft_check_rectagle.c \
	game/ft_check_walls.c \
	game/ft_collect_map.c \
	lib/ft_get_next_line.c \
	lib/ft_strcnmp.c \
	lib/ft_strlcat.c \
	lib/ft_strlen.c \
	lib/ft_strchr.c \
	lib/ft_strjoin.c \
	lib/ft_strlcpy.c \
	lib/ft_substr.c \
	utils/ft_error.c \
	utils/ft_free.c \
	utils/ft_init.c

objs = $(srcs:%.c = %.o)

all : $(NAME)

$(NAME) : $(objs)
	@$(CC) $(flags) $(objs) -o $(NAME) 

# compile with lmlx
clean :
	@rm -rf $(objs)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONEY : all clean fclean re 
