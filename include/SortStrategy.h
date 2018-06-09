/**
 * @file      SortStrategy.h
 * @brief     Sort Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(SORT_STRATEGY_H)
#define SORT_STRATEGY_H


/***************************
 * Type Definition
 ***************************/
typedef void (* Sort)(void* sort_strtgy, void* const collection);


/***************************
 * Structure
 ***************************/

/**
 * @struct    sort_strategy
 * @brief     Sort Strategy
 * @var       sort Sort function
 * @details   Interface of the Sort Strategy.
 */
/* interface */
struct sort_strategy {
	Sort sort;
};

typedef struct sort_strategy SortStrategy;


/***************************
 * Function prototype
 ***************************/
extern void sort_strategy_construct(SortStrategy* sort_strtgy, const Sort sort);

/* Due to the constraints of GCC, we created a function that returns a pointer to the sort function. */
extern Sort sort_strategy_func(SortStrategy* const sort_strtgy);


/***************************
 * Definition
 ***************************/
#define new_SortStrategy(sort) {(Sort) (sort)}


#endif /* SORT_STRATEGY_H */
