CC = gcc
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin


SRCS = $(SRC_DIR)/object.c main.c
OBJS = $(SRCS:.c=.o)


all : $(BIN_DIR)/main


$(BIN_DIR)/main : $(SRC_DIR)/object.c main.c
	@mkdir -p $(BIN_DIR)
	$(CC)  $^ -o $@

run : all
	./$(BIN_DIR)/main

clean : 
	@rm -rf $(BIN_DIR)

