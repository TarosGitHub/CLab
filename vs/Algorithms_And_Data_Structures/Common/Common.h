#if !defined(COMMON_H)
#define COMMON_H

/**
 * Boolean type.
 */
enum Boolean {
	FALSE, /**< False is zero. */
	TRUE /**< True is not zero. */
};

/**
 * Gets the minimum value.
 *
 * @param x A value.
 * @param y Another value.
 * @return Return the smaller of x and y. If x equals y, return y.
 */
#define min(x, y) ((x) < (y) ? (x) : (y))

#endif
