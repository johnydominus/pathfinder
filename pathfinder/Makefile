NAME = pathfinder
INC= ./inc/pathfinder.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./pathfinder.h ./libmx.h

SRC = ./main.c \
	  ./mx_check_first_line.c \
	  ./mx_check_lines.c \
	  ./mx_create_edge.c \
	  ./mx_create_vertice.c \
	  ./mx_error.c \
	  ./mx_check_errors.c \
	  ./mx_create_pathfinder.c \
	  ./mx_parser.c

SRCS = ./src/main.c \
	   ./src/mx_check_first_line.c \
	   ./src/mx_check_lines.c \
	   ./src/mx_create_edge.c \
	   ./src/mx_create_vertice.c \
	   ./src/mx_error.c \
	   ./src/mx_check_errors.c \
	   ./src/mx_create_pathfinder.c \
	   ./src/mx_parser.c

OBJ = ./main.o \
	  ./mx_check_first_line.o \
	  ./mx_check_lines.o \
	  ./mx_create_edge.o \
	  ./mx_create_vertice.o \
	  ./mx_error.o \
	  ./mx_check_errors.o \
	  ./mx_create_pathfinder.o \
	  ./mx_parser.o

OBJO = ./obj/main.o \
	   ./obj/mx_check_first_line.o \
	   ./obj/mx_check_lines.o \
	   ./obj/mx_create_edge.o \
	   ./obj/mx_create_vertice.o \
	   ./obj/mx_error.o \
	   ./obj/mx_check_errors.o \
	   ./obj/mx_create_pathfinder.o \
	   ./obj/mx_parser.o

CFLGS = -g -std=c11 -Wall -Wpedantic -Werror -Wextra

all: install clean

install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(INCLIB) $(SRCS) .
	@clang $(CFLGS) -c $(SRC)
	@mkdir obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

clean:
	@cd libmx && make -f Makefile clean
	@rm -rf $(OBJ) $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf libmx.a
	@rm -rf ./libmx/objd

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(NAME)

reinstall: uninstall clean all
