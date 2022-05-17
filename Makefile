#------------- NAME -----------------
NAME=			containers
#------------------------------------


#------------- SRCS -----------------
SRCS_DIR=		srcs
SRCS_FILES=		main.cpp\
				vector/vec_general.cpp\
				vector/vec_ope.cpp\
				vector/vec_it.cpp\
				vector/vec_rev_it.cpp\
				vector/vec_capacity.cpp\
				vector/vec_accessors.cpp\
				vector/vec_resize.cpp\
				vector/vec_push_back.cpp\
				vector/vec_pop_back.cpp\
				vector/vec_swap.cpp\
				vector/vec_clear.cpp\
				vector/vec_erase.cpp\
				vector/vec_insert.cpp\
				stack/stack_all.cpp\
				map/map_general.cpp
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
#------------------------------------


#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
PATH_OBJS=		$(SRCS_DIR) $(SRCS_DIR)/vector $(SRCS_DIR)/stack $(SRCS_DIR)/map
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
				reverse_iterator.hpp\
				utility.hpp\
				tests.hpp\
				test_vector.hpp\
				test_stack.hpp\
				test_map.hpp
INCLUDES=		$(addprefix $(INC_DIR)/,$(INC_FILES))
#------------------------------------


#-------------- BIN -----------------
BIN_PATH=		bin
#------------------------------------


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------

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
