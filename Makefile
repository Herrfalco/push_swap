NAME	=	checker
SRCS	=	src/checker.c \
			src/err.c \
			src/mem.c \
			src/ops.c \
			src/stack.c \
			src/stack_ops.c \
			src/utils.c \
			src/global.c
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
#CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer
RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

%.o	:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
