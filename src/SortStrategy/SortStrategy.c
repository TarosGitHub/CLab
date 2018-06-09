/**
 * @file      SortStrategy.c
 * @brief     Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "SortStrategy.h"


/***************************
 * Function
 ***************************/

/**
 * @fn        sort_strategy_construct
 * @brief     Constructor of the SortStrategy
 * @param     sort_strtgy Sort Strategy
 * @param     sort Sort function
 * @return    No return value
 * @details   Constructor of the SortStrategy.
 */
void 
sort_strategy_construct(
	SortStrategy* sort_strtgy, 
	const Sort sort
)
{
	sort_strtgy->sort = sort;
	
	return;
}

/**
 * @fn        sort_strategy_func
 * @brief     Get Sort Strategy sort function
 * @param     sort_strtgy Sort Strategy
 * @return    Sort Strategy sort function
 * @details   Get Sort Strategy sort function.
 *            Due to the constraints of GCC, we created a function 
 *            that returns a pointer to the sort function.
 */
Sort 
sort_strategy_func(
	SortStrategy* const sort_strtgy
)
{
	return sort_strtgy->sort;
}
