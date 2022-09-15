CC = gcc
CPPFLAGS = -MMD
CFLAGS = -Wall -Werror -Wextra -O0 -std=c99 -g -fsanitize=address

SRC= src/main.c src/reader/reader.c src/solver/solver.c src/tools/tools.c src/generator/generator.c 
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all : ${OBJ}
	${CC} ${CFLAGS} -o maze ${OBJ}
	mv maze build

-include ${DEP}

clean :
	rm -f ${OBJ}
	rm -f ${DEP}
	rm build/maze
