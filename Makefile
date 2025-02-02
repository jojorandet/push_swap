#--------------------TARGETS------------------------#

NAME = push_swap

#------------------DIRECTORIES----------------------#

DIR_BIN		=	./bin
DIR_INCLUDE	=	./include
DIR_SRC		=	./src
FT_LIBFT	= 	./include/libft

#-----------------COMP FLAGS------------------------#

UNAME := $(shell uname)
CFLAGS	=	-Wall -Werror -Wextra -g
ifeq ($(UNAME), Darwin)
	CFLAGS += -fsanitize=address
endif

#---------------------SOURCE------------------------#
#I looks for the header files, and then L looks for the .a and l links them together 
SOURCES			=	main.c \
					int_tester.c \
					exit_utils.c \
					parsing.c \
					push_swap_moves.c \
					rot_and_rev_moves.c \
					combined_moves.c \
					index_convert.c \
					basic_sorting.c

				
SOURCE_NAME		=	$(basename $(SOURCES))
OBJECTS			=	$(addsuffix .o, $(addprefix $(DIR_BIN)/, $(SOURCE_NAME)))

#----------Libraries and linking --------------------#

INCLUDE_FLAGS	=	-I$(FT_LIBFT) -I$(DIR_INCLUDE)
LIBRARY_PATH	=	-L$(FT_LIBFT) -L$(DIR_INCLUDE)
LIBRARIES		=	-lft

#-----------------

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(FT_LIBFT)
	@make bonus -C $(FT_LIBFT)
	@$(CC) $(OBJECTS) $(CFLAGS) $(LIBRARY_PATH) $(LIBRARIES) -o $@
	@echo "ready to execute $(NAME)\n"
#$@ expands to the target which is name. the compilation a.out goes into the push_swap

$(DIR_BIN)/%.o: $(DIR_SRC)/%.c | $(DIR_BIN)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@
#$< expands to src/main.c for example and then -o $@ is the target, meaning the ./bin/main.o

$(DIR_BIN):
	@mkdir -p $@

#-----------------------clean functions------------------------#

clean:
	@make clean -C $(FT_LIBFT)
	@rm -rf $(DIR_BIN)

fclean:	clean
	@make fclean -C $(FT_LIBFT)
	@rm -rf $(NAME)
#takes away the push_swap executable

re: fclean all
#cleans everything and calls the all command which makes everything

.PHONY: re fclean clean all