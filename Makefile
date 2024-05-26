NAME		=	fractol
SRCS		=	main.c keymove.c mousemove.c mypixel.c color.c julia.c burning.c util.c main2.c
FLAG		=	-Wall -Wextra -Werror
OBJS 		=	$(SRCS:.c=.o)
CC			=	cc
LIBX_FLAGS	=	-lm -lmlx -framework OpenGL -framework AppKit
# LIBX_FLAGS	=	-lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) printf/libftprintf.a $(LIBX_FLAGS) -o $(NAME)

%.o: %.c printf/libftprintf.a
	$(CC) $(FLAG) -c $< -o $@

printf/libftprintf.a:
	make -C printf

bonus: $(NAME)
	touch bonus

clean:
	$(RM) $(OBJS)
	make -C printf fclean
	rm -f bonus;

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
