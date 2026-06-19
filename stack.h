/*

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 06 (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

    PURPOSE OF THIS FILE: to show an example of a C header file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS:
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    3. Do NOT use global variables!  NON-COMPLIANCE WILL RESULT INTO A 10 POINT DEDUCTION!
*/

/*
    You may encode any of the following below this comment the following:   
    1. #define directives
    2. typedef alias(es) 
    3. declaration of your user-defined struct data type(s)
    4. typedef alias(es) for your struct data type(s) -- you have to put an inline comment 
       for each struct member as part of the documentation. 

    The header should NOT include the codes for any function definitions.  

    Function definitions should be encoded in your C source file only!
*/

#include <stdio.h>
#include <stdlib.h>

// you may include other header files
#include <stdbool.h>

#ifndef STACK_H
#define STACK_H
#define STACK_SIZE 32768

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[STACK_SIZE+1];
    int top;
} Stack;

bool ISFULL(Stack *stack);
bool ISEMPTY(Stack *stack);
void CREATE(Stack *stack);
void PUSH(Stack *stack, Point elem);
Point POP(Stack *stack);
Point TOP(Stack *stack);
Point NEXT_TO_TOP(Stack *stack);

/*
void Push(int a[], int *top);
double Pop(int a[], int *top);
bool isFull(int *top);
bool isEmpty(int *top);
double Top(int a[], int *top);
double nextToTop(int a[], int *top);
*/

#endif