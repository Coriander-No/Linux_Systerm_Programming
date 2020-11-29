INC_DIR=./include
SRC_DIR=./source
OBJ_DIR=./obj
BIN_DIR=./bin

# wildcard把source路径中的文件展开
SRC=$(wildcard ${SRC_DIR}/*.c)
# notdir把展开的文件去除掉路径信息
OBJ=$(patsubst %.c,${OBJ_DIR}/*.o,$(notdir ${SRC}))

TARGET=open
BIN_TARGET=${BIN_DIR}/${TARGET}

CC=gcc
CFLAGS= -g -I${INC_DIR}

${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ) -o $@
${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY:clean
clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(BIN_DIR)/*
