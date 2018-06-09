/**
 * @file      CompStrategy.h
 * @brief     Comparative Strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(COMP_STRATEGY_H)
#define COMP_STRATEGY_H


/***************************
 * Type Definition
 ***************************/
typedef int (* Compare)(void* comp_strtgy, const void* first, const void* second);


/***************************
 * Structure
 ***************************/

/**
 * @struct    comp_strategy
 * @brief     Comparative Strategy
 * @var       compare Comparison function
 * @details   Interface of the Comparative Strategy.
 */
/* interface */
struct comp_strategy {
	Compare compare;
};

typedef struct comp_strategy CompStrategy;


/***************************
 * Function prototype
 ***************************/
extern void comp_strategy_construct(CompStrategy* comp_strtgy, const Compare compare);

/* Due to the constraints of GCC, we created a function that returns a pointer to the compare function. */
extern Compare comp_strategy_func(CompStrategy* const comp_strtgy);


/***************************
 * Definition
 ***************************/
#define new_CompStrategy(compare) {(Compare) (compare)}

/* Ascending */
#define template_compare_asce(type, func_name)  \
int func_name(                                  \
	void* cmp_strtgy,                           \
	const void* first,                          \
	const void* second                          \
)                                               \
{                                               \
	const type* f = (const type*) first;        \
	const type* s = (const type*) second;       \
	int result;                                 \
	                                            \
	if (*f < *s) {                              \
		result = -1;                            \
	}                                           \
	else if (*s < *f) {                         \
		result = 1;                             \
	}                                           \
	else {                                      \
		result = 0;                             \
	}                                           \
	                                            \
	return result;                              \
}

/* Descending */
#define template_compare_desc(type, func_name)  \
int func_name(                                  \
	void* cmp_strtgy,                           \
	const void* first,                          \
	const void* second                          \
)                                               \
{                                               \
	const type* f = (const type*) first;        \
	const type* s = (const type*) second;       \
	int result;                                 \
	                                            \
	if (*f < *s) {                              \
		result = 1;                             \
	}                                           \
	else if (*s < *f) {                         \
		result = -1;                            \
	}                                           \
	else {                                      \
		result = 0;                             \
	}                                           \
	                                            \
	return result;                              \
}


#endif /* COMP_STRATEGY_H */
