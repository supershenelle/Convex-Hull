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

//type gcc -Wall test_slow.c graham_slow.c sort.c stack.c -o test_slow -lm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// include your own stack header file
#include "stack.h"
#include "sort.h"
#include "graham_slow.h"

#define LIMIT 32768

Stack grahamSlow(Point points[], int n); 
typedef char shortString[31]; //for items 30 characters

int main()
{
    FILE *fp;
    shortString inputFile, outputFile;
    Stack S;
    Point initialPoints[LIMIT];
    Point hullPoints[LIMIT];
    int i,j;
    int n;
    int m = 0;

    printf("Enter your input filename: ");
    scanf("%30s",inputFile);
    printf("Enter your output filename: ");
    scanf(" %30s",outputFile);

    fp = fopen(inputFile, "r");

    if(fp == NULL)
    {
        printf("Invalid Text File!");
        return 1;
    }

    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) { 
        fscanf(fp, "%lf %lf", &initialPoints[i].x, &initialPoints[i].y);  
    }
    
    fclose(fp);

    S = grahamSlow(initialPoints, n);

    fp = fopen(outputFile, "w");

    if(fp == NULL)
    {
        printf("Invalid Text File!");
        return 1;
    }
    
    while(!ISEMPTY(&S))
    {
        hullPoints[m++] = TOP(&S);
        POP(&S);
    }

    fprintf(fp, "%d\n", m);
    for (j = m - 1; j >= 0; j--)
        fprintf(fp, "%.2f %.2f\n", hullPoints[j].x, hullPoints[j].y);

    fclose(fp);

    return 0;
}