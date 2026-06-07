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
#include "sort.c"

int main(){

    int a[] = {9, 1, 8, 2, 7, 3, 6, 5, 4};
    int b[] = {9, 1, 8, 2, 7, 3, 6, 5, 4};

    insertionSort(a, 9);

    for(int i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    quickSort(b, 0, 8);

    for(int i = 0; i < 9; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}