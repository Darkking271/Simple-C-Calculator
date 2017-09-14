Author: Aleksandr Voytovich
Studen id: avoytovi

This is a simple calculator implemented in the C programming language. It takes a simple command followed by two
arguments, ex. "sum 3 2" or "div 6 3". It uses the command, as well as the arguments to calculate a result for the 
user, then it diplays the result. The program also allows for chaining commands, meaning the second argument can be 
another equation, ex. "sum 5 (mul 3 (div 8 (sub 4 2)))". This program will also handle input as well as calclation 
errors. It will detect any errors in the input, as well as if the user tries to divide by 0.

Possible inputs:
- "sum 3 10"
- "mul 4 12"
- "div 12 (mul 3 2)"
- "sum 14 (mul 2 (div 12 (sub 12 6)))"
- "col 100"

Example of improper input:
- "mul 2 (sub 4)"
- "add 3 (sum 4 5)"
- "div 10 (mul 5 2)"
- "div 20 (col 12)"

To chain equations, the program uses recursive functions to build a stack as well as solve the stack's values. To
build the stack's, the program parses the users input using the "bool check(char input[100], eq *equation, bool head)"
function. It will take input, and build the stack off of the information given. If the type, is col, it will do this
once, and return true or false if the input from the user was correct. Any other command, the function will check for
any paranthesis entered. If a right paranthesis is found after the first parameter, the function will recurse. Also, 
if col is found as a command within a parenthesis, the function will return false, and an error will display. Any
improper input the user enters, the funciton will detect, and return false. If the function parses properly, it will
return true, indicating to the main function that the input was correct, the stack is built, and is ready to be 
parsed. 
The next function is the "int parse(eq *equation, opt *option)". This function will take the the stack, and begin to
evaluate the result. It uses something similar to the recursive decent parser, where it continues to move further into
the stack, until it reaches the end. From there, it will evaulate the result, and return it. If the function recursed,
it will pass the function to the preceding call of the function. If there is an instance where division by 0 occurs,
option will be sent to false, and the function continues until it it done. Once complete, the function will return the
result into the option structure, and if the option is true, the result is printed, otherwise an error message will
print instead.