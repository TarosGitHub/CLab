/**
 * @file      Test_array_construct.c
 * @brief     Test for array_construct
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Array.h"


void test(int argc, char* argv[])
{
	#define ARRAY_SIZE 10
	int memory[ARRAY_SIZE] = {0};
	Array array;
	
	array_construct(&array, memory, ARRAY_SIZE, sizeof(int));
	printf("Construction completed.\n");
	
	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
