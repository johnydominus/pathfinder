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
	  ./mx_create_core.c \
	  ./mx_parser.c \
	  ./mx_check_vertice_presence.c \
	  ./mx_check_edge_presence.c \
	  ./mx_compare_vert_names.c \
	  ./mx_compare_edge_names.c \
	  ./mx_make_adj_matrix.c

SRCS = ./src/main.c \
	   ./src/mx_check_first_line.c \
	   ./src/mx_check_lines.c \
	   ./src/mx_create_edge.c \
	   ./src/mx_create_vertice.c \
	   ./src/mx_error.c \
	   ./src/mx_check_errors.c \
	   ./src/mx_create_core.c \
	   ./src/mx_parser.c \
	   ./src/mx_check_vertice_presence.c \
	   ./src/mx_check_edge_presence.c \
	   ./src/mx_compare_vert_names.c \
	   ./src/mx_compare_edge_names.c \
	   ./src/mx_make_adj_matrix.c

OBJ = ./main.o \
	  ./mx_check_first_line.o \
	  ./mx_check_lines.o \
	  ./mx_create_edge.o \
	  ./mx_create_vertice.o \
	  ./mx_error.o \
	  ./mx_check_errors.o \
	  ./mx_create_core.o \
	  ./mx_parser.o \
	  ./mx_check_vertice_presence.o \
	  ./mx_check_edge_presence.o \
	  ./mx_compare_vert_names.o \
	  ./mx_compare_edge_names.o \
	  ./mx_make_adj_matrix.o

OBJO = ./obj/main.o \
	   ./obj/mx_check_first_line.o \
	   ./obj/mx_check_lines.o \
	   ./obj/mx_create_edge.o \
	   ./obj/mx_create_vertice.o \
	   ./obj/mx_error.o \
	   ./obj/mx_check_errors.o \
	   ./obj/mx_create_core.o \
	   ./obj/mx_parser.o \
	   ./obj/mx_check_vertice_presence.o \
	   ./obj/mx_check_edge_presence.o \
	   ./obj/mx_compare_vert_names.o \
	   ./obj/mx_compare_edge_names.o \
	   ./obj/mx_make_adj_matrix.o

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
