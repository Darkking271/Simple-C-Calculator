//
// Created by Alex on 9/11/2017.
//

#include <stdio.h>
#include "solver.h"

int addition(int a, int b){ return a + b;   }

int subtraction(int a, int b){  return a - b;   }

int multiplication(int a, int b){return a * b;  }

int division(int a, int b){ return a / b;    }

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

int format(int count){
    count++;
    if((count + 1) % 15 == 0)
        printf("\n");
    return count;
}

