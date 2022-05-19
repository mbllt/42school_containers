#------------- NAME -----------------
EXE_STD=		$(SRCS_FILES:.cpp=_std)
EXE_MINE=		$(SRCS_FILES:.cpp=_mine)
EXE_STD_SAN=	$(SRCS_FILES:.cpp=_std_san)
EXE_MINE_SAN=	$(SRCS_FILES:.cpp=_mine_san)
#------------------------------------


#------------- SRCS -----------------
SRCS_DIR=		srcs
SRCS_FILES=		vector/vec_general.cpp\
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

BIN_DIR=		bin
BIN_PATH=		vector stack map

#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.cpp=_std.o))\
				$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.cpp=_mine.o))\
				$(addprefix $(OBJS_DIR)/,main.o)
PATH_OBJS=		vector stack map
#------------------------------------


#------------- COMPILER -------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra -std=c++98 -Iincludes/
SAN=			-fsanitize=address -g3
LEAK=			leaks -atExit --
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


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------


#------------------------------------------------------------------------


all:						$(BIN_DIR) $(EXE_STD) $(EXE_MINE) $(EXE_STD_SAN) $(EXE_MINE_SAN)

#-------------- EXE -----------------
$(EXE_STD):					$(OBJS)
#									@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$<$(END)"
									$(CC) $(FLAGS) .objs/main.o $< -o $(BIN_DIR)/$@

$(EXE_MINE):				$(OBJS)
#									@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(EXE_MINE)$(END)"
									$(CC) $(FLAGS) .objs/main.o $< -o $(BIN_DIR)/$@

$(EXE_STD_SAN):				$(OBJS)
#									@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$<$(END)"
									$(CC) $(FLAGS) $(SAN) .objs/main.o $< -o $(BIN_DIR)/$@

$(EXE_MINE_SAN):			$(OBJS)
#									@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(EXE_MINE)$(END)"
									$(CC) $(FLAGS) $(SAN) .objs/main.o $< -o $(BIN_DIR)/$@
#------------------------------------


#------------- OBJS ----------------
$(OBJS_DIR)/%_std.o:		$(SRCS_DIR)/%.cpp $(INCLUDES) | $(OBJS_DIR)
#									@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
									$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%_mine.o:		$(SRCS_DIR)/%.cpp $(INCLUDES) | $(OBJS_DIR)
#									@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
									$(CC) $(FLAGS) -D MINE=1 -c $< -o $@

$(OBJS_DIR)/main.o:			$(SRCS_DIR)/main.cpp $(INCLUDES)
#									@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
									$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
									mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))
#------------------------------------

$(BIN_DIR):
									mkdir -p $(BIN_DIR) $(addprefix $(BIN_DIR)/,$(BIN_PATH))

test:
									@./tester.sh

clean:
									@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)object files$(END)"
									@$(RM) $(OBJS_DIR)/

fclean:						clean
									@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)executables, objs_dir, bin_dir$(END)"
									@$(RM) $(OBJS_DIR) $(BIN_DIR) res

re:							fclean all

.PHONY:						all clean fclean re


#------------- COLORS --------------
GREEN	= \033[32m
END		= \033[0m
BOLD	= \033[1m
#------------------------------------
