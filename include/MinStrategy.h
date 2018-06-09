/**
 * @file      MinStrategy.h
 * @brief     Min Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(MIN_STRATEGY_H)
#define MIN_STRATEGY_H


/***************************
 * Type Definition
 ***************************/
typedef void* (* Min)(void* min_strtgy, void* const collection);


/***************************
 * Structure
 ***************************/

/**
 * @struct    min_strategy
 * @brief     Min Strategy
 * @var       min Min function
 * @details   Interface of the Min Strategy.
 */
/* interface */
struct min_strategy {
	Min min;
};

typedef struct min_strategy MinStrategy;


/***************************
 * Function prototype
 ***************************/
extern void min_strategy_construct(MinStrategy* min_strtgy, const Min min);

/* Due to the constraints of GCC, we created a function that returns a pointer to the min function. */
extern Min min_strategy_func(MinStrategy* const min_strtgy);


/***************************
 * Definition
 ***************************/
#define new_MinStrategy(min) {(Min) (min)}


#endif /* MIN_STRATEGY_H */
