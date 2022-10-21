CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack-test heap-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) -o $@ llrec-test.o llrec.o

llrec-test.o: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

stack-test: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) stack_test.cpp -o stack-test
	./stack-test

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp


clean:
	rm -f *.o rh llrec-test *~
	rm -f stack-test

.PHONY: clean 