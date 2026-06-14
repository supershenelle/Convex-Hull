/**

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 06  (2 digits)

    DE GUZMAN, MAVRICK L.    S09
    NONO, SHENELLE ANDREA G. S09
    YATCO, MARCO ALFREDO D.  S09 

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
    b. Name of Tester(s)    :  Mavrick De Guzman
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function initializes the stack by setting the top value to 0. 
                It is used to create an empty stack
    e. Return: None
    f. Parameters: Stack *stack - a pointer to the stack that will be initialized
*/
void CREATE(Stack *stack)
{
    stack->top = 0; // initialize top value to 0
}

/*
    a. Name of Programmer(s):  Shenelle Andrea Nono
    b. Name of Tester(s)    :  Mavrick De Guzman
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function adds an element to the top of the stack. 
                It first checks if the stack is full, and if not, it increments the top value 
                and stores the element at the new top index.
    e. Return: None
    f. Parameters: Stack *stack - a pointer to the stack where the element will be added
                   Point elem - the element that will be added to the stack
*/
void PUSH(Stack *stack, Point elem)
{
    int x;

    if (ISFULL(stack))
        printf("Error: Stack Overflow Error!\n");
    
    else
    {
        stack->top++; // increment top to 1
        stack->points[stack->top] = elem; // store elem in 1
    }
}

/*
    a. Name of Programmer(s):  Shenelle Andrea Nono
    b. Name of Tester(s)    :  Mavrick De Guzman
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function removes and returns the top element of the stack. 
                It first checks if the stack is empty, and if not, it stores the top element in a 
                temporary variable and decrements the top value then returns the popped element.
    e. Return: Point - the element that was removed from the top of the stack
    f. Parameters: Stack *stack - a pointer to the stack from which the element will be removed
*/
Point POP(Stack *stack)
{
    Point temp; // temp that will store pop value

	if (stack->top == 0)
		printf("Error: Stack Underflow Error!\n");
	
	else
        temp = stack->points[stack->top];
		stack->top--; // decrement top
	
    return temp; // return popped value
}

/*
    a. Name of Programmer(s):  Shenelle Andrea Nono
    b. Name of Tester(s)    :  Mavrick De Guzman
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function checks if the stack is full by comparing the top value with 
                the defined STACK_SIZE. 
    e. Return: bool - true if the stack is full, false otherwise
    f. Parameters: Stack *stack - a pointer to the stack that will be checked if full
*/
bool ISFULL(Stack *stack)
{
	if (stack->top == STACK_SIZE)
		return true;
	
    else
        return false;
}

/*
    a. Name of Programmer(s):  Shenelle Andrea Nono
    b. Name of Tester(s)    :  Mavrick De Guzman
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function checks if the stack is empty by comparing the top value with 0.
    e. Return: bool - true if the stack is empty, false otherwise
    f. Parameters: Stack *stack - a pointer to the stack that will be checked if empty
*/
bool ISEMPTY(Stack *stack)
{
    if (stack->top == 0)
        return true;

    else
        return false;
}

/*
    a. Name of Programmer(s):  Shenelle Andrea Nono
    b. Name of Tester(s)    :  Mavrick De Guzman
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function returns the top element of the stack without removing it. 
                It first checks if the stack is empty, and if not, it returns the element at the top index.
    e. Return: Point - the top element of the stack
    f. Parameters: Stack *stack - a pointer to the stack that will be checked for the top element
*/
Point TOP(Stack *stack)
{
    if (stack->top == 0)
        printf("Error: Stack is empty\n");
    
    else
    return stack->points[stack->top];
}

/*
    a. Name of Programmer(s):  Shenelle Andrea Nono
    b. Name of Tester(s)    :  Mavrick De Guzman
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function returns the next to top element of the stack without removing it. 
                It first checks if the stack has at least two elements, and if not, it prints an error message. 
                If there are at least two elements, it returns the element at the index one less than the top index. 
    e. Return: Point - the next to top element of the stack
    f. Parameters: Stack *stack - a pointer to the stack that will be checked for the next to top element
*/
Point NEXT_TO_TOP(Stack *stack)
{
    if (stack->top < 2)
        printf("Error: Need at least two elements in the stack\n");
    
    else
    return stack->points[(stack->top)-1];
}