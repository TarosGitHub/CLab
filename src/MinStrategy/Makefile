##
# @file      Makefile
# @brief     MinStrategy Makefile
# @author    Taro Hoshino
# Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
# 

include ../../Config.mk

# Source files
SRCS = MinStrategy.c

#TEST_SRCS = Test_min_strategy_construct.c

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

