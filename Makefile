#------------- NAME -----------------
VEC_EXE_STD=		$(SRCS_VEC:%.cpp=bin/%_std)
VEC_EXE_MINE=		$(SRCS_VEC:%.cpp=bin/%_mine)
VEC_EXE_STD_SAN=	$(SRCS_VEC:%.cpp=bin/%_std_san)
VEC_EXE_MINE_SAN=	$(SRCS_VEC:%.cpp=bin/%_mine_san)

STACK_EXE_STD=		$(SRCS_STACK:%.cpp=bin/%_std)
STACK_EXE_MINE=		$(SRCS_STACK:%.cpp=bin/%_mine)
STACK_EXE_STD_SAN=	$(SRCS_STACK:%.cpp=bin/%_std_san)
STACK_EXE_MINE_SAN=	$(SRCS_STACK:%.cpp=bin/%_mine_san)

MAP_EXE_STD=		$(SRCS_MAP:%.cpp=bin/%_std)
MAP_EXE_MINE=		$(SRCS_MAP:%.cpp=bin/%_mine)
MAP_EXE_STD_SAN=	$(SRCS_MAP:%.cpp=bin/%_std_san)
MAP_EXE_MINE_SAN=	$(SRCS_MAP:%.cpp=bin/%_mine_san)
#------------------------------------


#------------- SRCS -----------------
SRCS_DIR=		srcs
SRCS_PATH=		vector stack map

SRCS_VEC=		vector/vec_general.cpp\
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
				vector/vec_insert.cpp

SRCS_STACK=		stack/stack_all.cpp

SRCS_MAP=		map/map_general.cpp\
				map/map_accessors.cpp\
				map/map_it.cpp\
				map/map_capacity.cpp\
				map/map_modifiers.cpp\
				map/map_lookup.cpp\
				map/map_rev_it.cpp\
				map/map_non_members.cpp
#------------------------------------

#-------------- SPEED ---------------
SUBDIRS_SPEED = $(shell find src_speed -mindepth 1 -type d | grep -v ".dSYM" | cut -d/ -f2-)
TEST_SPEED_SRCS = $(shell find src_speed -mindepth 2 -type f | grep -v ".dSYM")
SUBDIRS_TEST_SPEED = $(addprefix test_speed/, $(SUBDIRS_SPEED))
TESTS_SPEED =	$(TEST_SPEED_SRCS:src_speed/%.cpp=test_speed/%)
#------------------------------------

BIN_DIR=		bin
BIN_PATH=		vector stack map

#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS_VEC:.cpp=_std.o))\
				$(addprefix $(OBJS_DIR)/,$(SRCS_VEC:.cpp=_mine.o))\
				$(addprefix $(OBJS_DIR)/,$(SRCS_STACK:.cpp=_std.o))\
				$(addprefix $(OBJS_DIR)/,$(SRCS_STACK:.cpp=_mine.o))\
				$(addprefix $(OBJS_DIR)/,$(SRCS_VEC:.cpp=_std.o))\
				$(addprefix $(OBJS_DIR)/,$(SRCS_VEC:.cpp=_mine.o))

PATH_OBJS=		vector stack map
#------------------------------------


#------------- COMPILER -------------
FLAGS=			-Wall -Werror -Wextra -std=c++98 -Iincludes/ -g
CC=				clang++
SAN=			-fsanitize=address -g3
#------------------------------------


#------------- INCS -----------------
INC_DIR=		includes
INC_FILES=		vector.hpp\
				stack.hpp\
				map.hpp\
				iterator_traits.hpp\
				iterator.hpp\
				iterator_map.hpp\
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


#--------------TESTS-----------------
all:							make_dir vector stack map
									./tester.sh

vector:							make_dir $(VEC_EXE_STD) $(VEC_EXE_MINE) $(VEC_EXE_STD_SAN) $(VEC_EXE_MINE_SAN)

stack:							make_dir $(STACK_EXE_STD) $(STACK_EXE_MINE) $(STACK_EXE_STD_SAN) $(STACK_EXE_MINE_SAN)

map:							make_dir $(MAP_EXE_STD) $(MAP_EXE_MINE) $(MAP_EXE_STD_SAN) $(MAP_EXE_MINE_SAN)

re_vector:						fclean vector

re_stack:						fclean stack

re_map:							fclean map

speed:							$(TESTS_SPEED)

speedv:							$(filter test_speed/vect/%, $(TESTS_SPEED))

speedm:							$(filter test_speed/map/%, $(TESTS_SPEED))
#------------------------------------

#-------------- EXE -----------------
$(BIN_DIR)/%_std:				$(OBJS_DIR)/%_std.o
									$(CC) $(FLAGS) $(OBJS_DIR)/main.o $< -o $@

$(BIN_DIR)/%_mine:				$(OBJS_DIR)/%_mine.o
									$(CC) $(FLAGS) $(OBJS_DIR)/main.o $< -o $@

$(BIN_DIR)/%_std_san:			$(OBJS_DIR)/%_std.o
									$(CC) $(FLAGS) $(SAN) $(OBJS_DIR)/main.o $< -o $@

$(BIN_DIR)/%_mine_san:			$(OBJS_DIR)/%_mine.o
									$(CC) $(FLAGS) $(SAN) $(OBJS_DIR)/main.o $< -o $@

test_speed/%:					src_speed/main.cpp src_speed/%.cpp | $(SUBDIRS_TEST_SPEED)
									$(CC) $^ -o $@_mine $(FLAGS) -D MINE
									@echo -en "$(erase)"
									$(CC) $^ -o $@_std $(FLAGS)
									@bash test_speed.sh $@

$(SUBDIRS_TEST_SPEED):
	mkdir -p test_speed
	mkdir -p $(SUBDIRS_TEST_SPEED)
#------------------------------------


#------------- OBJS ----------------
$(OBJS_DIR)/%_std.o:		$(SRCS_DIR)/%.cpp $(INCLUDES) | $(OBJS_DIR)/main.o
									$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%_mine.o:		$(SRCS_DIR)/%.cpp $(INCLUDES) | $(OBJS_DIR)/main.o
									$(CC) $(FLAGS) -D MINE=1 -c $< -o $@

$(OBJS_DIR)/main.o:			$(SRCS_DIR)/main.cpp $(INCLUDES)
									$(CC) $(FLAGS) -c $< -o $@
#------------------------------------

make_dir:
									@echo "$(green)$(bold)Making$(end) $(green)directories$(end) : $(BIN_DIR) $(addprefix $(BIN_DIR)/,$(BIN_PATH)) $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))"
									mkdir -p $(BIN_DIR) $(addprefix $(BIN_DIR)/,$(BIN_PATH))
									mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))
									rm -rf res

test:
									@./tester.sh

clean:
									@echo "$(green)$(bold)Deleting$(end) object files$(end)"
									@$(RM) $(OBJS_DIR)

fclean:						clean
									@echo "$(green)$(bold)Deleting$(end) executables and directories res bin .objs$(end)"
									@$(RM) $(BIN_DIR) res test_speed

re:							fclean all

.PHONY:						all clean fclean re
.SECONDARY: $(OBJS)


#------------- COLORS --------------
green	= \033[32m
end		= \033[0m
bold	= \033[1m
#------------------------------------
