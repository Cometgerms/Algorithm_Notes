# Binary Search Algorithm

## Overview
The Binary Search algorithm is an efficient method for finding an element within a sorted array. This algorithm repeatedly divides the search interval in half, beginning with the middle element of the array. If the middle element does not match the target value, the algorithm eliminates the half in which the target cannot lie and continues in the remaining half, repeating this process until the target value is found or the search space is reduced to zero.

## Algorithm Description
1. **Initialization**: Start with the entire array.
2. **Middle Element Check**: Locate the middle element of the current array or sub-array.
3. **Comparison and Decision**:
   - If the middle element is the target, return its index.
   - If the target is greater (assuming ascending order), narrow the search to the right half of the array.
   - If the target is lesser, narrow the search to the left half of the array.
4. **Iterate**: Repeat the above steps on the new sub-array.
5. **Termination**: The algorithm stops when the target element is found, or the sub-array size becomes zero.

## Time Complexity
The time complexity of the binary search algorithm is $O(log n)$, making it highly efficient for large datasets.

## Mathematical Deduction
The time complexity $O(log n)$ is derived based on the number of times the array can be divided by 2 until a single element remains. Mathematically, this is represented as $\frac{n}{2^k} = 1$, where $k$ is the number of iterations. Solving for $k$ gives us $k = log₂n$.
