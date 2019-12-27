NAME = pathfinder
INC= ./inc/pathfinder.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./pathfinder.h ./libmx.h

SRC = ./main.c \
	  ./mx_check_first_line.c \
	  ./mx_create_edge.c \
	  ./mx_create_vertice.c \
	  ./mx_error.c

SRCS = ./src/main.c \
	   ./src/mx_check_first_line.c \
	   ./src/mx_create_edge.c \
	   ./src/mx_create_vertice.c \
	   ./src/mx_error.c

OBJ = ./main.o \
	  ./mx_check_first_line.o \
	  ./mx_create_edge.o \
	  ./mx_create_vertice.o \
	  ./mx_error.o

OBJO = ./obj/main.o \
	   ./obj/mx_check_first_line.o \
	   ./obj/mx_create_edge.o \
	   ./obj/mx_create_vertice.o \
	   ./obj/mx_error.o

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
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/obj

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(NAME)

reinstall: uninstall clean all
