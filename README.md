# CS201 - Data Structure 🐲
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Week 1
### Task 1:
_This is an interactive task._
Using an array of size 100, implement a data structure in C that supports Push,
Pop, and a third operation FindMin, which returns the smallest element in
the data structure, all in O(1) worst case time and O(1) extra space.

### Task 2:
Write a C program to convert a given decimal number into it’s 2’s complement
representation. The program first ask the user to enter a number and then
print its 2’s complement representation nicely. Assume that you are working with 32 bits machine.
##### input
####  
```
8
-1
-64
-3
-7
```
##### output
####
```
0000 0000 0000 0000 0000 0000 0000 1000
1111 1111 1111 1111 1111 1111 1111 1111
1111 1111 1111 1111 1111 1111 1100 0000
1111 1111 1111 1111 1111 1111 1111 1101
1111 1111 1111 1111 1111 1111 1111 1001
```

### Task 3:
Write a C program to convert a sequence of binary numbers into it’s equivalent
decimal number. Interprete the sequence as a 2’s complement representation.
The program first ask user to enter a sequence of bits of arbitrary lengths (but ≤ 32 bits). Then your program should first save this sequence in a 32 bit
format without changing the original value and print the same. Then print its
original decimal value.

##### input
####
```
1111111
0100
10000000
11001
```

##### output
####
```
1111 1111 1111 1111 1111 1111 1111 1111 -1
0000 0000 0000 0000 0000 0000 0000 0100 4
1111 1111 1111 1111 1111 1111 1000 0000 -128
1111 1111 1111 1111 1111 1111 1111 1001 -7
```

# Week 2

### Task:
Write a C-program which does the following based on the user choice of **a** or **b**:
**a**. Reads a text file (like the ExampleFile.txt provided). Stores it in an array named ‘Arr[]’ of the appropriate size (the size here should not be hard-coded).
**b**. Takes the user input of an array and stores it in an array named ‘Arr[]’ of appropriate size 
(the size here should not be hard- coded).

Assume that the zeroth element of Arr contains a 0. Then run the following queries on function 1 and function 2 (defined ahead) sequentially and compute the running-time each query takes:
- _Query 1_: increment the first index element of the array with a value of +5.
- _Query 2_: find the sum of the first n-5 elements in the array.

##### function 1:
This function takes as input the array Arr[] and builds it’s cumulative frequency array named CIarr[] of appropriate size. It then performs the queries on this new CIarr array. Make sure that after running Query 1, CIarr contains the correct value in all of it’s indices.

##### function 2:
This function takes as input the array Arr[] and builds the ‘Binary Indexed Tree’ as another array named BItree[] of appropriate size. It runs the respective queries through this new BItree array. Make sure that after running Query 1, BItree contains the correct value in all of it’s indices.

The output of your program should be the timings and values of running the following in this sequence:

- _query 1_ on _function 1_,
- _query 2_ on _function 1_,
- _query 1_ on _function 2_,
- _query 2_ on _function 2_

# Week 4

### Task:
Your program needs to read the ‘ExampleFile.txt’ file. The first line in the file will contain the total number of inputs (Say, N). Define an array ‘Arr’ with the size of this N. The second line in the file will contain the value of K (i.e your program needs to find this Kth smallest number). Continue reading the file for the input numbers and store them in this ‘Arr’ array.

You need to define two functions func1 and func2 defined as follows:
- **func1** : Before calling this function, create a new array ‘Arr1’ and copy the contents of Arr into Arr1. Call this function as func1(Arr1, N, K). This function should perform quicksort on the array Arr1 by taking the last element as pivot always. The function finally returns the element in the (K − 1)th index in the final sorted array (since array indices starts from 0).
- **func2** : Call this function as func2(Arr, N, K). This function should perform the median-of-medians Algorithm as taught in class and return the element which is the Kth smallest in the array.

In the main function you should call these functions as follows: First scan the input file and store values in N, K, Arr, Arr1. Then start a timer, call func1, stop the timer. Then print the returned value of func1 and the time taken by the function. Again, reset the timer to 0, call func2, stop the timer. Then print the returned value of func2 and the time taken
by the function.

# Week 6

### Task:
_This is an interactive task._
The problem is to implement B-trees in C. Your B-tree program should support the following operations:

- B-TREE-CREATE
- B-TREE-SPLIT-CHILD
- B-TREE-INSERT
- B-TREE-INSERT-NONFULL
- B-TREE-DELETE
- B-TREE-SEARCH
- B-TREE-MIN
- B-TREE-INORDER-TRAVERSE

# Week 8

### Task:
_This is an interactive task._
The problem is to implement Hash-Table where collisions are resolved via chaining with doubly linked lists in C.
The first line of input is an integer $m$, which provides the hashing function to be used as : $h(k) = k\mod m$.
The remaining program should support the following operations:
- Insert
- Delete
- Search
- Display

# Week 9

### Task:
For this assignment you need to implement randomized-quick sort and insertion sort from the numbers in a file.
Input: a .txt file with 10000 integers (32 bit)
Output: output_randomqs.txt and output_insersions.txt files with 10000 integers from input file in sorted order, and 2 integers in stdout - number of comparisions taken by randomized-quick sort and insertion sort respectively. 

# Week 11

## Task:
Implement DFS in C. If the graph is undirected return if the graph is bipartite (show a colouring if it is) or not.

Input:
- line 1: int $V$ - number of vertices in graph
- line 2: char $c$ - 'U' if graph is undirected, 'D' if graph is directed.
- next $E$ lines: int, int $(u, v)$ - representing an edge between vetrices u and v (from u to v in directed graph).
- line 4: char 'Q' - to indicate last edge has been added.

Output:
- first $V$ lines: adjecency list for each vertex.
- next $V$ lines: result of DFS on graph - with discovery and finish time for each vertex.
- next $E$ lines: classification of each edge as 'tree', 'forward', 'back' or 'cross' edge.
- last line: Bipartiteness of graph (along with a colouring if it is bipartite).

