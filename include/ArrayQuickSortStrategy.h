/**
 * @file      ArrayQuickSortStrategy.h
 * @brief     Array Quick Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(ARRAY_QUICK_SORT_STRATEGY_H)
#define ARRAY_QUICK_SORT_STRATEGY_H

#include "SortStrategy.h"


/***************************
 * Structure
 ***************************/

/**
 * @struct    array_quick_sort_strategy
 * @brief     Array Quick Sort Strategy
 * @var       base SortStrategy
 * @details   Interface of the Array Quick Sort Strategy.
 */
/* interface */
struct array_quick_sort_strategy {
	SortStrategy base;
};

typedef struct array_quick_sort_strategy ArrayQuickSortStrategy;


/***************************
 * Function prototype
 ***************************/
extern void array_quick_sort_strategy_construct(ArrayQuickSortStrategy* sort_strtgy);
extern void array_quick_sort_strategy_sort(void* sort_strtgy, void* const collection);


/***************************
 * Definition
 ***************************/
#define new_ArrayQuickSortStrategy() {new_SortStrategy(array_quick_sort_strategy_sort)}


#endif /* ARRAY_QUICK_SORT_STRATEGY_H */
