CC= gcc
CFLAGS= -Wall -I.
EXE_NAME=Poems
FILES= main.c poems.c
INCLUDE = 

all: $(FILES) $(INCLUDE)
	clear
	$(CC) -o $(EXE_NAME) $(FILES)  $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f $(EXE_NAME)
	
run:
	./$(EXE_NAME) -l

run2:
	./$(EXE_NAME) -p Butterfly

run3:
	./$(EXE_NAME) -p House

run4:
	./$(EXE_NAME) -p Night

run5:
	./$(EXE_NAME) -p joku

rb: clean all

b: clean all run

b2: clean all run2

b3: clean all run3

b4: clean all run4

b5: clean all run5

