# Design & Analysis of Algorithms 

## Lab 1 

### Duplicate Numbers
**Category:** Iterative  
**Time Complexity:** O(n²) 
**Space Complexity :** `O(1)`  
Detect duplicate elements in an array by comparing each element with every other, returning all repeated values.


### Horner's Rule
**Category:** Iterative  
**Time Complexity:** `O(n)` 
**Space Complexity:** `O(1)`  
Evaluate a polynomial efficiently by reducing multiplications from O(n²) to O(n) through nested multiplication.


### Linear Search
**Category:** Iterative  
**Time Complexity:** `O(n)` 
**SpaceComplexity:** `O(1)`  
Sequentially scan an array to find a target element, returning its index or –1 if not found.


### Permutation Generator
**Category:** Recursive  
**Time Complexity:** `O(n!)` 
**Space Complexity:** `O(n)`  
Generate all n! arrangements of a set using recursion and in-place swapping.


### Tower of Hanoi
**Category:** Recursive  
**Time Complexity:** `O(2ⁿ)` 
**Space Complexity:** `O(n)`  
Move n disks from source to destination peg via an auxiliary peg without ever placing a larger disk on a smaller one.


### Velocity
**Category:** Iterative  
**Time Complexity:** `O(1)` 
**Space Complexity:** `O(1)`  
Given an initial velocity, determine how many times the velocity reduces until it becomes less than 1.0, where each reduction multiplies the velocity by a constant factor.
Naive Approach: Use an iterative loop to repeatedly multiply velocity by the reduction factor until it becomes less than 1.


### Power 
**Category:** Recursive  
**Time Complexity:** `O(log n)` 
**Space Complexity:** `O(log n)`  
Compute xⁿ using exponentiation by squaring to reduce recursive calls by half at each step.


### Sum of N Numbers
**Category:** Recursive  
**Time Complexity:** `O(n)` 
**Space Complexity:** `O(1)`  
Compute the cumulative sum of the first N natural numbers recursively.


### Truth Table Generation
**Category:** Iterative  
**Time Complexity:** `O(2ⁿ)` 
**Space Complexity:** `O(2ⁿ)`  
Enumerate all 2ⁿ combinations of n boolean variables and evaluate a logical expression for each row.

### Consecutive Numbers
**Category:** Iterative  
**Time Complexity:** `O(n)` 
**Space Complexity:** `O(1)`  
Determine whether a given array contains a sequence of consecutive integers.


## Lab 2 — Searching & Insertion Sort

### Binary Search
**Category:** Recursive  
**Time Complexity:** `O(log n)` 
**Space Complexity:** `O(1)`  
Search a sorted array by repeatedly halving the search interval until the target is found or the interval is empty.

### Insertion Sort
**Category:** Iterative  
**Time Complexity:** `O(n²)` 
**Space Complexity:** `O(1)`  
Build a sorted array one element at a time by inserting each new element into its correct position.


## Lab 3 — Divide & Conquer Sorting

### Merge Sort
**Category:** Recursive  
**Time Complexity:** `O(n log n)` 
**Space Complexity:** `O(n)`  
Recursively split the array in half, sort each half, and merge the two sorted halves.

### Quick Sort
**Category:** Recursive  
**Time Complexity:** `O(n log n)` 
**Space Complexity:** `O(log n)`  
Partition around a pivot, then recursively sort each partition.


## Lab 4 — Min-Max Finding

### Minimum & Maximum
**Category:** Recursive  
**Time Complexity:** `O(n)` 
**Space Complexity:** `O(1)`  
Find both min and max simultaneously using divide-and-conquer approach 


## Lab 5 

### Convex Hull
**Category:** Greedy  
**Time Complexity:** `O(n log n)` 
**Space Complexity:** `O(n)`  
Compute the smallest convex polygon enclosing all given points using Graham Scan

### Fractional Knapsack Problem
**Category:** Greedy  
**Time Complexity:** `O(n log n)` 
**Space Complexity:** `O(1)`  
Maximise value by greedily selecting items with the highest value-to-weight ratio, allowing fractional inclusion.

### Matrix Multiplication 
**Category:** Recursive  
**Time:** `O(n^3)` **Space:** `O(n²)`  
Multiply two n×n matrices using Strassen's method, reducing sub-multiplications from 8 to 7.

---

## Lab 6 — Greedy Graph Algorithms

### Dijkstra's Algorithm
**Category:** Greedy, Graph  
**Time Complexity:** `O((V+E) log V)` **Space Complexity:** `O(V)`  
Find single-source shortest paths in a weighted graph with non-negative edges using a min-priority queue.

### Prim's Algorithm
**Category:** Greedy, Graph  
**Time Complexity:** `O((V+E) log V)` **Space Complexity:** `O(V)`  
Grow a Minimum Spanning Tree from an arbitrary vertex by always adding the cheapest crossing edge.

### Kruskal's Algorithm
**Category:** Greedy, Graph  
**Time Complexity:** `O(E log E)` **Space Complexity:** `O(V)`  
Build an MST by sorting edges and adding the lowest-weight edge that does not form a cycle, tracked via Union-Find.

### Activity Selection
**Category:** Greedy  
**Time Complexity:** `O(n log n)` **Space Complexity:** `O(1)`  
Select the maximum number of non-overlapping activities by always choosing the one that finishes earliest.


## Lab 7 — Graph Traversal Techniques

### Cycle Detection
**Category:** Graph, Recursive  
**Time Complexity:** `O(V+E)` **Space Complexity:** `O(V)`  
Detect cycles in directed and undirected graphs using DFS coloring (white-gray-black) or Union-Find.

### Multistage Graph (Greedy)
**Category:** Greedy, Graph  
**Time Complexity:** `O(V+E)` **Space Complexity:** `O(V)`  
Find the shortest path through a layered graph using a greedy forward pass.


## Lab 8 — Dynamic Programming

### Matrix Chain Multiplication
**Category:** Dynamic Programming  
**Time Complexity:** `O(n³)` **Space Complexity:** `O(n²)`  
Determine the optimal parenthesisation of a matrix chain to minimise scalar multiplications using bottom-up DP.

### Multistage Graph — Forward Approach
**Category:** Dynamic Programming, Graph  
**Time Complexity:** `O(V+E)` **Space Complexity:** `O(V)`  
Compute the minimum-cost path through a multistage graph by propagating cost estimates forward from the source.

### Multistage Graph — Backward Approach
**Category:** Dynamic Programming, Graph  
**Time Complexity:** `O(V+E)` **Space Complexity:** `O(V)`  
Compute the minimum-cost path by propagating cost estimates backward from the sink to the source.


## Lab 9 — All-Pairs Shortest Paths

### Algorithm
**Category:** Dynamic Programming  
**Time Complexity:** `O(V³)` **Space Complexity:** `O(V²)`  
Compute shortest paths between all pairs of vertices in a weighted graph, handling negative edges but not negative cycles.


## Lab 10 

### 0/1 Knapsack
**Category:** Dynamic Programming  
**Time Complexity:** `O(nW)` **Space Complexity:** `O(nW)`  
Maximise total value without exceeding weight capacity W; each item is either fully taken or left.

### Travelling Salesperson Problem
**Category:** Dynamic Programming  
**Time Complexity:** `O(n² 2ⁿ)` **Space Complexity:** `O(n 2ⁿ)`  
Find the minimum-cost Hamiltonian cycle using Held-Karp bitmask DP.


## Lab 11 — Backtracking

### N-Queens
**Category:** Backtracking, Recursive  
**Time Complexity:** `O(n!)` **Space Complexity:** `O(n)`  
Place n non-attacking queens on an n×n board by column-by-column exploration with constraint pruning.

### Subset Sum
**Category:** Backtracking, Recursive  
**Time Complexity:** `O(2ⁿ)` **Space Complexity:** `O(n)`  
Find all subsets whose elements sum to a target value using recursive inclusion/exclusion with pruning.

### Graph Colouring
**Category:** Backtracking, Graph  
**Time Complexity:** `O(mⁿ)` **Space Complexity:** `O(V)`  
Assign m colours to vertices so no two adjacent vertices share a colour, explored via backtracking with constraint checking.
