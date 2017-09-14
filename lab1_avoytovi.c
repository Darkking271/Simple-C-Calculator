/**Simple-C-Calculator
 * Author: Aleksandr Voytovich (avoytovi)
 *
 * This is a simple calculator written in C. The user gives the program a command, with a parameter. The command can be
 * one of 5, sum, sub, mul, div, and col. Sum gives you the sum of two numbers. Sub gives you the difference of two
 * numbers. Mul gives you the product of two numbers. Div gives you the quotient of two numbers. Finally, col displays
 * the collatz sequence of a positive number. These commands can also be chained together. For example, say you want to
 * find 5 * (3 + 4). You could enter "mul 5 (sum 3 4)". The program also actively checks for validity of the input. So if
 * "mul 4 (sum 4)" or "sum 1 (col 23)" were to be entered, the program would simply tell the user that the input is
 * invalid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/** equation struct
 * Simple structure for storing the users input equation. The structure holds, the command, the first argument, and the
 * second argument as either an int, or a pointer to another allocated equation struct.
 * The structure is typedefined as eq.
 */
typedef struct Equation{
    int cmd;
    int arg1;
    int arg2_num;
    struct Equation *arg2_cmd;
}eq;

/** option struct
 * Simple structure for division validation. If an instance of dividing by 0 occurs, the option will be set to false,
 * and upon checking the option, if true, the result will print, if false, an error message will apear.
 * The structure is typedefined as opt.
 */
typedef struct Option{
    int result;
    bool option;
}opt;

bool check(char input[100], eq *equation, bool head);
int parse(eq *equation, opt *option);
int get_type(char in[100]);
void collatz_sequence(int num);
int format(int count);

/** main
 * The main method of the C calculator. Takes the input from the user, checks and parses it, and displays the result.
 * The program continues to take input from the user until "bye" is entered. The program then quits and returns 0.
 * @return 0
 */
int main() {
    char input[100] = {'\0'};
    printf("avoytovi>$ ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    opt *option = malloc(sizeof(opt));

    while(strcmp(input, "bye") != 0){

        eq *equation = malloc(sizeof(eq));
        option->option = true;

        if(check(input, equation, true)){
            if(equation->cmd == 5)
                collatz_sequence(equation->arg1);
            else {
                option->result = parse(equation, option);
                if(option->option)
                    printf("%d\n", option->result);
                else printf("Cannot divide by 0!\n");
            }
        }else{
            printf("Not a valid input!\n");
            parse(equation, option);//used to free any built structures
        }

        memset(input, 0, sizeof(input));
        printf("avoytovi>$ ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

    }printf("Goodbye\n");
    free(option);
    return 0;
}

/** check
 * A function to take the input, as well as a structure that has been allocated in memeory, and whether the structere
 * given is the head of the linked list or not. The program parses the input, while building the linked list, and
 * checking validity of the input. It runs recursively if the input from the user is a chained equation such as
 * "mul 5 (sum 3 4)".
 * @param input
 * @param equation
 * @param head
 * @return valid
 */
bool check(char input[100], eq *equation, bool head){
    char num[30] = {'\0'};
    int type = get_type(input);
    memmove(input, input+4, strlen(input));//removes first 4 elements of string
    if(type == 5 && head){

        for(int i = 0; i < strlen(input); ++i){
            if(isdigit(input[i]))
                num[i] = input[i];
            else return false;
        }
        equation->cmd = type;
        equation->arg1 = atoi(num);
        if(equation->arg1 < 0)
            return false;
        else return true;

    }else if(type == 1 || type == 2 || type == 3 || type == 4){

        for(int i = 0; i < strlen(input); ++i) {
            if (isdigit(input[i]))
                num[i] = input[i];
            else if (input[i] == ' ') {
                memmove(input, input + i + 1, strlen(input));
                break;
            } else return false;
        }
        equation->cmd = type;
        equation->arg1 = atoi(num);
        if(input[0] == '('){
            memmove(input, input + 1, strlen(input));

            if(input[strlen(input) - 1] == ')')
                input[strlen(input) - 1] = '\0';
            else return false;

            equation->arg2_cmd = malloc(sizeof(eq));
            if(check(input, equation->arg2_cmd, false))
                return true;
        }else{
            memset(num, 0, sizeof(num));
            for(int i = 0; i < strlen(input); ++i){
                if(isdigit(input[i]))
                    num[i] = input[i];
                else return false;
            }
            equation->arg2_num = atoi(num);
            return true;
        }

    }else if(type == 0){
        return false;
    }

    return false;
}

/** parse
 * A function to take the linked list built in the check function, and calculates the result. It runs recursively if
 * the input from the user was chained, such as "mul 5 (sum 3 4)". The function also frees the allocated linked list
 * as it ascends from the recursion.
 * @param equation
 * @return result
 */
int parse(eq *equation, opt *option){
    if(equation->arg2_cmd != NULL){
        equation->arg2_num = parse(equation->arg2_cmd, option);
    }
    int type = equation->cmd, arg1 = equation->arg1, arg2 = equation->arg2_num;
    free(equation);

    if(type == 4 && arg2 == 0){ //Handler for division by 0
        option->option = false;
        return 0;
    }else{
        switch(type){
            case 1: return arg1 + arg2;//addition(arg1, arg2);
            case 2: return arg1 - arg2;//subtraction(arg1, arg2);
            case 3: return arg1 * arg2;//multiplication(arg1, arg2);
            case 4: return arg1 / arg2;//division(arg1, arg2);
            default: return 0;
        }
    }
}

/** get_type
 * This function takes the users input, and checks what command the user input. It returns 1 for sum, 2 for sub, 3 for
 * mul, 4 for div, and 5 for col. If the input from the user is not recognized, the function returns 0.
 * @param in
 * @return type
 */
int get_type(char in[100]){
    if(in[0] == 's' && in[1] == 'u' && in[2] == 'm')     //sum = 1
        return 1;
    else if(in[0] == 's' && in[1] == 'u' && in[2] == 'b')//sub = 2
        return 2;
    else if(in[0] == 'm' && in[1] == 'u' && in[2] == 'l')//mul = 3
        return 3;
    else if(in[0] == 'd' && in[1] == 'i' && in[2] == 'v')//div = 4
        return 4;
    else if(in[0] == 'c' && in[1] == 'o' && in[2] == 'l')//col = 5
        return 5;
    else return 0;                                       //unrecognized = 0
}

/** collatz_sequence
 * Takes a positive int, and prints it's collatz sequence
 * 15 numbers per line.
 * @param num
 */
void collatz_sequence(int num){
    printf("%d ", num);
    int count = 0;
    while(num!= 1){
        if(num % 2 == 0){
            num /= 2;
            printf("%d ", num);
            count = format(count);
        }else{
            num = num * 3 + 1;
            printf("%d ", num);
            count = format(count);
        }
    }printf("\n");
}

/** format
 * Takes a count, and checks if number is multiple of 15.
 * It increments the number, if the number is a multiple,
 * it prints a new line. Finally, it returns the incremented
 * count.
 * @param count
 * @return count++
 */
int format(int count){
    count++;
    if((count + 1) % 15 == 0)
        printf("\n");
    return count;
}
