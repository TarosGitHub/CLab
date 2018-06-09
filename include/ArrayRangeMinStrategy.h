/**
 * @file      ArrayRangeMinStrategy.h
 * @brief     Array Range Min Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(ARRAY_RANGE_MIN_STRATEGY_H)
#define ARRAY_RANGE_MIN_STRATEGY_H

#include "MinStrategy.h"


/***************************
 * Structure
 ***************************/

/**
 * @struct    array_range_min_strategy
 * @brief     Array Range Min Strategy
 * @var       base MinStrategy
 * @var       first The first of the range
 * @var       last The last of the range
 * @var       set_range Set range
 * @details   Interface of the Array Range Min Strategy.
 */
/* interface */
struct array_range_min_strategy {
	/* private */
	MinStrategy base;
	unsigned int first;
	unsigned int last;

	/* public */
	void (* set_range)(struct array_range_min_strategy* strtgy, unsigned int first, unsigned int last);
};

typedef struct array_range_min_strategy ArrayRangeMinStrategy;


/***************************
 * Function prototype
 ***************************/
extern void array_range_min_strategy_construct(ArrayRangeMinStrategy* strtgy, unsigned int first, unsigned int last);
extern void array_range_min_strategy_set_range(ArrayRangeMinStrategy* strtgy, unsigned int first, unsigned int last);
extern void* array_range_min_strategy_min(void* min_strtgy, void* const collection);


/***************************
 * Definition
 ***************************/
#define new_ArrayRangeMinStrategy(                  \
	first,                                          \
	last                                            \
)                                                   \
{                                                   \
	new_MinStrategy(array_range_min_strategy_min),  \
	(unsigned int) (first),                         \
	(unsigned int) (last),                          \
	(array_range_min_strategy_set_range)            \
}


#endif /* ARRAY_RANGE_MIN_STRATEGY_H */
