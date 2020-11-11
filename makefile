CC = gcc
CFLAGS = -Wall -g
INCLUDE = 
LIBS = -lm

ODIR = build
dummy_build_folder := $(shell mkdir -p $(ODIR))

main: src/doublyLinkedList.c src/main.c
	${make_build}
	${CC} ${CFLAGS} ${INCLUDE} ${LIBS} -o ${ODIR}/main src/doublyLinkedList.c src/main.c

clean:
	rm -f build/*.o
	rm -f build/main