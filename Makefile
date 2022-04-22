NAME = so_long

CC = gcc

flags = -Werror -Wextra -Wall

HEADERS = ./src/so_long.h ./src/ft_printf.h ./src/libft.h ./src/get_next_line.h

#so_long
SRC_FOLDER = ./src/
SRCS_C = so_long.c draw.c ft_map_check.c ft_map.c move.c
SRCS = $(addprefix $(SRC_FOLDER),$(SRCS_C))
OBJS = $(SRCS:%.c = %.o)

#printf
PRINTF_FOLDER = ./src/ft_printf/
PRINTF_C = ft_print_pointer.c ft_printf.c ft_putchar.c  ft_putnbr_hex.c  ft_putnbr_unsigned10.c \
		ft_print_pourcentage.c ft_putnbr_base10.c ft_putnbr_hex_upper.c  ft_putstr.c
PRINTF_SRCS = $(addprefix $(PRINTF_FOLDER),$(PRINTF_C))

#libft
LIBFT_FOLDER = ./src/libft/
LIBFT_C = ft_atoi.c ft_isalpha.c ft_itoa.c ft_lstdelone.c ft_lstnew.c ft_memcpy.c ft_putendl_fd.c  ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c \
	ft_bzero.c ft_isascii.c ft_lstadd_back.c ft_lstiter.c ft_lstsize.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
	ft_calloc.c ft_isdigit.c ft_lstadd_front.c ft_lstlast.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c \
	ft_isalnum.c ft_isprint.c ft_lstclear.c ft_lstmap.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c
LIBFT_SRCS = $(addprefix $(LIBFT_FOLDER),$(LIBFT_C))

#get_next_line
GET_NEXT_LINE_FOLDER = ./src/get_next_line/
GET_NEXT_LINE_C = get_next_line.c get_next_line_utils.c
GET_NEXT_LINE_SRCS = $(addprefix $(GET_NEXT_LINE_FOLDER),$(GET_NEXT_LINE_C))

O_SRCS = $(GET_NEXT_LINE_SRCS) $(PRINTF_SRCS) $(LIBFT_SRCS)
O_OBJS = $(O_SRCS:.c=.o)

LIBS = ./src/printf.a ./src/libft.a ./src/get_next_line.a

all : $(NAME)

$(NAME) : $(objs)
	@$(MAKE) -C $(PRINTF_FOLDER)
	@echo "printf.a created!"
	@$(MAKE) -C $(LIBFT_FOLDER)
	@echo "libft.a created!"
	@$(MAKE) -C $(GET_NEXT_LINE_FOLDER)
	@echo "get_next_line.a created!"
	$(CC) $(OBJS) $(LIBS) -lmlx - framework OpenGL -framework AppKit -o $(NAME) 

%.o : %.c $(HEADERS)
	$(CC) $(flags) -Imlx -c $< -o $@
clean :
	@rm -rf $(LIBS) $(OBJS) $(O_OBJS)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

