/**
 * @file      CompStrategy.c
 * @brief     Comparative Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include "CompStrategy.h"


/***************************
 * Function
 ***************************/

/**
 * @fn        comp_strategy_construct
 * @brief     Constructor of the CompStrategy
 * @param     comp_strtgy Comparative Strategy
 * @param     compare Comparison function
 * @return    No return value
 * @details   Constructor of the CompStrategy.
 */
void 
comp_strategy_construct(
	CompStrategy* comp_strtgy, 
	const Compare compare
)
{
	comp_strtgy->compare = compare;
	
	return;
}

/**
 * @fn        comp_strategy_func
 * @brief     Get Comparative Strategy compare function
 * @param     comp_strtgy Comparative Strategy
 * @return    Comparative Strategy compare function
 * @details   Get Comparative Strategy compare function.
 *            Due to the constraints of GCC, we created a function 
 *            that returns a pointer to the compare function.
 */
Compare 
comp_strategy_func(
	CompStrategy* const comp_strtgy
)
{
	return comp_strtgy->compare;
}
