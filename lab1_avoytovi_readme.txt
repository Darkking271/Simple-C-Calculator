Author:     Aleksandr Voytovich
Student id: avoytovi
date:       09/15/2017
class:      CSC-322

This is a simple calculator implemented in the C programming language. It takes a simple command followed by two
arguments, ex. "sum 3 2" or "div 6 3". It uses the command, as well as the arguments to calculate a result for the 
user, then it displays the result. The program also allows for chaining commands, meaning the arguments can be
another equation, ex. "sum (mul 2 5) (div 4 (sum 1 1))". This program will also handle input as well as calculation
errors. It will detect any errors in the input, as well as if the user tries to divide by 0.

Possible inputs:
- "sum 3 10"
- "mul (sum 1 2) 12"
- "div 12 (mul 3 2)"
- "sum (mul 2 (sum 11)) (mul (sub 3 2) 1)"
- "col 100"

Example of improper input:
- "mul 2 (sub 4)"
- "add 3 (sum 4 5)"
- "div (2 5) 10"
- "div 20 (col 12)"

The program uses two primary functions to process the user's input, as well as evaluate the value. The program parses
the input using string patterns. It will construct an equation tree as it builds. If argument is another equation, it
will recursively parse it, building children onto the root of the equation. This function will also evaluate any
incorrect input, and break out of the function if issues are found. Once built, the tprogram will then traverse the tree,
and evaluate the arguments of each node. If there is an instance of division by 0, the option structure will be set to
false. If the main method detects that the option is false, it will print an error message. Finally, after the
evaluation, the program frees the equation tree, and loops for further user input.

Demo:
avoytovi>$ sum 4 5
9
avoytovi>$ div 8 4
2
avoytovi>$ mul 1 2
2
avoytovi>$ sub 10 7
3
avoytovi>$ sum (mul 2 5) (div 4 2)
12
avoytovi>$ sum (mul (div (sub 12 6) 2) 3) (mul 2 3)
15
avoytovi>$ col 200
200 100 50 25 76 38 19 58 29 88 44 22 11 34 17
52 26 13 40 20 10 5 16 8 4 2 1
avoytovi>$ col 300
300 150 75 226 113 340 170 85 256 128 64 32 16 8 4
2 1
avoytovi>$ sum 3 b
Not a valid input!
avoytovi>$ bye
Goodbye!