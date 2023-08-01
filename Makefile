NAME = exec_name
CC = g++
SRC_DIR = ./src
INC_DIR = ./include
BIN_DIR = ./bin
OBJ_DIR = ./obj
CFLAGS = -Wall -g -pg
EXE = $(BIN_DIR)/$(NAME)

OBJS =\
		$(OBJ_DIR)/BinaryTree.o\
		$(OBJ_DIR)/Expression.o\
		$(OBJ_DIR)/Functions.o\
		$(OBJ_DIR)/Node_Stack.o\
		$(OBJ_DIR)/Node.o\
		$(OBJ_DIR)/Stack.o\
		$(OBJ_DIR)/Verifier.o\
		$(OBJ_DIR)/main.o

all: $(EXE)

run: all
		$(EXE)

$(EXE): $(OBJS)
		$(CC) -pg $(OBJS) -o $(EXE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/**/%.cpp $(INC_DIR)/%.hpp
		$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
		$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

clean:
		rm -f $(OBJS)
		rm -f $(EXE)

valgrind: $(EXE)
		valgrind --leak-check=full bin/$(NAME)