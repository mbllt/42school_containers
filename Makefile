#------------- NAME -----------------
NAME=			containers
MINE_NAME=		mine_containers
#------------------------------------


#------------- SRCS -----------------
SRCS_DIR=		tests
SRCS_FILES=		main.cpp\
				vector/vector_general.cpp
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
#------------------------------------


#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
PATH_OBJS=		tests tests/vector
#------------------------------------


#------------- COMPILER -------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra -std=c++98 -Iincludes/ # -fsanitize=address -g3
#------------------------------------


#------------- INCS -----------------
INC_DIR=		includes
INC_FILES=		vector.hpp\
				stack.hpp\
				map.hpp\
				iterator_traits.hpp\
				iterator.hpp\
				test_vector_std.hpp\
				test_vector_mine.hpp\
				reverse_iterator.hpp\
				utility.hpp\
				tests.hpp\
				test_stack.hpp\
				test_map.hpp
INCLUDES=		$(addprefix $(INC_DIR)/,$(INC_FILES))

# INC_STD=			includes/test_vector_std.hpp

# INC_MINE=			includes/test_vector_mine.hpp
#------------------------------------


#-------------- BIN -----------------
BIN_PATH=		bin
#------------------------------------


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------

all:		$(NAME) $(MINE_NAME)

$(NAME):	$(OBJS)
					@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(NAME)$(END)"
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(MINE_NAME):	$(OBJS)
					@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(MINE_NAME)$(END)"
					$(CC) $(FLAGS) $(OBJS) -o $(MINE_NAME)

$(OBJS_DIR)/%.o:	%.cpp $(INCLUDES) | $(OBJS_DIR)
					@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
					$(CC) $(FLAGS) -o $@ -c $<

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))

clean:
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)object files$(END)"
					@$(RM) $(OBJS)
					@$(RM) $(BIN_PATH)

fclean:		clean
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)executable, objs_dir$(END)"
					@$(RM) $(NAME)
					@$(RM) $(OBJS_DIR)

re:			fclean all

.PHONY:		all clean fclean re


#------------- COLORS --------------
GREEN	= \033[32m
END		= \033[0m
BOLD	= \033[1m
#------------------------------------
