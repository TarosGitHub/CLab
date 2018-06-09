/**
 * @file      Math.h
 * @brief     Math Class
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(MATH_H)
#define MATH_H

#define math_min(first, second) ((first) < (second) ? (first) : (second))
#define math_max(first, second) ((first) > (second) ? (first) : (second))
#define math_abs(value) ((value) < 0 ? -(value) : (value))

#endif /* MATH_H */
