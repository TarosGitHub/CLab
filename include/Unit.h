/**
 * @file      Unit.h
 * @brief     Unit Class
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#if !defined(UNIT_H)
#define UNIT_H


/***************************
 * Definition
 ***************************/

/**
 * @def       BIT_PER_BYTE
 * @brief     bit / byte
 * @details   Number of bits per byte.
 */
#define BIT_PER_BYTE 8


/***************************
 * Function
 ***************************/

/**
 * @fn        unit_conv_bit_to_byte
 * @brief     bit -> byte
 * @param     bit_value Bit value
 * @return    Byte value
 * @details   Convert bits to bytes.
 */
#define unit_conv_bit_to_byte(  \
	bit_value                   \
)                               \
(                               \
	(bit_value) / BIT_PER_BYTE  \
)

/**
 * @fn        unit_conv_byte_to_bit
 * @brief     byte -> bit
 * @param     byte_value Byte value
 * @return    Bit value
 * @details   Convert bytes to bits.
 */
#define unit_conv_byte_to_bit(   \
	byte_value                   \
)                                \
(                                \
	(byte_value) * BIT_PER_BYTE  \
)


#endif /* UNIT_H */
