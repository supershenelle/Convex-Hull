## 📝 Convex Hull

A C program that computes the convex hull of a set of 2D points using **Graham's Scan**, implemented with two different sorting algorithms to compare their empirical performance:

- **Insertion Sort** (`graham_slow`) — O(n²)
- **Quick Sort** (`graham_fast`) — O(n log n)

Built as a group machine project (MCO1) for a Data Structures and Algorithms course.

## How it works

1. Read `n` points from an input file.
2. Find the **anchor point** (lowest y-coordinate, ties broken by lowest x).
3. Sort the remaining points by polar angle relative to the anchor (ties broken by distance).
4. Scan the sorted points with a stack, popping any point that would create a clockwise turn or a collinear point, keeping only points that form a strict counterclockwise turn.
5. Write the resulting hull points to an output file and print them to the console, along with the elapsed computation time.

## Project structure

```
graham_slow.c / .h   Graham's Scan using Insertion Sort
graham_fast.c / .h   Graham's Scan using Quick Sort
sort.c / .h          Sorting algorithms, orientation, distance, polar angle helpers
stack.c / .h         Stack ADT used to build the hull (Point, Stack types)
test_slow.c          Driver program for the Insertion Sort version
test_fast.c          Driver program for the Quick Sort version
test_sort.c          Driver/test program for the sorting functions
test_stack.c         Driver/test program for the stack ADT
empirical-time.c     Sample program for measuring empirical execution time
TEXTFILES/           Sample and benchmark input files (varying sizes)
OUTPUTFILES/         Sample and benchmark output files
```

## Input format

```
n
x1 y1
x2 y2
...
xn yn
```

The first line is the number of points, followed by `n` lines of `x y` coordinates.

## Output format

```
m
x1 y1
x2 y2
...
xm ym
```

The first line is the number of hull points, followed by the hull's vertices in counterclockwise order, starting from the anchor point.

## Building

Requires `gcc`. On Windows, the `-Wl,--stack,16777216` flag is recommended (or required for large inputs) since the program stores large point arrays on the stack and Windows' default 1MB stack is too small.

**Insertion Sort version:**
```bash
gcc -Wall test_slow.c graham_slow.c sort.c stack.c -o test_slow.exe -lm -Wl,--stack,16777216
```

**Quick Sort version:**
```bash
gcc -Wall test_fast.c graham_fast.c sort.c stack.c -o test_fast.exe -lm -Wl,--stack,16777216
```

> On Windows PowerShell, wrap the stack flag in quotes: `"-Wl,--stack,16777216"`

## Running

```bash
./test_slow.exe
Enter your input filename: TEXTFILES/sample-input.txt
Enter your output filename: output.txt
```

The program prints each hull point and the elapsed time for the Graham Scan computation, and also writes the result to the given output file.

## Authors

Group 06
- De Guzman, Mavrick L.
- Nono, Shenelle Andrea G.
- Yatco, Marco Alfredo D.
