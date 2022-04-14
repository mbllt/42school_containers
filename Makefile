#------------- NAME -----------------
NAME=			containers
#------------------------------------


#------------- SRCS -----------------
SRCS_DIR=		tests
SRCS_FILES=		main.cpp\
				vectorTest.cpp
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
#------------------------------------


#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
PATH_OBJS=		tests
#------------------------------------


#------------- COMPILER -------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra -std=c++98 -Ivector/ -Iiterator/ -Itests/
#------------------------------------


#------------- INCS -----------------
INCLUDES=		vector/vector.hpp\
				iterator/iterator.hpp\
				iterator/reverse_iterator.hpp\
				tests/tests.hpp
#------------------------------------


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------

#probleme avec les includes : quand je les mets en dependance ca marche plus


ifeq ($(SAN), 1)
FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3
endif


all:		$(NAME)

$(NAME):	$(OBJS)
					@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(NAME)$(END)"
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	%.cpp $(INCLUDES) | $(OBJS_DIR)
					@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
					$(CC) $(FLAGS) -o $@ -c $<

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))

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
