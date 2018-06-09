/**
 * @file      Library.h
 * @brief     Library Class
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(LIBRARY_H)
#define LIBRARY_H

#include <assert.h>
#include <string.h>


/* assert.h */
#define lib_assert(expression) assert(expression)


/* string.h */
#define lib_memset(dst, character, size) memset((dst), (character), (size))
#define lib_memcpy(dst, src, size) memcpy((dst), (src), (size))


#endif /* LIBRARY_H */
