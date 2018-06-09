/**
 * @file      Test_matrix_add.c
 * @brief     Test for matrix_add
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Matrix.h"


void test(int argc, char* argv[])
{
	#define ROW 3
	#define COL 3
	double first[ROW][COL] = {
		{0.0, 0.1, 0.2}, 
		{1.0, 1.1, 1.2}, 
		{2.0, 2.1, 2.2}
	};
	double second[ROW][COL] = {
		{10.0, 10.0, 10.0}, 
		{10.0, 10.0, 10.0}, 
		{10.0, 10.0, 10.0}
	};
	double sum[ROW][COL] = {
		{0.0, 0.0, 0.0}, 
		{0.0, 0.0, 0.0}, 
		{0.0, 0.0, 0.0}
	};
	Matrix fmat = new_Matrix(first, ROW, COL);
	Matrix smat = new_Matrix(second, ROW, COL);
	Matrix summat = new_Matrix(sum, ROW, COL);
	
	/* Addition of a matrix */
	summat.add(&summat, &fmat, &smat);
	
	matrix_print(&summat, "%f");
	
	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
