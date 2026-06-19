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
#include <time.h>

// include your own stack header file
#include "stack.h"
#include "sort.c"

/*
    a. Name of Programmer(s):  Marco Yatco
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will determine the direction formed by the points
    e. Return: int - 0 if collinear, 1 if clockwise, 2 if counterclockwise
    f. Parameters: Point p - is the first point , Point q - is the second point, Point r - is the third point
*/
int orientation(Point p, Point q, Point r)
{
    double value;
    value = (q.y - p.y) * (r.x -q.x) - (q.x - p.x) * (r.y -q.y);

    if(value = 0)
        return 0; //collinear

    if(value > 0)
        return 1; //clockwise

    return 2; //counterclockwise
}

/*
    a. Name of Programmer(s):  Marco Yatco
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function computes for the convex hull using the Graham's scan algorithim.
                this algorithim will be using the insertionSort (Slow)
    e. Return: S - Hull points after using the graham scan
    f. Parameters: point - contains coordinates of points, n - number of points
*/
Stack grahamSlow(Point point[], int n)
{
    int i;
    int anchor;
    Stack S;
    clock_t time_start;
    clock_t time_end;
    double totalTime;

    time_start = clock();

    anchor = findAnchorPoint(point, n);
    insertionSort(point, anchor, n);
    CREATE(&S);
    PUSH(&S, point[0]);
    PUSH(&S, point[1]);
    PUSH(&S, point[2]);

    for(i=3; i<n; i++)
    {
        while(S.top >= 1 && orientation(NEXT_TO_TOP(&S),TOP(&S),point[i])!=2)
            POP(&S);

        PUSH(&S,point[i]);
    }

    time_end = clock();

    totalTime = ((double)(time_end - time_start)/CLOCKS_PER_SEC)*1000;

    printf("The Total elapsed time for the slow Graham Scan is : %lf ms", totalTime);

    return S;
}
