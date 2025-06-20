#ifndef __DELAYS_H
#define __DELAYS_H

#define Delay1TCY() Nop() 

/* Delay of exactly 10 Tcy */
#define Delay10TCY() Delay10TCYx(1)

/* Delay10TCYx
 * Delay multiples of 10 Tcy
 * Passing 0 (zero) results in a delay of 2560 cycles.
 * The 18Cxxx version of this function supports the full range [0,255]
 * The 17Cxxx version supports [2,255] and 0.
 */
void Delay10TCYx(char delay);

/* Delay100TCYx
 * Delay multiples of 100 Tcy
 * Passing 0 (zero) results in a delay of 25,600 cycles.
 * The full range of [0,255] is supported.
 */
void Delay100TCYx(char delay);

/* Delay1KTCYx
 * Delay multiples of 1000 Tcy
 * Passing 0 (zero) results in a delay of 256,000 cycles.
 * The full range of [0,255] is supported.
 */
void Delay1KTCYx(char delay);

/* Delay10KTCYx
 * Delay multiples of 10,000 Tcy
 * Passing 0 (zero) results in a delay of 2,560,000 cycles.
 * The full range of [0,255] is supported.
 */
void Delay10KTCYx(char delay);

#endif
