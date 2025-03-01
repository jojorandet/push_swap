#--------------------TARGETS------------------------#

NAME = push_swap

#------------------DIRECTORIES----------------------#

DIR_BIN		=	./bin
DIR_STACK	=	./stack
DIR_PROGRAM	=	./push_swap_program
DIR_LIBFT	=	./libft

#-----------------COMP FLAGS------------------------#

UNAME := $(shell uname)
CFLAGS = -Wall -Werror -Wextra -g
#ifeq ($(UNAME), Darwin)
#CFLAGS += -fsanitize=address
#endif

#---------------------SOURCE------------------------#
#I looks for the header files, and then L looks for the .a and l links them together 

STACK_SRCS		= 	atoll_long_push_swap.c \
					int_tester.c \
					parsing.c \
					stack_free.c

PROGRAM_SRCS	=	push_swap.c \
					index_convert.c \
					push.c \
					swap.c \
					rotate.c \
					sort_a.c \
					sort_b.c \
					rev_rotate.c \
					dispatch_sorting.c \
					sort_small_n.c \
					stack_manipulation_operations.c \
					push_swap_exit.c 

STACK_OBJS		=	$(addprefix $(DIR_BIN)/stack/, $(STACK_SRCS:.c=.o))
PROGRAM_OBJS	=	$(addprefix $(DIR_BIN)/program/, $(PROGRAM_SRCS:.c=.o))
ALL_SRCS		=	$(addprefix stack/src/, $(STACK_SRCS))
ALL_SRCS		+=	$(addprefix push_swap_program/src/, $(PROGRAM_SRCS))
ALL_OBJ			=	$(STACK_OBJS) $(PROGRAM_OBJS)

#----------Libraries and linking --------------------#

INCLUDE_FLAGS	=	-I$(DIR_LIBFT) -I$(DIR_STACK)/include -I$(DIR_PROGRAM)/include
LIBRARY_PATH	=	-L$(DIR_LIBFT)
LIBRARIES		=	-lft

#-----------------

all: $(NAME)

$(NAME): $(ALL_OBJ) | $(DIR_BIN)
	@make -s -C $(DIR_LIBFT)
	@make -s bonus -C $(DIR_LIBFT)
	@$(CC) $(ALL_OBJ) $(CFLAGS) $(LIBRARY_PATH) $(LIBRARIES) -o $@
#$@ expands to the target which is name. the compilation a.out goes into the push_swap

#rule for stack objects
$(DIR_BIN)/stack/%.o: $(DIR_STACK)/src/%.c | $(DIR_BIN)/stack
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(DIR_BIN)/program/%.o: $(DIR_PROGRAM)/src/%.c | $(DIR_BIN)/program
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(DIR_BIN):
	@mkdir -p $@

$(DIR_BIN)/stack:
	@mkdir -p $@

$(DIR_BIN)/program:
	@mkdir -p $@

wasm: 
	docker run --rm -v $(shell pwd):/src emscripten/emsdk emcc $(ALL_SRCS) ./libft/*.c -o $(NAME).wasm
#-----------------------clean functions------------------------#

clean:
	@make -s clean -C $(DIR_LIBFT)
	@rm -rf $(DIR_BIN)

fclean:	clean
	@make -s fclean -C $(DIR_LIBFT)
	@rm -rf $(NAME)
#takes away the push_swap executable

re: fclean all
#cleans everything and calls the all command which makes everything

.PHONY: re fclean clean all