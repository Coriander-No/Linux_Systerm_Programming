INC_DIR=./include
SRC_DIR=./source
OBJ_DIR=./obj
BIN_DIR=./bin

SRC=$(wildcard ${SRC_DIR}/*.c)
OBJ=$(patsubst %.c,${OBJ_DIR}/*.o,$(notdir ${SRC}))

TARGET=copy
BIN_TARGET=${BIN_DIR}/${TARGET}

CC=gcc
CFLAGS= -g -I${INC_DIR}

${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ) -o $@
${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY:clean
clean:
	find ${OBJ_DIR} -name *.o -exce rm -rf {}


