/**
 * @file      ArrayBubbleSortStrategy.h
 * @brief     Array Bubble Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(ARRAY_BUBBLE_SORT_STRATEGY_H)
#define ARRAY_BUBBLE_SORT_STRATEGY_H

#include "SortStrategy.h"


/***************************
 * Structure
 ***************************/

/**
 * @struct    array_bubble_sort_strategy
 * @brief     Array Bubble Sort Strategy
 * @var       base SortStrategy
 * @details   Interface of the Array Bubble Sort Strategy.
 */
/* interface */
struct array_bubble_sort_strategy {
	SortStrategy base;
};

typedef struct array_bubble_sort_strategy ArrayBubbleSortStrategy;


/***************************
 * Function prototype
 ***************************/
extern void array_bubble_sort_strategy_construct(ArrayBubbleSortStrategy* sort_strtgy);
extern void array_bubble_sort_strategy_sort(void* sort_strtgy, void* const collection);


/***************************
 * Definition
 ***************************/
#define new_ArrayBubbleSortStrategy() {new_SortStrategy(array_bubble_sort_strategy_sort)}


#endif /* ARRAY_BUBBLE_SORT_STRATEGY_H */
