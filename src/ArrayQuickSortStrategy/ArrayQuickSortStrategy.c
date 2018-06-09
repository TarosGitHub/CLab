/**
 * @file      ArrayQuickSortStrategy.c
 * @brief     Array Quick Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "ArrayQuickSortStrategy.h"
#include "Array.h"


/***************************
 * Function prototype
 ***************************/
static void array_quick_sort_strategy_sort_process(Array* array, int left, int right);
static int array_quick_sort_strategy_partition(Array* array, int left, int right);


/***************************
 * Function
 ***************************/

/**
 * @fn        array_quick_sort_strategy_construct
 * @brief     Constructor of the ArrayQuickSortStrategy
 * @param     sort_strtgy Array Quick Sort Strategy
 * @return    No return value
 * @details   Constructor of the ArrayQuickSortStrategy.
 */
void 
array_quick_sort_strategy_construct(
	ArrayQuickSortStrategy* sort_strtgy
)
{
	sort_strategy_construct(&sort_strtgy->base, array_quick_sort_strategy_sort);

	return;
}

/**
 * @fn        array_quick_sort_strategy_construct
 * @brief     Array quick sort
 * @param     sort_strtgy Array Quick Sort Strategy
 * @param     collection Collection
 * @return    No return value
 * @details   Quickion sort of Array.
 *            It is necessary to set a comparison function in the array in advance.
 *            By comparison functions, the contents of the array are arranged in ascending order.
 *            The comparison function MUST return either an integer less than zero, 
 *            an integer greater than zero, or an integer greater than zero, depending on whether 
 *            the first argument is less than, equal to, or greater than the second argument.
 */
void 
array_quick_sort_strategy_sort(
	void* sort_strtgy, 
	void* const collection
)
{
	Array* const array = (Array* const) collection;

	array_quick_sort_strategy_sort_process(array, 0, array->max_size(array) - 1);

	return;
}

/**
 * @fn        array_quick_sort_strategy_sort_process
 * @brief     Array quick sort main process
 * @param     array Array
 * @param     left Leftmost of the range to be sorted
 * @param     right Rightmost of the range to be sorted
 * @return    No return value
 * @details   Array quick sort main process.
 */
static void 
array_quick_sort_strategy_sort_process(
	Array* array, 
	int left, 
	int right
)
{
	int pivot;

	/* Do nothing if you have one element to align */
	if (right <= left) {
		return;
	}

	/* Partition the array based on pivot */
	pivot = array_quick_sort_strategy_partition(array, left, right);

	/* Sort the partial array on the left */
	array_quick_sort_strategy_sort_process(array, left, pivot - 1);

	/* Sort the partial array on the right */
	array_quick_sort_strategy_sort_process(array, pivot + 1, right);

	return;
}

/**
 * @fn        array_quick_sort_strategy_partition
 * @brief     Partition the array
 * @param     array Array
 * @param     left Leftmost of the range to be sorted
 * @param     right Rightmost of the range to be sorted
 * @return    Subscript of the pivot
 * @details   Partition the array.
 */
static int 
array_quick_sort_strategy_partition(
	Array* array, 
	int left, 
	int right
)
{
	int l;
	int r;
	int pivot;

	l = left;
	r = right - 1;

	/* Pivot the rightmost element */
	pivot = right;

	while (1) {
		/* Move pointer l to the right */
		while (0 > array->compare(array->comp_strtgy, array->iget(array, l), array->iget(array, pivot))) {
			l++;
		}

		/* Move pointer r to the lest */
		while ((l < r) && (0 < array->compare(array->comp_strtgy, array->iget(array, r), array->iget(array, pivot)))) {
			r--;
		}

		/* If pointer l and pointer r collide, we get out of the loop */
		if (r <= l) {
			break;
		}

		/* Pointer l exchange the element pointing to pointer r */
		array->swap_index(array, l, r);
	}

	/* Pointer l exchange the element pointing to pivot */
	array->swap_index(array, l, pivot);

	return l;
}
