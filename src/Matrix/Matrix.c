/**
 * @file      Matrix.c
 * @brief     Matrix Class
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "Matrix.h"
#include "Library.h"

#if defined(DEBUG_MATRIX)
#include <stdio.h>
#endif /* DEBUG_MATRIX */


/***************************
 * Function
 ***************************/

/**
 * @fn        matrix_construct
 * @brief     Matrix constructor
 * @param     matrix Matrix
 * @param     memory Memory area
 * @param     row Row of the matrix
 * @param     col Columm of the matrix
 * @return    No return value
 * @details   Construct Matrix.
 */
void 
matrix_construct(
	Matrix* matrix, 
	const void* memory, 
	unsigned int row, 
	unsigned int col
)
{
	/* Member variable */
	matrix->row = row;
	matrix->col = col;
	matrix->memory = (double*) memory;

	/* Member function */
	matrix->get = matrix_get;
	matrix->set = matrix_set;
	matrix->set_all = matrix_set_all;
	matrix->swap = matrix_swap;
	matrix->copy = matrix_copy;
	matrix->sclr_mul = matrix_sclr_mul;
	matrix->add = matrix_add;
	matrix->mul = matrix_mul;
	matrix->row_switch = matrix_row_switch;
	matrix->row_mul = matrix_row_mul;
	matrix->row_add = matrix_row_add;

	return;
}

/**
 * @fn        matrix_get
 * @brief     Get the element
 * @param     matrix Matrix
 * @param     row Row of the matrix
 * @param     col Columm of the matrix
 * @return    The element
 * @details   Get the element of the row and the col.
 */
double 
matrix_get(
	const Matrix* matrix, 
	unsigned int row, 
	unsigned int col
)
{
	return matrix->memory[matrix->col * row + col];
}

/**
 * @fn        matrix_set
 * @brief     Set data to the element
 * @param     matrix Matrix
 * @param     row Row of the matrix
 * @param     col Columm of the matrix
 * @param     data Data to set
 * @return    No return value
 * @details   Set the element of the row and the col.
 */
void 
matrix_set(
	Matrix* matrix, 
	unsigned int row, 
	unsigned int col, 
	double data
)
{
	matrix->memory[matrix->col * row + col] = data;

	return;
}

/**
 * @fn        matrix_set_all
 * @brief     Set data to all elements
 * @param     matrix Matrix
 * @param     data Data to set
 * @return    No return value
 * @details   Set data to all elements of the matrix.
 */
void 
matrix_set_all(
	Matrix* matrix, 
	double data
)
{
	unsigned int i;		/* Row */
	unsigned int j;		/* Columm */

	for (i = 0; i < matrix->row; i++) {
		for (j = 0; j < matrix->col; j++) {
			matrix_set(matrix, i, j, data);
		}
	}

	return;
}

/**
 * @fn        matrix_swap
 * @brief     Elements swapping
 * @param     matrix Matrix
 * @param     n_row The n-th row
 * @param     n_col The n-th column
 * @param     m_row The m-th row
 * @param     m_col The m-th column
 * @return    No return value
 * @details   Swap the elements of the matrix.
 */
void 
matrix_swap(
	Matrix* matrix, 
	unsigned int n_row, 
	unsigned int n_col, 
	unsigned int m_row, 
	unsigned int m_col
)
{
	double tmp;

	tmp = matrix_get(matrix, n_row, n_col);
	matrix_set(matrix, n_row, n_col, matrix_get(matrix, m_row, m_col));
	matrix_set(matrix, m_row, m_col, tmp);

	return;
}

/**
 * @fn        matrix_copy
 * @brief     Copy the matrix
 * @param     dst_matrix Copy destination matrix
 * @param     src_matrix Copy source matrix
 * @return    No return value
 * @details   Copy all elements of src_matrix to dst_matrix.
 */
void 
matrix_copy(
	Matrix* dst_matrix, 
	const Matrix* src_matrix
)
{
	lib_memcpy(dst_matrix->memory, src_matrix->memory, sizeof(double) * dst_matrix->col * dst_matrix->row);

	return;
}

/**
 * @fn        matrix_sclr_mul
 * @brief     Scalar multiplication of matrix
 * @param     matrix Matrix
 * @param     scalar Scalar
 * @return    No return value
 * @details   Scalar multiplication of matrix.
 */
void 
matrix_sclr_mul(
	Matrix* matrix, 
	double scalar
)
{
	unsigned int i;		/* Row */
	unsigned int j;		/* Columm */

	for (i = 0; i < matrix->row; i++) {
		for (j = 0; j < matrix->col; j++) {
			matrix_set(matrix, i, j, scalar * matrix_get(matrix, i, j));
		}
	}

	return;
}

/**
 * @fn        matrix_add
 * @brief     Addition of a matrix
 * @param     sum Sum of matrices
 * @param     first The first Matrix
 * @param     second The Second Matrix
 * @return    No return value
 * @details   Add the first matrix and the second matrix to the sum.
 */
void 
matrix_add(
	Matrix* sum, 
	const Matrix* first, 
	const Matrix* second
)
{
	unsigned int i;		/* Row */
	unsigned int j;		/* Columm */

	lib_assert(first->row == second->row);
	lib_assert(first->col == second->col);

	for (i = 0; i < sum->row; i++) {
		for (j = 0; j < sum->col; j++) {
			matrix_set(sum, i, j, matrix_get(first, i, j) + matrix_get(second, i, j));
		}
	}

	return;
}

/**
 * @fn        matrix_mul
 * @brief     Multiply of a matrix
 * @param     product Product of matrices
 * @param     first The first Matrix
 * @param     second The Second Matrix
 * @return    No return value
 * @details   Multiply the first matrix and the second matrix to the product.
 */
void 
matrix_mul(
	Matrix* product, 
	const Matrix* first, 
	const Matrix* second
)
{
	unsigned int i;		/* Row */
	unsigned int j;		/* Columm */
	unsigned int k;		/* Iterator of matrix elements */
	double product_i_j;	/* The i, j element */

	lib_assert(first->col == second->row);

	for (i = 0; i < product->row; i++) {
		for (j = 0; j < product->col; j++) {
			/* Compute the i, j element. */
			product_i_j = 0.0;
			for (k = 0; k < first->col; k++) {
				product_i_j += matrix_get(first, i, k) * matrix_get(second, k, j);
			}

			/* Set the i, j element. */
			matrix_set(product, i, j, product_i_j);
		}
	}

	return;
}

/**
 * @fn        matrix_row_switch
 * @brief     Row switching - Elementary row operations
 * @param     matrix Matrix
 * @param     n_row The n-th row
 * @param     m_row The m-th row
 * @return    No return value
 * @details   A row within the matrix can be switched with another row.
 *            Rn <-> Rm
 */
void 
matrix_row_switch(
	Matrix* matrix, 
	unsigned int n_row, 
	unsigned int m_row
)
{
	unsigned int j;		/* Columm */

	for (j = 0; j < matrix->col; j++) {
		matrix_swap(matrix, n_row, j, m_row, j);
	}

	return;
}

/**
 * @fn        matrix_row_mul
 * @brief     Row multiplication - Elementary row operations
 * @param     matrix Matrix
 * @param     n_row The n-th row
 * @param     constant A constant
 * @return    No return value
 * @details   Each element in a row can be multiplied by a non-zero constant.
 *            c * Rn -> Rn, where c != 0
 */
void 
matrix_row_mul(
	Matrix* matrix, 
	unsigned int n_row, 
	double constant
)
{
	unsigned int j;		/* Columm */

	/* lib_assert(constant != 0.0); */
	lib_assert((constant < 0.0) || (0.0 < constant));

	for (j = 0; j < matrix->col; j++) {
		matrix_set(matrix, n_row, j, constant * matrix_get(matrix, n_row, j));
	}

	return;
}

/**
 * @fn        matrix_row_add
 * @brief     Row addition - Elementary row operations
 * @param     matrix Matrix
 * @param     n_row The n-th row
 * @param     m_row The m-th row
 * @param     constant A constant
 * @return    No return value
 * @details   A row can be replaced by the sum of that row and a multiple of another row.
 *            Rn + c * Rm -> Rn, where n != m
 */
void 
matrix_row_add(
	Matrix* matrix, 
	unsigned int n_row, 
	unsigned int m_row, 
	double constant
)
{
	unsigned int j;		/* Columm */

	lib_assert(n_row != m_row);

	for (j = 0; j < matrix->col; j++) {
		matrix_set(matrix, n_row, j, matrix_get(matrix, n_row, j) + constant * matrix_get(matrix, m_row, j));
	}

	return;
}

#if defined(DEBUG_MATRIX)
/**
 * @fn        matrix_print
 * @brief     Print the matrix.
 * @param     matrix Matrix
 * @param     elem_format Output format of a element
 * @return    No return value
 * @details   Print all elements of the matrix.
 */
void 
matrix_print(
	const Matrix* matrix, 
	const char* elem_format
)
{
	unsigned int i;		/* Row */
	unsigned int j;		/* Columm */

	for (i = 0; i < matrix->row; i++) {
		for (j = 0; j < matrix->col; j++) {
			printf("[%d][%d]=", i, j);
			printf(elem_format, matrix_get(matrix, i, j));
			printf("  ");
		}
		printf("\n");
	}
}
#endif /* DEBUG_MATRIX */
