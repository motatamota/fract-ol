NAME		=	fract-ol
SRCS		=	main.c keymove.c mousemove.c mypixel.c color.c
FLAG		=	-Wall -Wextra -Werror
OBJS 		=	$(SRCS:.c=.o)
CC			=	cc
LIBX_FLAGS	=	-lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
