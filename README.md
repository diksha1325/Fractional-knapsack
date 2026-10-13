# Fractional-knapsack
C implementation of Fractional Knapsack using the Greedy Algorithm
# PBLE 1: Fractional Knapsack Problem

## Aim
To implement the Fractional Knapsack problem using the Greedy Algorithm in C for smart delivery planning.

## Problem Statement
A delivery vehicle has a limited weight capacity. Each package has a profit and a weight. The objective is to maximize the total profit by selecting packages without exceeding the vehicle's capacity. Packages can be selected completely or partially.

## Algorithm
1. Enter the number of packages, their profits, weights, and vehicle capacity.
2. Calculate the profit-to-weight ratio for each package.
3. Sort packages in decreasing order of their profit-to-weight ratio.
4. Select packages with the highest ratio first.
5. If a package cannot fit completely, select the required fraction of it.
6. Display the maximum profit and selected packages.

## Sample Input

Number of packages: `4`

Profits: `40 30 50 20`

Weights: `5 10 5 4`

Vehicle capacity: `15`

## Expected Output

Maximum profit: `113.00`

Total weight used: `15`

## Time Complexity
- Calculating ratios: O(n)
- Sorting packages using Bubble Sort: O(n²)
- Selecting packages: O(n)
- **Overall time complexity: O(n²)**

## Space Complexity
O(n), for storing package details, ratios, and selection fractions.

## Technologies Used
- Programming Language: C
- Algorithm: Greedy Algorithm
- Sorting Technique: Bubble Sort

## How to Run
1. Compile the program using a C compiler:
   `gcc fractional_knapsack.c -o fractional_knapsack`
2. Run the program:
   - Windows: `fractional_knapsack.exe`
   - Linux/macOS: `./fractional_knapsack`

## Conclusion
The Fractional Knapsack problem is solved using the Greedy Algorithm by selecting packages in decreasing order of profit-to-weight ratio to maximize the total profit within the vehicle's capacity.
