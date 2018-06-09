/**
 * @file      Matrix.h
 * @brief     Matrix Class
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(MATRIX_H)
#define MATRIX_H

/***************************
 * Structure
 ***************************/

/**
 * @struct    matrix
 * @brief     Matrix
 * @var       row Row of the matrix
 * @var       col Columm of the matrix
 * @var       memory Memory area of matrix instance
 * @details   Class of Matrix.
 */
struct matrix {
	/* private */
	unsigned int row;
	unsigned int col;
	double* memory;

	/* public */
	double (* get)(const struct matrix* matrix, unsigned int row, unsigned int col);
	void (* set)(struct matrix* matrix, unsigned int row, unsigned int col, double data);
	void (* set_all)(struct matrix* matrix, double data);
	void (* swap)(struct matrix* matrix, unsigned int n_row, unsigned int n_col, unsigned int m_row, unsigned int m_col);
	void (* copy)(struct matrix* dst_matrix, const struct matrix* src_matrix);
	void (* sclr_mul)(struct matrix* matrix, double scalar);
	void (* add)(struct matrix* sum, const struct matrix* first, const struct matrix* second);
	void (* mul)(struct matrix* product, const struct matrix* first, const struct matrix* second);
	void (* row_switch)(struct matrix* matrix, unsigned int n_row, unsigned int m_row);
	void (* row_mul)(struct matrix* matrix, unsigned int n_row, double constant);
	void (* row_add)(struct matrix* matrix, unsigned int n_row, unsigned int m_row, double constant);
};

typedef struct matrix Matrix;


/***************************
 * Function prototype
 ***************************/
extern void matrix_construct(Matrix* matrix, const void* memory, unsigned int row, unsigned int col);
extern double matrix_get(const Matrix* matrix, unsigned int row, unsigned int col);
extern void matrix_set(Matrix* matrix, unsigned int row, unsigned int col, double data);
extern void matrix_set_all(Matrix* matrix, double data);
extern void matrix_swap(Matrix* matrix, unsigned int n_row, unsigned int n_col, unsigned int m_row, unsigned int m_col);
extern void matrix_copy(Matrix* dst_matrix, const Matrix* src_matrix);
extern void matrix_sclr_mul(Matrix* matrix, double scalar);
extern void matrix_add(Matrix* sum, const Matrix* first, const Matrix* second);
extern void matrix_mul(Matrix* product, const Matrix* first, const Matrix* second);
extern void matrix_row_switch(Matrix* matrix, unsigned int n_row, unsigned int m_row);
extern void matrix_row_mul(Matrix* matrix, unsigned int n_row, double constant);
extern void matrix_row_add(Matrix* matrix, unsigned int n_row, unsigned int m_row, double constant);

#if defined(DEBUG_MATRIX)
extern void matrix_print(const Matrix* matrix, const char* elem_format);
#else /* DEBUG_MATRIX */
#define matrix_print(matrix, elem_format) 
#endif /* DEBUG_MATRIX */


/***************************
 * Definition
 ***************************/
#define new_Matrix(        \
	memory,                \
	row,                   \
	col                    \
)                          \
{                          \
	(unsigned int) (row),  \
	(unsigned int) (col),  \
	(double*) (memory),    \
	matrix_get,            \
	matrix_set,            \
	matrix_set_all,        \
	matrix_swap,           \
	matrix_copy,           \
	matrix_sclr_mul,       \
	matrix_add,            \
	matrix_mul,            \
	matrix_row_switch,     \
	matrix_row_mul,        \
	matrix_row_add         \
}

#endif /* MATRIX_H */
