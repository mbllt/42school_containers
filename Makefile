#------------- NAME -----------------
NAME=			containers
#------------------------------------


#------------- SRCS -----------------
SRCS=			main.cpp
#------------------------------------


#-------------- TESTS ---------------
TEST_DIR=		tests
TEST_FILES=		vectorTest.cpp
TEST_SRCS=		$(addprefix $(TEST_DIR)/,$(TEST_FILES))
#------------------------------------


#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
#------------------------------------


#------------- COMPILER -------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra -std=c++98
#------------------------------------


#------------- INCS -----------------
INCLUDES=		-Ivector/ -Iiterator/ -Itests/
#------------------------------------


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------


ifeq ($(SAN), 1)
FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3
endif


all:		$(NAME)

$(NAME):	$(OBJS)
					@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(NAME)$(END)"
					$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(TEST_VEC)

$(OBJS_DIR)/%.o:	%.cpp | $(OBJS_DIR)
					@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
					$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $< $(TEST_VEC)

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)

clean:
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)object files$(END)"
					@$(RM) $(OBJS)

fclean:		clean
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)executable, objs_dir$(END)"
					@$(RM) $(NAME)
					@$(RM) $(OBJS_DIR)

re:			fclean all

.PHONY:		all clean fclean re


#-----------------------COLORS-----------------------
GREEN	= \033[32m
END		= \033[0m
BOLD	= \033[1m
#----------------------------------------------------
