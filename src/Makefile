# Makefile to build tree driver program
# --- macros
CC=g++
CFLAGS=  -Wall -g
TEST_OBJ= TestBinarySearchTree.o
#
#
# # --- targets

all:	test 
test:   $(TEST_OBJ) 
	$(CC)  -o test  $(TEST_OBJ) 

TestBinarySearchTree.o: TestBinarySearchTree.cpp
	$(CC) $(CFLAGS) -c TestBinarySearchTree.cpp

# --- remove binary and executable files
clean:
	rm -f test $(TEST_OBJ) 
