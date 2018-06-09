/**
 * @file      MinStrategy.c
 * @brief     Min Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "MinStrategy.h"


/***************************
 * Function
 ***************************/

/**
 * @fn        min_strategy_construct
 * @brief     Constructor of the MinStrategy
 * @param     min_strtgy Min Strategy
 * @param     min Min function
 * @return    No return value
 * @details   Constructor of the MinStrategy.
 */
void 
min_strategy_construct(
	MinStrategy* min_strtgy, 
	const Min min
)
{
	min_strtgy->min = min;
	
	return;
}

/**
 * @fn        min_strategy_func
 * @brief     Get Min Strategy min function
 * @param     min_strtgy Min Strategy
 * @return    Min Strategy min function
 * @details   Get Min Strategy min function.
 *            Due to the constraints of GCC, we created a function 
 *            that returns a pointer to the min function.
 */
Min 
min_strategy_func(
	MinStrategy* const min_strtgy
)
{
	return min_strtgy->min;
}
