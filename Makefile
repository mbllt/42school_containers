#------------- NAME -----------------
EXE_STD=		$(SRCS_FILES:%.cpp=bin/%_std)
EXE_MINE=		$(SRCS_FILES:%.cpp=bin/%_mine)
EXE_STD_SAN=	$(SRCS_FILES:%.cpp=bin/%_std_san)
EXE_MINE_SAN=	$(SRCS_FILES:%.cpp=bin/%_mine_san)
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
				stack/stack_all.cpp

SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
#------------------------------------

BIN_DIR=		bin
BIN_PATH=		vector stack map

#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.cpp=_std.o))\
				$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.cpp=_mine.o))

PATH_OBJS=		vector stack map
#------------------------------------


#------------- COMPILER -------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra -std=c++98 -Iincludes/
SAN=			-fsanitize=address -g3
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
				test_stack.hpp
#				test_map.hpp
INCLUDES=		$(addprefix $(INC_DIR)/,$(INC_FILES))
#------------------------------------


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------


#------------------------------------------------------------------------


all:							make_dir $(EXE_STD) $(EXE_MINE) $(EXE_STD_SAN) $(EXE_MINE_SAN)

#-------------- EXE -----------------
$(BIN_DIR)/%:				$(OBJS_DIR)/%.o
									$(CC) $(FLAGS) $(OBJS_DIR)/main.o $< -o $@

$(BIN_DIR)/%_san:			$(OBJS_DIR)/%.o
									$(CC) $(FLAGS) $(SAN) $(OBJS_DIR)/main.o $< -o $@
#------------------------------------


#------------- OBJS ----------------
$(OBJS_DIR)/%_std.o:		$(SRCS_DIR)/%.cpp $(INCLUDES) | $(OBJS_DIR)/main.o
									$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%_mine.o:		$(SRCS_DIR)/%.cpp $(INCLUDES) | $(OBJS_DIR)/main.o
									$(CC) $(FLAGS) -D MINE=1 -c $< -o $@

$(OBJS_DIR)/main.o:			$(SRCS_DIR)/main.cpp $(INCLUDES)
									$(CC) $(FLAGS) -c $< -o $@

make_dir:
									@echo "$(green)$(bold)Making$(end) $(green)directories$(end) : $(BIN_DIR) $(addprefix $(BIN_DIR)/,$(BIN_PATH)) $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))"
									mkdir -p $(BIN_DIR) $(addprefix $(BIN_DIR)/,$(BIN_PATH))
									mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))
#------------------------------------

test:
									@./tester.sh

clean:
									@echo "$(green)$(bold)Deleting$(end) object files$(end)"
									@$(RM) $(OBJS_DIR)

fclean:						clean
									@echo "$(green)$(bold)Deleting$(end) executables$(end)"
									@$(RM) $(BIN_DIR) res

re:							fclean all

.PHONY:						all clean fclean re
.SECONDARY: $(OBJS)

#------------- COLORS --------------
green	= \033[32m
end		= \033[0m
bold	= \033[1m
#------------------------------------
#------------------------------------
