NAME_1		=	checker
NAME_2		=	push_swap
SRCS		=	src/shared/err.c \
				src/shared/global.c \
				src/shared/mem/mem_1.c \
				src/shared/mem/mem_2.c \
				src/shared/shared.c \
				src/shared/utils_1.c \
				src/shared/utils_2.c \
				src/sorts/optimised.c \
				src/stack/stack.c \
				src/stack/moves/ops_1.c \
				src/stack/moves/ops_2.c \
				src/stack/moves/ops_3.c \
				src/stack/moves/stack_moves.c \
				src/stack/specialized/op_stack.c \
				src/stack/specialized/stacks.c
MAIN_1		=	src/mains/checker.c
MAIN_2		=	src/mains/push_swap.c
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
