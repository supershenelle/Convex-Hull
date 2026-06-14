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

#include <stdlib.h>

// include your own stack C source file
#include "stack.c"
#include "stdbool.h"

int main()
{
    Stack stack;
    Point elem;

    // -----------------------------------------------------------------------------------------
    printf("--- MAIN NEEDED CODE FOR MCO ----------------------\n");
    // 1. CREATE where ISEMPTY should return true
    CREATE(&stack);

    if (ISEMPTY(&stack))
        printf("1. CREATE - PASSED\n");
    else
        printf("1. CREATE - FAILED\n");

    // 2. PUSH return TOP and NEXT TO TOP VALUES
    Point p1 = {10.0, 0.0}; // assume na ito ung values??? tama ba sa x ilalagay...
    Point p2 = {20.0, 0.0};
    Point p3 = {30.0, 0.0};

    PUSH(&stack, p1);
    PUSH(&stack, p2);
    PUSH(&stack, p3);

    // prinint ko nalang ung x kasi di ko alam kung tama b .. 
    printf("TOP should be 30: %.1f\n", TOP(&stack).x);
    printf("NEXT_TO_TOP should be 20: %.1f\n", NEXT_TO_TOP(&stack).x);
    // -----------------------------------------------------------------------------------------

    Stack s;
    printf("\n--- ADDITIONAL TESTS FOR FUNCTIONS -------------------\n");
    printf("Test 1 : CREATE\n");
    CREATE(&s);
    if (ISEMPTY(&s))
        printf("Empty = TRUE\n");
    else
        printf("Empty = FALSE\n");

    printf("\nTest 2 : PUSH (push 10)\n");
    PUSH(&s, p1);
    if (TOP(&s).x == p1.x)
        printf("Top = %f\n", TOP(&s).x);
    else
        printf("Top = FAILED\n");

    printf("\nTest 3 : NEXT TO TOP (push 20)\n");
    PUSH(&s, p2);
    if (NEXT_TO_TOP(&s).x == p1.x)
        printf("Next to Top = %f\n", TOP(&s).x);
    else
        printf("Next to Top = FAILED\n");

    printf("\nTest 4 : POP (pop 20)\n");
    Point test = POP(&s);
    if (test.x == p2.x && TOP(&s).x == p1.x)
        printf("Pop = %f\nTop = %f\n", test.x, TOP(&s).x);
    else
        printf("Pop = FAILED\n");

    printf("\nTest 5 : ISEMPTY (pop 10)\n");
    test = POP(&s);
    if (test.x == p1.x && ISEMPTY(&s))
        printf("Pop = %f\nIs Empty = %s\n", test.x, ISEMPTY(&s) ? "TRUE" : "FALSE");
    else
        printf("Is Empty = FAILED\n");

    printf("\nTest 6 : POP on empty stack\n");
    POP(&s); // should print error message

    printf("\nTest 7 : TOP on empty stack\n");
    TOP(&s); // should print error message

    printf("\nTest 8 : NEXT TO TOP with one element\n");
    PUSH(&s, p1);
    NEXT_TO_TOP(&s); // should print error message

    printf("\nTest 9 : Fill stack with 32768 elements\n");
    for (int i = 0; i < STACK_SIZE; i++)
    {
        PUSH(&s, p1); // pushing same point lang para mafill stack  
    }
    if (ISFULL(&s))
        printf("Is Full = PASSED\n");
    else
        printf("Is Full = FAILED\n");

    printf("\nTest 10 : PUSH when stack is full\n");
    PUSH(&s, p1); // should print error message

    return 0;
}


