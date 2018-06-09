/**
 * @file      ArraySelectSortStrategy.c
 * @brief     Array Select Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "ArraySelectSortStrategy.h"
#include "Array.h"


/***************************
 * Function prototype
 ***************************/
static unsigned int array_select_sort_strategy_min_index_range(const Array* array, unsigned int first, unsigned int last);


/***************************
 * Function
 ***************************/

/**
 * @fn        array_select_sort_strategy_construct
 * @brief     Constructor of the ArraySelectSortStrategy
 * @param     sort_strtgy Array Select Sort Strategy
 * @return    No return value
 * @details   Constructor of the ArraySelectSortStrategy.
 */
void 
array_select_sort_strategy_construct(
	ArraySelectSortStrategy* sort_strtgy
)
{
	sort_strategy_construct(&sort_strtgy->base, array_select_sort_strategy_sort);

	return;
}

/**
 * @fn        array_select_sort_strategy_construct
 * @brief     Array selection sort
 * @param     sort_strtgy Array Select Sort Strategy
 * @param     collection Collection
 * @return    No return value
 * @details   Selection sort of Array.
 *            It is necessary to set a comparison function in the array in advance.
 *            By comparison functions, the contents of the array are arranged in ascending order.
 *            The comparison function MUST return either an integer less than zero, 
 *            an integer greater than zero, or an integer greater than zero, depending on whether 
 *            the first argument is less than, equal to, or greater than the second argument.
 */
void 
array_select_sort_strategy_sort(
	void* sort_strtgy, 
	void* const collection
)
{
	Array* const array = (Array* const) collection;
	unsigned int i;
	unsigned int lowest;

	for (i = 0; i < array->max_size(array) - 1; i++) {
		lowest = array_select_sort_strategy_min_index_range(array, i, array->max_size(array) - 1);
		if (i != lowest) {
			array->swap_index(array, i, lowest);
		}
	}

	return;
}

/**
 * @fn        array_select_sort_strategy_min_index_range
 * @brief     Get the index of the minimum value in the range
 * @param     array Array
 * @param     first The first of the range
 * @param     last The last of the range
 * @return    The index of the minimum value in the range
 * @details   Get the index of the minimum value in the range.
 */
static unsigned int 
array_select_sort_strategy_min_index_range(
	const Array* array, 
	unsigned int first, 
	unsigned int last
)
{
	unsigned int i;
	unsigned int lowest;

	lowest = first;

	for (i = first + 1; i <= last; i++) {
		if (0 > array->compare(array->comp_strtgy, array->iget(array, i), array->iget(array, lowest))) {
			lowest = i;
		}
	}

	return lowest;
}
