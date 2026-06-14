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
#include "math.h"


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




int partition(Point a[], int start, int end, int anchor);







/*
    a. Name of Programmer(s):  Mavrick De Guzman
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will find the index of the anchor point, which is the lowest point.
    e. Return: int - index of anchor point.
    f. Parameters: Point points[] - array of points, int n - number of points in the array
*/
int findAnchorPoint(Point points[], int n) {
    int index = 0; // track index of lowest point
    int i;

    // find lowest y coor
    for (i = 1; i < n; i++) {
        if (points[i].y < points[index].y) 
        {
            index = i;
        }
        else if (points[i].y == points[index].y) //if may y na equal, compare x coor
        {  
            if (points[i].x < points[index].x) 
            {
                index = i;
            }
        }
    }
    return index;
}

/*
    a. Name of Programmer(s):  Mavrick De Guzman
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will return the polar angle between two points.
    e. Return: double - polar angle between the two points
    f. Parameters: Point a - is a point , Point b - is another point
*/
double polarAngle(Point a, Point b)
{
    double dx;
    double dy;

    dx = a.x - b.x;
    dy = a.y - b.y;

    return atan2(dy, dx);
}

/*
    a. Name of Programmer(s):  Mavrick De Guzman
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will return the distance between two points
    e. Return: double - distance between the two points
    f. Parameters: Point a - is a point , Point b - is another point
*/
double distance(Point a, Point b)
{
    double dx;
    double dy;

    dx = a.x - b.x;
    dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}


/*
    a. Name of Programmer(s):  Mavrick De Guzman
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will swap two points in an array
    e. Return: NONE
    f. Parameters: Point coordinate[] - is an array of points, int i and int j - index of the points you want to switch
*/
void swapPointArray(Point coordinate[], int i, int j)
{
    Point temp;

    temp = coordinate[i];
    coordinate[i] = coordinate[j];
    coordinate[j] = temp;
}



/*
    a. Name of Programmer(s):  Mavrick De Guzman
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function sorts the array using insertion sort based on the polar angles by each point with the anchor point.
    e. Return: NONE
    f. Parameters: Point a[] - is an array of points, int anchor - contains the index of the anchor, int n - number of points in the array
*/
// shift all indexes to +1 kasi nakastore na yung anchor sa index 0
void insertionSort(Point a[], int anchor, int n) 
{
    int i;
    int j;
    Point temp;

    for(i = 2; i < n; i++)
    {
        temp = a[i]; // store the index ur currently sorting to in temp
        j = i - 1; // left side of the index ur currently sorting

        //while the left side is bigger than the index ur currently sorting
        while(j >= 1 && (polarAngle(a[j], a[anchor]) > polarAngle(temp, a[anchor]) || 
             ( polarAngle(a[j], a[anchor]) == polarAngle(temp, a[anchor]) && distance(a[j], a[anchor]) > distance(temp, a[anchor]) ) ) ) 
        {
            a[j + 1] = a[j]; // shift the left side to right 
            j--; // decrement
        }
        a[j + 1] = temp; // insert temp to correct position/index
    }
}

/*
    a. Name of Programmer(s):  Mavrick De Guzman
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function sorts the array using quick sort based on the polar angles by each point with the anchor point.
    e. Return: NONE
    f. Parameters: Point a[] - is an array of points, int start - contains index where sorting of the array starts,
                   int end - contains index where sorting of the array ends,  int anchor - contains the index of the anchor
*/
void quickSort(Point a[], int start, int end, int anchor)
{
    int pivot; // location of pivot

    if(end <= start) return; // base case

    pivot = partition(a, start, end, anchor); // sort array to find pivot
    quickSort(a, start, pivot - 1, anchor); // left partition
    quickSort(a, pivot + 1, end, anchor);  // right partition
}

/*
    a. Name of Programmer(s):  Mavrick De Guzman
    b. Name of Tester(s)    :  
    c. Code Type -- 100% Human Generated 
    d. Purpose: partitions the array of points for quick sort. selects the last element as pivot.
    e. Return: int - index of pivot after partition.
    f. Parameters: Point a[] - is an array of points, int start - contains index where sorting of the array starts,
                               int end - contains index where sorting of the array ends,  int anchor - contains the index of the anchor
*/
//helper function for quicksort
int partition(Point a[], int start, int end, int anchor)
{
    Point pivot; //for this variation, pivot will always be at the end
    int i;
    int j;


    pivot = a[end];
    i = start - 1;

    for(j = start; j <= end - 1; j++)
    {
         if(polarAngle(a[j], a[anchor]) < polarAngle(pivot, a[anchor]) || 
             ( polarAngle(a[j], a[anchor]) == polarAngle(pivot, a[anchor]) && distance(a[j], a[anchor]) < distance(pivot, a[anchor]) ) ) 
         {
            i++;
            // swap
            swapPointArray(a, i, j);
         }
    }
    i++;
 
    swapPointArray(a, i, end);
     
    return i; //location of pivot  
      
}