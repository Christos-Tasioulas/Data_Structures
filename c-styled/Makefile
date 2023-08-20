# sample Makefile that you can quickly adapt to your needs
# set compiler options here
CPPFLAGS=-g -Wall -g3 -std=c++11

# set the name of the executable file to compile here
program=test

# list object files needed to compile the program
objects=main.o List.o Queue.o BinaryTree.o CompleteBinaryTree.o Heap.o MinHeap.o BinarySearchTree.o AVLTree.o HashTable.o
# arguments to run the program
args =
# this makes the program. It's the first rule so it will be executed if you give just 'make'
$(program) : $(objects)
	g++ $(CPPFLAGS) $(objects) -o $(program)

# list .h dependencies for each .o (dependency on .c is automatically set by make!)
main.o : MinHeap.h Heap.h AVLTree.h HashTable.h
List.o : List.h 
Queue.o : Queue.h
BinaryTree.o : BinaryTree.h
CompleteBinaryTree.o : CompleteBinaryTree.h
Heap.o : Heap.h
MinHeap.o : MinHeap.h
BinarySearchTree.o : BinarySearchTree.h
AVLTree.o : AVLTree.h
HashTable.o : HashTable.h

# this allows to quickly remove all generated files with 'make clean'
clean:
	rm $(program) $(objects)

# run the program with 'make run'. Sometimes useful to avoid rewriting long commands.
run: $(program)
	./$(program) $(args)	

valgrind: $(program)
	valgrind --track-origins=yes ./$(program) $(args)