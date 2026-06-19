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
#include "sort.c"

int main(){

    FILE *fp;
    Point coordinate[100]; // DONT FORGET TO CHANGE SIZE
    int n; //number of points sa file
    int anchor;

    fp = fopen("sample-input.txt", "r"); //open input file
    fscanf(fp, "%d", &n);   //read number of points

    //store in array
    for (int i = 0; i < n; i++) { 
        fscanf(fp, "%lf %lf", &coordinate[i].x, &coordinate[i].y);  
    }

    //print coordinates to check if stored correctly
    for(int i = 0; i < n; i++)
    {
        printf("%lf %lf\n", coordinate[i].x, coordinate[i].y);
    }
    printf("\n");

    anchor = findAnchorPoint(coordinate, n); // get anchor index
    printf("anchor index: %d || anchor point: (%lf, %lf)\n\n", anchor, coordinate[anchor].x, coordinate[anchor].y); // check if anchor correct

    swapPointArray(coordinate, 0, anchor); // swap anchor to first index
    anchor = 0; //update anchor index 

     //print coordinates to check if na swap
        for(int i = 0; i < n; i++)
    {
        printf("%lf %lf\n", coordinate[i].x, coordinate[i].y);
    }
    printf("\n");

    // test if nakukuha polar angle
    printf("point 1: (%lf, %lf), point 2: (%lf, %lf)\n", coordinate[anchor].x, coordinate[anchor].y, coordinate[1].x, coordinate[1].y);
    printf("polar angle: %lf\n\n", polarAngle(coordinate[1], coordinate[anchor]));


    // INSERTION SORT
    insertionSort(coordinate, anchor, n);
    printf("sorted coordinates(insertion sort):\n");

    for(int i = 0; i < n; i++)
    {
        printf("(%lf, %lf)\n", coordinate[i].x, coordinate[i].y);
    }
    printf("\n");

-------------------------------------------------------------------------

    // QUICK SORT 
    quickSort(coordinate, 1, n - 1, anchor);

    printf("sorted coordinates(quick sort):\n");

    for(int i = 0; i < n; i++)
    {
        printf("(%lf, %lf)\n", coordinate[i].x, coordinate[i].y);
    }
    printf("\n");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // int a[] = {9, 1, 8, 2, 7, 3, 6, 5, 4};
    // int b[] = {9, 1, 8, 2, 7, 3, 6, 5, 4};

    
    // insertionSort(a, 9);

    // for(int i = 0; i < 9; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");

    // quickSort(b, 0, 8);

    // for(int i = 0; i < 9; i++)
    // {
    //     printf("%d ", b[i]);
    // }
    // printf("\n");
}

// HOW TO COMPILE: gcc -Wall -std=c99 <yourMP.c> -o <output>