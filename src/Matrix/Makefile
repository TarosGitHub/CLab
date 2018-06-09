##
# @file      Makefile
# @brief     Matrix Makefile
# @author    Taro Hoshino
# @date      2017/07/10
# Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
# 

include ../../Config.mk

# Source files
SRCS = Matrix.c

#TEST_SRCS = Test_matrix_construct.c
#TEST_SRCS = Test_matrix_swap.c
#TEST_SRCS = Test_matrix_add.c
#TEST_SRCS = Test_matrix_mul.c
#TEST_SRCS = Test_matrix_row_switch.c
#TEST_SRCS = Test_matrix_row_mul.c
#TEST_SRCS = Test_matrix_row_add.c

# Compiler switch
CFLAGS += -DNDEBUG
#CFLAGS += -DDEBUG_MATRIX

# Object files
OBJS = ${SRCS:.c=.o}
TEST_OBJS = ${TEST_SRCS:.c=.o}

# Includes
INCLUDES  = -I../../include 

# Target
TEST_TARGET = Test.exe

# PHONY Target
.PHONY: build clean tbuild mktest test

# Rules
build: ${SRCS}
	@${CC} ${CFLAGS} ${INCLUDES} -c ${SRCS}
	@${AR} ${ARFLAGS} ${LIBRARY} ${OBJS}

clean: 
	@${RM} ${RMFLAGS} *.o *.exe

tbuild: ${TEST_SRCS}
	@${CC} ${CFLAGS} ${INCLUDES} -c ${TEST_SRCS}

mktest: build tbuild
	@${CC} -o ${TEST_TARGET} ${CFLAGS} ${INCLUDES} ${TEST_OBJS} ${LIBRARY}

test: 
	@./${TEST_TARGET}

