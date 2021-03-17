NAME_1		=	checker
NAME_2		=	push_swap
SRCS		=	src/basics/err.c \
				src/basics/mem/mem_1.c \
				src/basics/mem/mem_2.c \
				src/basics/utils.c \
				src/stack/ops/ops_1.c \
				src/stack/ops/ops_2.c \
				src/stack/ops/ops_3.c \
				src/stack/ops/stack_moves.c \
				src/stack/low_level/stack.c \
				src/stack/low_level/stack_access.c \
				src/stack/op_stack.c \
				src/shared/global.c \
				src/shared/shared.c \
				src/sorts/back_track.c \
				src/sorts/bubble.c \
				src/sorts/insertion.c \
				src/debug.c #a supprimer
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
