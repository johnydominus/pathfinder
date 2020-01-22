NAME = pathfinder
INC = ./inc/pathfinder.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./pathfinder.h ./libmx.h

SRC = ./main.c \
	  ./mx_check_first_line.c \
	  ./mx_check_lines.c \
	  ./mx_error.c \
	  ./mx_check_errors.c \
	  ./mx_create_core.c \
	  ./mx_nparser.c \
	  ./mx_pathfinder.c \
	  ./mx_free_everything.c \
	  ./mx_print.c

SRCS = ./src/main.c \
	   ./src/mx_check_first_line.c \
	   ./src/mx_check_lines.c \
	   ./src/mx_error.c \
	   ./src/mx_check_errors.c \
	   ./src/mx_create_core.c \
	   ./src/mx_nparser.c \
	   ./src/mx_pathfinder.c \
	   ./src/mx_free_everything.c \
	   ./src/mx_print.c

OBJ = ./main.o \
	  ./mx_check_first_line.o \
	  ./mx_check_lines.o \
	  ./mx_error.o \
	  ./mx_check_errors.o \
	  ./mx_create_core.o \
	  ./mx_nparser.o \
	  ./mx_pathfinder.o \
	  ./mx_free_everything.o \
	  ./mx_print.o

OBJO = ./obj/main.o \
	   ./obj/mx_check_first_line.o \
	   ./obj/mx_check_lines.o \
	   ./obj/mx_error.o \
	   ./obj/mx_check_errors.o \
	   ./obj/mx_create_core.o \
	   ./obj/mx_nparser.o \
	   ./obj/mx_pathfinder.o \
	   ./obj/mx_free_everything.o \
	   ./obj/mx_print.o

CFLGS = -g -std=c11 -Wall -Wpedantic -Werror -Wextra

all: install clean

install:
	@make -C libmx install
	@cp $(INC) $(INCLIB) $(SRCS) .
	@clang $(CFLGS) -c $(SRC)
	@mkdir obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

clean:
	@make -C libmx/ -f Makefile clean
	@rm -rf $(OBJ) $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf libmx.a
	@rm -rf ./libmx/obj

uninstall: clean
	@make -C libmx/ -f Makefile uninstall
	@rm -rf $(NAME)

reinstall: uninstall all
