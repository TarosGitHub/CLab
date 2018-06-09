/**
 * @file      Test_matrix_construct.c
 * @brief     Test for matrix_construct
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Matrix.h"


void test(int argc, char* argv[])
{
	#define ROW 3
	#define COL 3
	double memory[ROW][COL] = {
		{4.0, 3.0, 2.0}, 
		{2.0, 2.0, 1.0}, 
		{3.0, 6.0, 2.0}
	};
	Matrix matrix;
	
	matrix_construct(&matrix, memory, ROW, COL);
	printf("Construction completed.\n");
	
	matrix_print(&matrix, "%f");
	
	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
