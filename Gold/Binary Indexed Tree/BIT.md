# Understanding the Fenwick Tree (Binary Indexed Tree)

The Fenwick Tree, also known as a Binary Indexed Tree, is a data structure that provides efficient methods for updating elements and calculating prefix sums in a sequence of numbers.

## Example Problem

Consider a typical problem solvable by the tree: given an array of length $n$, efficiently perform the following operations:

- $update(idx, delta)$: Add a number $delta$ to the element at position $idx$.
- $prefixSum(idx)$: Compute the sum of elements from the first position to position $idx$ (inclusive).
- $rangeSum(from_idx, to_idx)$: Calculate the sum of elements from position $from_idx$ to $to_idx$.

Aside from the brute-force solution of recalculating sums after each update, a simpler approach is to construct a _cumulative sum array_ in O(n) time. This array's $i$-th element holds the sum of the first $i$ elements of the original array. The operations are then:

- $update(idx, delta)$: Update the cumulative sum array for each affected prefix, from $idx$ to the end. This operation has O(n) time complexity.
- $prefixSum(idx)$: Return $cumulativeSum[idx + 1]$. This operation has O(1) time complexity.
- $rangeSum(from_idx, to_idx)$: Return $cumulativeSum[to_idx + 1] - cumulativeSum[from_idx]$. This operation has O(1) time complexity.

This approach is efficient for sum queries but linear-time for single updates. If updates are less frequent than sum queries, it's suitable. Otherwise, optimization is needed.

## Intuitive Explanation

1. $C[i]$ represents the sum of $f[1]$ to $f[i]$, while $tree[idx]$ represents the sum of some subsequence.
2. Specifically, $tree[idx]$ is the sum of $f[index]$ for indexes from $(idx - 2^r + 1)$ to $idx$, where $r$ is the number of trailing zeroes in the binary representation of $idx$. For example:
   - When $idx = 8$ (binary $1000$), with $r = 3$, $tree[8] = f[1] + … + f[8]$.
   - When $idx = 11$ (binary $1011$), with $r = 0$, $tree[11] = f[11]$.
   - When $idx = 12$ (binary $1100$), with $r = 2$, $tree[12] = f[9] + f[10] + f[11] + f[12]$.
   - When $idx = 14$ (binary $1110$), with $r = 1$, $tree[14] = f[13] + f[14]$.
3. With the $tree$ array, we can deduce that $C[13] = tree[13] + tree[12] + tree[8]$. An important conclusion is that the number of _1_ s in the binary representation of $idx$ equals the number of subsequences that constitute $C[idx]$, or the number of elements in $tree$ that sum up to it.
