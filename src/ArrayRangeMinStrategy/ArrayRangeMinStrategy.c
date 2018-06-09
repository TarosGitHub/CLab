/**
 * @file      ArrayRangeMinStrategy.c
 * @brief     Array Range Min Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "ArrayRangeMinStrategy.h"
#include "Array.h"


/***************************
 * Function
 ***************************/

/**
 * @fn        array_range_min_strategy_construct
 * @brief     Constructor of the ArrayRangeMinStrategy
 * @param     strtgy Array Range Min Strategy
 * @param     first The first of the range
 * @param     last The last of the range
 * @return    No return value
 * @details   Constructor of the ArrayRangeMinStrategy.
 */
void 
array_range_min_strategy_construct(
	ArrayRangeMinStrategy* strtgy, 
	unsigned int first, 
	unsigned int last
)
{
	min_strategy_construct(&strtgy->base, array_range_min_strategy_min);
	strtgy->first = first;
	strtgy->last = last;
	strtgy->set_range = array_range_min_strategy_set_range;

	return;
}

/**
 * @fn        array_range_min_strategy_set_range
 * @brief     Set range of the ArrayRangeMinStrategy
 * @param     strtgy Array Range Min Strategy
 * @param     first The first of the range
 * @param     last The last of the range
 * @return    No return value
 * @details   Set range of the ArrayRangeMinStrategy.
 */
void 
array_range_min_strategy_set_range(
	ArrayRangeMinStrategy* strtgy, 
	unsigned int first, 
	unsigned int last
)
{
	strtgy->first = first;
	strtgy->last = last;

	return;
}

/**
 * @fn        array_range_min_strategy_min
 * @brief     Get the minimum value int the range
 * @param     min_strtgy ArrayRangeMinStrategy
 * @param     collection Array
 * @return    The minimum value int the range
 * @details   Get the minimum value int the range.
 */
void* 
array_range_min_strategy_min(
	void* min_strtgy, 
	void* const collection
)
{
	ArrayRangeMinStrategy* strtgy = (ArrayRangeMinStrategy*) min_strtgy;
	Array* const array = (Array* const) collection;
	unsigned int i;
	unsigned int lowest;

	lowest = strtgy->first;

	for (i = lowest + 1; i <= strtgy->last; i++) {
		if (0 > array->compare(array->comp_strtgy, array->get(array, i), array->get(array, lowest))) {
			lowest = i;
		}
	}

	return array->get(array, lowest);
}
