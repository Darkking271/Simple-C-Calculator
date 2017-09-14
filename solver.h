//
// Created by Alex on 9/11/2017.
//

#ifndef UNTITLED_SOLVER_H
#define UNTITLED_SOLVER_H

/** addition
 * Takes two ints, and returns their sum.
 * @param a
 * @param b
 * @return a + b
 */
int addition(int a, int b);

/** subtraction
 * Takes two ints, and returns their difference.
 * @param a
 * @param b
 * @return a - b
 */
int subtraction(int a, int b);

/** multiplication
 * Takes two ints, and returns their product.
 * @param a
 * @param b
 * @return a * b
 */
int multiplication(int a, int b);

/** division
 * Takes two ints, and returns their quotient.
 * @param a
 * @param b
 * @return a/b
 */
int division(int a, int b);

/** collatz_sequence
 * Takes a positive int, and prints it's collatz sequence
 * 15 numbers per line.
 * @param num
 */
void collatz_sequence(int num);

/** format
 * Takes a count, and checks if number is multiple of 15.
 * It increments the number, if the number is a multiple,
 * it prints a new line. Finally, it returns the incremented
 * count.
 * @param count
 * @return count++
 */
int format(int count);

#endif //UNTITLED_SOLVER_H
