NAME_1		=	checker
NAME_2		=	push_swap
SRCS		=	src/err.c \
				src/mem.c \
				src/ops.c \
				src/stack.c \
				src/stack_ops.c \
				src/utils.c \
				src/op_stack.c \
				src/back_track.c \
				src/bubble.c \
				src/insertion.c \
				src/global.c \
				src/shared.c \
				src/debug.c #a supprimer
MAIN_1		=	src/checker.c
MAIN_2		=	src/push_swap.c
OBJS_1		=	$(MAIN_1:.c=.o) $(SRCS:.c=.o)
OBJS_2		=	$(MAIN_2:.c=.o) $(SRCS:.c=.o)
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
