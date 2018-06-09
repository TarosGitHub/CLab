/**
 * @file      Array.h
 * @brief     Array Class
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(ARRAY_H)
#define ARRAY_H

#include "CompStrategy.h"
#include "SortStrategy.h"
#include "MinStrategy.h"

#if defined(DEBUG_ARRAY)
#include <stdio.h>
#endif /* DEBUG_ARRAY */


/***************************
 * Structure
 ***************************/

/**
 * @struct    array
 * @brief     Array
 * @var       memory Memory area of array instance
 * @var       array_size Array size
 * @var       elem_size Element size
 * @var       index_array Index array
 * @var       max_size Get Array maximum size
 * @var       get Get the element of Array
 * @var       set Set a element
 * @var       set_all Set data all of Array elements
 * @var       copy Copy Array
 * @var       compare Compare two elements of Array
 * @details   Class of Array.
 */
struct array {
	/* private */
	char* memory;
	unsigned int array_size;
	unsigned int elem_size;
	unsigned int* index_array;

	/* public */
	void (* implement_comp_strategy)(struct array* array, CompStrategy* const comp_strtgy);
	void (* implement_sort_strategy)(struct array* array, SortStrategy* const sort_strtgy);
	void (* implement_min_strategy)(struct array* array, MinStrategy* const sort_strtgy);
	unsigned int (* max_size)(struct array* array);
	void* (* get)(const struct array* array, unsigned int index);
	void (* set)(struct array* array, unsigned int index, const void* data);
	void (* set_all)(struct array* array, const void* data);
	void (* copy)(const struct array* src, struct array* dst);
	void (* set_index_array)(struct array* array, unsigned int* index_array);
	void (* init_index_array)(struct array* array);
	void* (* iget)(const struct array* array, unsigned int index);
	void (* iset)(struct array* array, unsigned int index, const void* data);
	void (* swap_index)(struct array* array, unsigned int index_i, unsigned int index_j);
	Compare compare;
	Sort sort;
	Min min;

	/* Due to the constraints of GCC. */
	CompStrategy* comp_strtgy;
	SortStrategy* sort_strtgy;
	MinStrategy* min_strtgy;
};

typedef struct array Array;


/***************************
 * Function prototype
 ***************************/
extern void array_construct(Array* array, void* const memory, unsigned int array_size, unsigned int elem_size);
extern void array_implement_comp_strategy(Array* array, CompStrategy* const comp_strtgy);
extern void array_implement_sort_strategy(Array* array, SortStrategy* const sort_strtgy);
extern void array_implement_min_strategy(Array* array, MinStrategy* const min_strtgy);
extern unsigned int array_max_size(Array* array);
extern void* array_get(const Array* array, unsigned int index);
extern void array_set(Array* array, unsigned int index, const void* data);
extern void array_set_all(Array* array, const void* data);
extern void array_copy(const Array* src, Array* dst);
extern void array_set_index_array(Array* array, unsigned int* const index_array);
extern void array_init_index_array(Array* array);
extern void* array_iget(const Array* array, unsigned int index);
extern void array_iset(Array* array, unsigned int index, const void* data);
extern void array_swap_index(Array* array, unsigned int index_i, unsigned int index_j);


/***************************
 * Definition
 ***************************/
#define new_Array(                    \
	type,                             \
	memory,                           \
	array_size                        \
)                                     \
{                                     \
	(char*) (memory),                 \
	(unsigned int) (array_size),      \
	(unsigned int) sizeof(type),      \
	(unsigned int*) (0),              \
	(array_implement_comp_strategy),  \
	(array_implement_sort_strategy),  \
	(array_implement_min_strategy),   \
	(array_max_size),                 \
	(array_get),                      \
	(array_set),                      \
	(array_set_all),                  \
	(array_copy),                     \
	(array_set_index_array),          \
	(array_init_index_array),         \
	(array_iget),                     \
	(array_iset),                     \
	(array_swap_index),               \
	(Compare) (0),                    \
	(Sort) (0),                       \
	(Min) (0)                         \
}

#if defined(DEBUG_ARRAY)
/**
 * @fn        array_print
 * @brief     Print array elements
 * @param     type Type of array element
 * @param     array_p Pointer to Array
 * @param     format Format of printf
 * @param     wrap_num Number of array element per line
 * @return    No return value
 * @details   Print array elements.
 */
#define array_print(                                                \
	type,                                                           \
	array_p,                                                        \
	format,                                                         \
	wrap_num                                                        \
)                                                                   \
{                                                                   \
	unsigned int i;                                                 \
	                                                                \
	for (i = 0; i < (array_p)->max_size(array_p); i++) {            \
		printf((format), *(type*) (array_p)->get((array_p), i));    \
		if ((0 < (wrap_num)) && (((i + 1) % (wrap_num)) == 0)) {    \
			printf("\n");                                           \
		}                                                           \
	}                                                               \
	printf("\n");                                                   \
}

/**
 * @fn        array_iprint
 * @brief     Print array elements via Index Array
 * @param     type Type of array element
 * @param     array_p Pointer to Array
 * @param     format Format of printf
 * @param     wrap_num Number of array element per line
 * @return    No return value
 * @details   Print array elements via Index Array.
 */
#define array_iprint(                                               \
	type,                                                           \
	array_p,                                                        \
	format,                                                         \
	wrap_num                                                        \
)                                                                   \
{                                                                   \
	unsigned int i;                                                 \
	                                                                \
	for (i = 0; i < (array_p)->max_size(array_p); i++) {            \
		printf((format), *(type*) (array_p)->iget((array_p), i));   \
		if ((0 < (wrap_num)) && (((i + 1) % (wrap_num)) == 0)) {    \
			printf("\n");                                           \
		}                                                           \
	}                                                               \
	printf("\n");                                                   \
}
#else /* DEBUG_ARRAY */
#define array_print(type, array_p, format, wrap_num) 
#define array_iprint(type, array_p, format, wrap_num) 
#endif /* DEBUG_ARRAY */


#endif /* ARRAY_H */
