#PROJETO LP

PROG = start_simulator
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = main.o dependencia.o imprime.o split.o
HEADER1 = ./include/instrucao.h
HEADER2 = ./include/dependencia.h
HEADER3 = ./include/imprime.h
HEADER4 = ./include/split.h
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o $(BIN_DIR)

main.o: $(HEADER3)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)main.cpp

dependencia.o: $(HEADER4)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)dependencia.cpp

imprime.o: $(HEADER2)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)imprime.cpp

split.o: $(HEADER1)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)split.cpp
	
clean:
	rm -f $(BIN_DIR)*.o $(PROG)
