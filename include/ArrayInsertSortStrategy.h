/**
 * @file      ArrayInsertSortStrategy.h
 * @brief     Array Insert Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(ARRAY_INSERT_SORT_STRATEGY_H)
#define ARRAY_INSERT_SORT_STRATEGY_H

#include "SortStrategy.h"


/***************************
 * Structure
 ***************************/

/**
 * @struct    array_insert_sort_strategy
 * @brief     Array Insert Sort Strategy
 * @var       base SortStrategy
 * @details   Interface of the Array Insert Sort Strategy.
 */
/* interface */
struct array_insert_sort_strategy {
	SortStrategy base;
};

typedef struct array_insert_sort_strategy ArrayInsertSortStrategy;


/***************************
 * Function prototype
 ***************************/
extern void array_insert_sort_strategy_construct(ArrayInsertSortStrategy* sort_strtgy);
extern void array_insert_sort_strategy_sort(void* sort_strtgy, void* const collection);


/***************************
 * Definition
 ***************************/
#define new_ArrayInsertSortStrategy() {new_SortStrategy(array_insert_sort_strategy_sort)}


#endif /* ARRAY_INSERT_SORT_STRATEGY_H */
