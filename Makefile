NAME = pathfinder

INC = ./inc/header.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./header.h ./libmx.h

SRC = ./mx_find_in_depth.c \
	./mx_crarr_names.c \
	./mx_cr_nodes.c \
	./mx_set_bridge.c \
	./mx_check_file.c \
	./mx_pr_errors.c \
	./mx_pr_path.c \
	./mx_pathmain.c \
	./mx_way_funcs.c \

SRCS = ./src/mx_find_in_depth.c \
	./src/mx_crarr_names.c \
	./src/mx_cr_nodes.c \
	./src/mx_set_bridge.c \
	./src/mx_check_file.c \
	./src/mx_pr_errors.c \
	./src/mx_pr_path.c \
	./src/mx_pathmain.c \
	./src/mx_way_funcs.c \

OBJ = ./mx_find_in_depth.o \
	./mx_crarr_names.o \
	./mx_cr_nodes.o \
	./mx_set_bridge.o \
	./mx_check_file.o \
	./mx_pr_errors.o \
	./mx_pr_path.o \
	./mx_pathmain.o \
	./mx_way_funcs.o \

OBJO = obj/mx_find_in_depth.o \
	obj/mx_crarr_names.o \
	obj/mx_cr_nodes.o \
	obj/mx_set_bridge.o \
	obj/mx_check_file.o \
	obj/mx_pr_errors.o \
	obj/mx_pr_path.o \
	obj/mx_pathmain.o \
	obj/mx_way_funcs.o \

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: clean
	@make -C libmx
	@cp $(INC) $(SRCS) .
	@cp $(INCLIB) . 
	@clang $(CFLAG) -c  $(SRC)
	@mkdir obj
	@cp libmx/libmx.a .
	@mv $(OBJ) ./obj
	@clang $(CFLAG) $(OBJO) libmx/libmx.a -o $(NAME)
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf $(OBJ)
	@rm -rf libmx.a
	@make clean
install:
	@make -C libmx
	@cp $(INC) $(SRCS) .
	@cp $(INCLIB) . 
	@clang $(CFLAG) -c  $(SRC)
	@mkdir  obj
	@cp libmx/libmx.a .
	@mv $(OBJ) ./obj
	@clang $(CFLAG) $(OBJO) libmx/libmx.a -o $(NAME)
uninstall:
	@make uninstall -C libmx
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/obj
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@rm -rf libmx.a
clean:
	@make clean -C libmx
	@rm -rf ./obj
	@rm -rf $(OBJ)
reinstall: uninstall install
