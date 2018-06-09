/**
 * @file      ArraySelectSortStrategy.h
 * @brief     Array Select Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(ARRAY_SELECT_SORT_STRATEGY_H)
#define ARRAY_SELECT_SORT_STRATEGY_H

#include "SortStrategy.h"


/***************************
 * Structure
 ***************************/

/**
 * @struct    array_select_sort_strategy
 * @brief     Array Select Sort Strategy
 * @var       base SortStrategy
 * @details   Interface of the Array Select Sort Strategy.
 */
/* interface */
struct array_select_sort_strategy {
	SortStrategy base;
};

typedef struct array_select_sort_strategy ArraySelectSortStrategy;


/***************************
 * Function prototype
 ***************************/
extern void array_select_sort_strategy_construct(ArraySelectSortStrategy* sort_strtgy);
extern void array_select_sort_strategy_sort(void* sort_strtgy, void* const collection);


/***************************
 * Definition
 ***************************/
#define new_ArraySelectSortStrategy() {new_SortStrategy(array_select_sort_strategy_sort)}


#endif /* ARRAY_SELECT_SORT_STRATEGY_H */
