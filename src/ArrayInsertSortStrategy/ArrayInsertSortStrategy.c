/**
 * @file      ArrayInsertSortStrategy.c
 * @brief     Array Insert Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "ArrayInsertSortStrategy.h"
#include "Array.h"


/***************************
 * Function
 ***************************/

/**
 * @fn        array_insert_sort_strategy_construct
 * @brief     Constructor of the ArrayInsertSortStrategy
 * @param     sort_strtgy Array Insert Sort Strategy
 * @return    No return value
 * @details   Constructor of the ArrayInsertSortStrategy.
 */
void 
array_insert_sort_strategy_construct(
	ArrayInsertSortStrategy* sort_strtgy
)
{
	sort_strategy_construct(&sort_strtgy->base, array_insert_sort_strategy_sort);

	return;
}

/**
 * @fn        array_insert_sort_strategy_construct
 * @brief     Array insertion sort
 * @param     sort_strtgy Array Insert Sort Strategy
 * @param     collection Collection
 * @return    No return value
 * @details   Insertion sort of Array.
 *            It is necessary to set a comparison function in the array in advance.
 *            By comparison functions, the contents of the array are arranged in ascending order.
 *            The comparison function MUST return either an integer less than zero, 
 *            an integer greater than zero, or an integer greater than zero, depending on whether 
 *            the first argument is less than, equal to, or greater than the second argument.
 */
void 
array_insert_sort_strategy_sort(
	void* sort_strtgy, 
	void* const collection
)
{
	Array* const array = (Array* const) collection;
	unsigned int i;
	unsigned int j;

	for (i = 1; i < array->max_size(array); i++) {
		for (j = i; (1 <= j) && (0 < array->compare(array->comp_strtgy, array->iget(array, j - 1), array->iget(array, j))); j--) {
			array->swap_index(array, j - 1, j);
		}
	}

	return;
}
