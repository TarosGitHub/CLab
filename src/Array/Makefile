##
# @file      Makefile
# @brief     Array Makefile
# @author    Taro Hoshino
# Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
# 

include ../../Config.mk

# Source files
SRCS = Array.c

#TEST_SRCS = Test_array_construct.c
#TEST_SRCS = Test_array_implement_comp_strategy.c
#TEST_SRCS = Test_array_implement_sort_strategy.c
#TEST_SRCS = Test_array_max_size.c
#TEST_SRCS = Test_array_get_set.c
#TEST_SRCS = Test_array_min_max.c
#TEST_SRCS = Test_array_copy.c
#TEST_SRCS = Test_array_set_index_array.c
#TEST_SRCS = Test_array_iget.c

# Compiler switch
#CFLAGS += -DDEBUG_ARRAY

# Object files
OBJS = ${SRCS:.c=.o}
TEST_OBJS = ${TEST_SRCS:.c=.o}

# Includes
INCLUDES  = -I../../include 

# Target
TEST_TARGET = TestArray.exe

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

