/**
 * @file      Array.c
 * @brief     Array
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "Array.h"
#include "Math.h"
#include "Library.h"


/***************************
 * Function
 ***************************/

/**
 * @fn        array_construct
 * @brief     Array constructor
 * @param     array Array
 * @param     memory Memory area
 * @param     array_size Array size
 * @param     elem_size Element size
 * @return    No return value
 * @details   Construct Array.
 */
void 
array_construct(
	Array* array, 
	void* const memory, 
	unsigned int array_size, 
	unsigned int elem_size
)
{
	/* Member variable */
	array->memory = (char*) memory;
	array->array_size = array_size;
	array->elem_size = elem_size;
	array->index_array = (unsigned int*) 0;

	/* Member function */
	array->implement_comp_strategy = array_implement_comp_strategy;
	array->implement_sort_strategy = array_implement_sort_strategy;
	array->implement_min_strategy = array_implement_min_strategy;
	array->max_size = array_max_size;
	array->get = array_get;
	array->set = array_set;
	array->set_all = array_set_all;
	array->copy = array_copy;
	array->set_index_array = array_set_index_array;
	array->init_index_array = array_init_index_array;
	array->iget = array_iget;
	array->iset = array_iset;
	array->swap_index = array_swap_index;
	array->compare = (Compare) 0;
	array->sort = (Sort) 0;
	array->min = (Min) 0;

	return;
}

/**
 * @fn        array_implement_comp_strategy
 * @brief     Implement CompStrategy
 * @param     array Array
 * @param     comp_strtgy CompStrategy
 * @return    No return value
 * @details   Implement CompStrategy.
 */
void 
array_implement_comp_strategy(
	Array* array, 
	CompStrategy* const comp_strtgy
)
{
	/* This is the original process. */
	/* array->compare = (Compare) comp_strtgy; */

	/* Due to the constraints of GCC, we created a function that returns a pointer to the compare function. */
	array->comp_strtgy = comp_strtgy;
	array->compare = comp_strategy_func(comp_strtgy);

	return;
}

/**
 * @fn        array_implement_sort_strategy
 * @brief     Implement SortStrategy
 * @param     array Array
 * @param     sort_strtgy SortStrategy
 * @return    No return value
 * @details   Implement SortStrategy.
 */
void 
array_implement_sort_strategy(
	Array* array, 
	SortStrategy* const sort_strtgy
)
{
	/* This is the original process. */
	/* array->sort = (Sort) sort_strtgy; */

	/* Due to the constraints of GCC, we created a function that returns a pointer to the sort function. */
	array->sort_strtgy = sort_strtgy;
	array->sort = sort_strategy_func(sort_strtgy);

	return;
}

/**
 * @fn        array_implement_min_strategy
 * @brief     Implement MinStrategy
 * @param     array Array
 * @param     sort_strtgy MinStrategy
 * @return    No return value
 * @details   Implement MinStrategy.
 */
void 
array_implement_min_strategy(
	Array* array, 
	MinStrategy* const min_strtgy
)
{
	/* This is the original process. */
	/* array->min = (Min) min_strtgy; */

	/* Due to the constraints of GCC, we created a function that returns a pointer to the min function. */
	array->min_strtgy = min_strtgy;
	array->min = min_strategy_func(min_strtgy);

	return;
}

/**
 * @fn        array_max_size
 * @brief     Get the maximum size
 * @param     array Array
 * @return    The maximum size
 * @details   Get the maximum size of the array.
 */
unsigned int 
array_max_size(
	Array* array
)
{
	return array->array_size;
}

/**
 * @fn        array_get
 * @brief     Get the element
 * @param     array Array
 * @param     index Array index
 * @return    The element
 * @details   Get the elements of the array specified by index.
 */
void* 
array_get(
	const Array* array, 
	unsigned int index
)
{
	return (void*) &array->memory[array->elem_size * index];
}

/**
 * @fn        array_set
 * @brief     Set data
 * @param     array Array
 * @param     index Array index
 * @param     data Data to be set
 * @return    No return value
 * @details   Set data at the position specified by index.
 */
void 
array_set(
	Array* array, 
	unsigned int index, 
	const void* data
)
{
	lib_memcpy(&array->memory[array->elem_size * index], data, array->elem_size);

	return;
}

/**
 * @fn        array_set_all
 * @brief     Set data for all elements
 * @param     array Array
 * @param     data Data to be set
 * @return    No return value
 * @details   Set data for all elements.
 */
void 
array_set_all(
	Array* array, 
	const void* data
)
{
	unsigned int i;

	for (i = 0; i < array->array_size; i++) {
		lib_memcpy(&array->memory[array->elem_size * i], data, array->elem_size);
	}

	return;
}

/**
 * @fn        array_copy
 * @brief     Copy array
 * @param     src The source array
 * @param     dst The destination array
 * @return    No return value
 * @details   Copy the source array to the destination array. Only copy elements.
 *            If the array sizes are different, copy only the small size.
 *            If the element sizes are different, copy only the small size.
 */
void 
array_copy(
	const Array* src, 
	Array* dst
)
{
	unsigned int i;
	unsigned int size_min;
	unsigned int elem_size_min;

	size_min = math_min(src->array_size, dst->array_size);
	elem_size_min = math_min(src->elem_size, dst->elem_size);

	for (i = 0; i < size_min; i++) {
		char* dst_elem = &dst->memory[dst->elem_size * i];
		lib_memset(dst_elem, 0x00, dst->elem_size);
		lib_memcpy(dst_elem, &src->memory[src->elem_size * i], elem_size_min);
	}

	return;
}

/**
 * @fn        array_set_index_array
 * @brief     Set Index Array
 * @param     array Array
 * @param     index_array Index Array
 * @return    No return value
 * @details   Set Index Array.
 */
void 
array_set_index_array(
	Array* array, 
	unsigned int* const index_array
)
{
	array->index_array = index_array;

	return;
}

/**
 * @fn        array_init_index_array
 * @brief     Initializing Index Array
 * @param     array Array
 * @return    No return value
 * @details   Initialize Index Array.
 */
void 
array_init_index_array(
	Array* array
)
{
	unsigned int i;

	for (i = 0; i < array->array_size; i++) {
		array->index_array[i] = i;
	}

	return;
}

/**
 * @fn        array_iget
 * @brief     Get the element via Index Array
 * @param     array Array
 * @param     index Index Array index
 * @return    No return value
 * @details   Get the element via Index Array.
 */
void* 
array_iget(
	const Array* array, 
	unsigned int index
)
{
	return array_get(array, array->index_array[index]);
}

/**
 * @fn        array_iset
 * @brief     Set the element via Index Array
 * @param     array Array
 * @param     index Index Array index
 * @param     data Data to be set
 * @return    No return value
 * @details   Set the element via Index Array.
 */
void 
array_iset(
	Array* array, 
	unsigned int index, 
	const void* data
)
{
	array_set(array, array->index_array[index], data);

	return;
}

/**
 * @fn        array_swap_index
 * @brief     Swap index of Index Array
 * @param     array Array
 * @param     index_i The i-th index of Index Array
 * @param     index_j The j-th index of Index Array
 * @return    No return value
 * @details   Swap index of Index Array.
 */
void 
array_swap_index(
	Array* array, 
	unsigned int index_i, 
	unsigned int index_j
)
{
	unsigned int tmp;

	tmp = array->index_array[index_i];
	array->index_array[index_i] = array->index_array[index_j];
	array->index_array[index_j] = tmp;

	return;
}
