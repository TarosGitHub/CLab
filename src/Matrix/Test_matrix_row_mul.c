/**
 * @file      Test_matrix_row_mul.c
 * @brief     Test for matrix_row_mul
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Matrix.h"


void test(int argc, char* argv[])
{
	#define ROW 2
	#define COL 3
	double memory[ROW][COL] = {
		{0.0, 0.1, 0.2}, 
		{1.0, 1.1, 1.2}
	};
	Matrix matrix = new_Matrix(memory, ROW, COL);

	matrix.row_mul(&matrix, 1, 10.0);

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
