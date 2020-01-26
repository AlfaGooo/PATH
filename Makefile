NAME = pathfinder

SRC = src/main.c \
	src/mx_final_print.c \
	src/mx_making_matrix.c \
	src/mx_print_error.c \
	src/mx_reading_strarr.c \
	src/mx_recover_path.c \
	src/mx_create_zero.c \
	src/mx_print_distance.c \
	src/mx_floyd.c \
	src/mx_printerr.c \
	src/mx_line_check.c \
	src/mx_arr_size.c \
	src/mx_count_short_ways.c \
	src/mx_free_iarray.c \
	src/mx_struct_make.c

SRCOB = main.o \
	mx_final_print.o \
	mx_making_matrix.o \
	mx_print_error.o \
	mx_reading_strarr.o \
	mx_recover_path.o \
	mx_create_zero.o \
	mx_print_distance.o \
	mx_floyd.o \
	mx_printerr.o \
	mx_line_check.o \
	mx_arr_size.o \
	mx_count_short_ways.o \
	mx_free_iarray.o \
	mx_struct_make.o

INC = inc/pathfinder.h

OBJ = obj/main.o \
	obj/mx_final_print.o \
	obj/mx_making_matrix.o \
	obj/mx_print_error.o \
	obj/mx_reading_strarr.o \
	obj/mx_recover_path.o \
	obj/mx_create_zero.o \
	obj/mx_print_distance.o \
	obj/mx_floyd.o \
	obj/mx_printerr.o \
	obj/mx_line_check.o \
	obj/mx_arr_size.o \
	obj/mx_count_short_ways.o \
	obj/mx_free_iarray.o \
	obj/mx_struct_make.o

DIR = obj/
LIBMX = libmx
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C $(LIBMX)
	@mkdir obj
	@clang $(CFLAGS) -c $(SRC)
	@cp $(SRCOB) $(DIR)
	@clang $(CFLAGS) -o $(NAME) $(SRCOB) -L./libmx -lmx

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -C $(LIBMX)

clean:	
	@rm -rf $(SRCOB)
	@rm -rf $(DIR)

reinstall: uninstall install
	@rm -rf $(SRCOB)
	@rm -rf $(DIR)
