/**

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 00  (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

    PURPOSE OF THIS FILE: to show an example of a C source file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/

#include <stdio.h>
#include <stdlib.h>

// include your own stack header file
#include "stack.h"
#include "stdbool.h"


/*
    EACH FUNCTION DEFINITION MUST BE PRECEDED BY A INLINE DOCUMENTATION CONTAINING THE FOLLOWING:

    a. Name of Programmer(s)
    b. Name of Tester(s) -- for an unbiased black box testing, the tester should NOT be the same person as the programmer.
    c. Code Type -- indicate EXPLICITLY if the code is one of the following: 100% Human Generated code, 100% AI Generated code
       or a modified AI generated code.  If it is a modified AI generated code, indicate explicitly which lines were 
       modified and the reason why a line of code had to be modified.
    d. Purpose -- indicate the purpose of the function
    e. Return -- indicate what will be returned (type None for void functions)
    f. Parameters -- indicate the nature of the parameters

    An example is shown below.  

    Remove the Sample() function in your own C source code.
*/


/*
    a. Name of Programmer(s):  Shenelle Andrea Nono
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will ....
    e. Return: None
    f. Parameters: x is the ...    
*/
void CREATE(Stack *stack)
{
    stack->top = 0; // initialize top value to 0
}

void PUSH(Stack *stack, Point elem)
{
    int x;

    if (ISFULL(stack))
        printf("Error: Stack Overflow Error!\n");
    
    else
    {
        stack->top++; // increment top to 1
        stack->coords[stack->top] = elem; // store elem in 1
    }
}

Point POP(Stack *stack)
{
    Point temp; // temp that will store pop value

	if (stack->top == 0)
		printf("Error: Stack Underflow Error!\n");
	
	else
        temp = stack->coords[stack->top];
		stack->top--; // decrement top
	
    return temp; // return popped value
}

bool ISFULL(Stack *stack)
{
	if (stack->top == STACK_SIZE)
		return true;
	
    else
        return false;
}

bool ISEMPTY(Stack *stack)
{
    if (stack->top == 0)
        return true;

    else
        return false;
}

Point TOP(Stack *stack)
{
    if (stack->top == 0)
        printf("Error: Stack is empty\n");
    
    else
    return stack->coords[stack->top];
}

Point NEXT_TO_TOP(Stack *stack)
{
    if (stack->top < 2)
        printf("Error: Need at least two elements in the stack\n");
    
    else
    return stack->coords[(stack->top)-1];
}

// test notes: implement test-stack.c, verify if no bugs