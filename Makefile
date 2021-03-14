NAME_1		=	checker
NAME_2		=	push_swap
SRCS		=	src/err.c \
				src/mem.c \
				src/ops.c \
				src/stack.c \
				src/stack_ops.c \
				src/utils.c \
				src/op_stack.c \
				src/global.c
SRC_1		=	src/checker.c
SRC_2		=	src/back_track.c
OBJS_1		=	src/checker.o $(SRCS:.c=.o)
OBJS_2		=	src/back_track.o $(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer
RM			=	rm -rf

all			:	$(NAME_1) $(NAME_2)

$(NAME_1)	:	$(OBJS_1)
				$(CC) $(CFLAGS) $^ -o $@

$(NAME_2)	:	$(OBJS_2)
				$(CC) $(CFLAGS) $^ -o $@

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS_1) $(OBJS_2)

fclean		:	clean
				$(RM) $(NAME_1) $(NAME_2)

re			:	fclean all
