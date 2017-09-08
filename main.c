#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct command{
    char cmd[3];
    int arg1;
    int arg2_num;
    struct command *arg2_cmd;
    struct command *prev;
}type;

bool check(char input[100]);
void parse(char input[100], type * equation);
char *get_command(char string[100]);

int main() {
    char input[100];
    printf("avoytovi>$ ");
    scanf("%s", input);
    while(strcmp(input, "bye") != 0){
        type *equation = malloc(sizeof(type));
        bool valid = check(input);
        parse(input, equation);


        printf("avoytovi>$ ");
        scanf("%s", input);
    }
}

bool check(char input[100]){

}

void parse(char input[100], type *equation){

}

char *get_command(char string[100]){
    static char cmd[3];
    cmd[0] = string[0]; cmd[1] = string[1]; cmd[2] = string[2];
    return cmd;
}

