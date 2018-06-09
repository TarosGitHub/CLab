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
	#define FROW 2
	#define FCOL 3
	#define SROW 3
	#define SCOL 2
	double first[FROW][FCOL] = {
		{0.0, 0.1, 0.2}, 
		{1.0, 1.1, 1.2}
	};
	double second[SROW][SCOL] = {
		{10.0, 100.0}, 
		{10.0, 100.0}, 
		{10.0, 100.0}
	};
	double product[FROW][SCOL] = {
		{0.0, 0.0}, 
		{0.0, 0.0}
	};
	Matrix fmat = new_Matrix(first, FROW, FCOL);
	Matrix smat = new_Matrix(second, SROW, SCOL);
	Matrix prdmat = new_Matrix(product, FROW, SCOL);
	
	/* Addition of a matrix */
	prdmat.mul(&prdmat, &fmat, &smat);
	
	matrix_print(&prdmat, "%f");
	
	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
