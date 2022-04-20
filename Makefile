NAME = so_long

FOLDER = ./src/

CC = gcc

flags = -Werror -Wextra -Wall

header = so_long.h 

SRCS_C = so_long.c \

SRCS = $(addprefix $(FOLDER),$(SRCS_C))


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
