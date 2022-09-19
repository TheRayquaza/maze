CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3 -std=c99 -g -fsanitize=address

SRC= src/reader/reader.c src/solver/solver.c src/tools/tools.c src/generator/generator.c 
TEST= test/test_solver.c

all : maze test_criterion
	./test_criterion

maze : 
	${CC} ${CLAGS} -o maze src/main.c ${SRC}
	mv maze build

test_criterion :
	${CC} ${CFLAGS} -o test_criterion ${SRC} ${TEST} -lcriterion

clean :
	rm -f build/*
	rm -f test_criterion
