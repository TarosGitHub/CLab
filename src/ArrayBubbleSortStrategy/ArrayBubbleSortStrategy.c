/**
 * @file      ArrayBubbleSortStrategy.c
 * @brief     Array Bubble Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "ArrayBubbleSortStrategy.h"
#include "Array.h"


/***************************
 * Function
 ***************************/

/**
 * @fn        array_bubble_sort_strategy_construct
 * @brief     Constructor of the ArrayBubbleSortStrategy
 * @param     sort_strtgy Array Bubble Sort Strategy
 * @return    No return value
 * @details   Constructor of the ArrayBubbleSortStrategy.
 */
void 
array_bubble_sort_strategy_construct(
	ArrayBubbleSortStrategy* sort_strtgy
)
{
	sort_strategy_construct(&sort_strtgy->base, array_bubble_sort_strategy_sort);

	return;
}

/**
 * @fn        array_bubble_sort_strategy_construct
 * @brief     Array bubble sort
 * @param     sort_strtgy Array Bubble Sort Strategy
 * @param     collection Collection
 * @return    No return value
 * @details   Bubble Sort of Array.
 *            It is necessary to set a comparison function in the array in advance.
 *            By comparison functions, the contents of the array are arranged in ascending order.
 *            The comparison function MUST return either an integer less than zero, 
 *            an integer greater than zero, or an integer greater than zero, depending on whether 
 *            the first argument is less than, equal to, or greater than the second argument.
 */
void 
array_bubble_sort_strategy_sort(
	void* sort_strtgy, 
	void* const collection
)
{
	Array* const array = (Array* const) collection;
	unsigned int i;
	unsigned int j;

	for (i = 0; i < array->max_size(array) - 1; i++) {
		for (j = array->max_size(array) - 1; i < j; j--) {
			if (0 < array->compare(array->comp_strtgy, array->iget(array, j - 1), array->iget(array, j))) {
				array->swap_index(array, j - 1, j);
			}
		}
	}

	return;
}
