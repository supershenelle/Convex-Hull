/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 00  (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

    PURPOSE OF THIS FILE: to show an example of a test driver program.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/

#include <stdlib.h>

// include your own stack C source file
#include "stack.c"

/*
=========================================================
STACK MODULE TEST CASES
=========================================================

+----+----------------------------------+--------------------------+----------------------+
| TC | Operation                        | Expected Result          | Expected Output      |
+----+----------------------------------+--------------------------+----------------------+
| 1  | CREATE(S)                        | Stack created            | Stack is empty       |
|    | ISEMPTY(S)                       | Returns 1 (true)         | Empty = 1            |
+----+----------------------------------+--------------------------+----------------------+
| 2  | PUSH(S, 10)                      | 10 added to stack        | Top = 10             |
|    | TOP(S)                           | Returns 10              | Top = 10             |
+----+----------------------------------+--------------------------+----------------------+
| 3  | PUSH(S, 20)                      | 20 added to stack        | Top = 20             |
|    | PUSH(S, 30)                      | 30 added to stack        | Top = 30             |
|    | TOP(S)                           | Returns 30              | Top = 30             |
+----+----------------------------------+--------------------------+----------------------+
| 4  | NEXT_TO_TOP(S)                   | Returns 20              | Next-to-top = 20     |
+----+----------------------------------+--------------------------+----------------------+
| 5  | POP(S)                           | Removes and returns 30   | Popped = 30          |
|    | TOP(S)                           | Returns 20              | Top = 20             |
+----+----------------------------------+--------------------------+----------------------+
| 6  | POP(S)                           | Removes 20              | Popped = 20          |
|    | POP(S)                           | Removes 10              | Popped = 10          |
|    | ISEMPTY(S)                       | Returns 1 (true)         | Empty = 1            |
+----+----------------------------------+--------------------------+----------------------+
| 7  | POP(S) on empty stack            | Underflow error          | Error message        |
+----+----------------------------------+--------------------------+----------------------+
| 8  | TOP(S) on empty stack            | Invalid operation        | Error message        |
+----+----------------------------------+--------------------------+----------------------+
| 9  | PUSH(S, 10)                      | One element in stack     | Top = 10             |
|    | NEXT_TO_TOP(S)                   | Not enough elements      | Error message        |
+----+----------------------------------+--------------------------+----------------------+
|10  | Fill stack with 32768 elements   | Stack becomes full       | ISFULL = 1           |
+----+----------------------------------+--------------------------+----------------------+
|11  | PUSH(S, 999) when full           | Overflow error           | Error message        |
+----+----------------------------------+--------------------------+----------------------+

Sample Expected Console Output:

Test 1: Create Stack
Empty = 1

Test 2: Push 10
Top = 10

Test 3: Push 20, 30
Top = 30

Test 4: Next-to-top
Next-to-top = 20

Test 5: Pop
Popped = 30
Top = 20

Test 6: Empty Stack
Popped = 20
Popped = 10
Empty = 1

Test 7: Underflow
Error: Stack is empty

Test 8: TOP on Empty Stack
Error: Stack is empty

Test 9: NEXT_TO_TOP with One Element
Error: Need at least two elements

Test 10: Fill Stack
ISFULL = 1

Test 11: Overflow
Error: Stack is full
=========================================================
*/

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
        printf("Pop = %f\nIs Empty = %d\n", test.x, ISEMPTY(&s));
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


