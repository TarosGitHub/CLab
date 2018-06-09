##
# @file      Config.mk
# @brief     Configuration file of Makefile
# @author    Taro Hoshino
# Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
# 

####################
# Directory
####################
WORK_DIR    = C:/Users/Taro/Desktop/project/Lab
LIB_DIR     = ${WORK_DIR}/lib
INCLUDE_DIR = ${WORK_DIR}/include


####################
# Library
####################
LIBRARY = ${LIB_DIR}/lib.a 


####################
# Tools
####################
CD = cd
RM = rm
CC = gcc
AR = ar


####################
# Option
####################

## For RM
RMFLAGS = -f
CLN_FILE_SUFFIX  = *.o
CLN_FILE_SUFFIX += *.bak
CLN_FILE_SUFFIX += *.skrold *.skrnew

## For CC
CFLAGS  = -Wall
CFLAGS += -g
#CFLAGS += -O3

## For AR
ARFLAGS = crv


####################
# Export
####################
export WORK_DIR
export LIB_DIR
export INCLUDE_DIR
export LIBRARY
export LIB_NAME
export CD
export RM
export CC
export AR
export RMFLAGS
export CLN_FILE_SUFFIX
export CFLAGS
export ARFLAGS

