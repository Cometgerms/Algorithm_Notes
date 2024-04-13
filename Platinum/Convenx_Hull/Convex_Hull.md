# Convex Hull

## Cross Product: A Fundamental Tool in Computational Geometry

### Definition and Formula

The cross-product is a binary operation on two vectors in three-dimensional space. Given two vectors **A** = \(A_x, A_y, A_z\) and **B** = \(B_x, B_y, B_z\), their cross product **A × B** is defined as:

$$ \mathbf{A} \times \mathbf{B} = (A_{y}B_{z} - A_{z}B_{y}, A_{z}B_{x} - A_{x}B_{z}, A_{x}B_{y} - A_{y}B_{x}) $$

This results in a new vector that is orthogonal (perpendicular) to both **A** and **B**. The magnitude of **A × B** is equal to the area of the parallelogram that **A** and **B** span, which is a key concept in geometric interpretations.

<p align="center">
  <img src="./images/Cross_product_vector.png" alt="Cross Product Vector" width="50%">
  <br>
  <em>Fig.1: Cross product vector.</em>
</p>

### Application in 2D Computational Geometry

In two-dimensional geometry, especially in algorithms like the Convex Hull, the cross-product is often simplified. Considering 2D vectors **A** = \(A_x, A_y\) and **B** = \(B_x, B_y\), the "2D cross product" can be represented as the scalar:

$$ \mathbf{A} \times \mathbf{B} = A_{x}B_{y} - A_{y}B_{x} $$

This scalar is crucial for determining the orientation of three points (say A, B, and C). If the result is positive, B lies to the left of the line formed by A and C, indicating a counter-clockwise turn. If it's negative, B lies to the right, indicating a clockwise turn. This concept is fundamental in Convex Hull algorithms like Graham's Scan and Jarvis's March, where the order and orientation of points are pivotal for determining the hull's boundary.

### Importance in Convex Hull Algorithms

In the context of computing the Convex Hull, the cross product helps identify the outermost points that form the "hull" of a set of points. By iterating over points and using the cross product to check turns at each step, algorithms can effectively "wrap" around the set of points, much like stretching a rubber band around them. This simple yet powerful application of the cross product is what makes it indispensable in computational geometry.

## Determine whether the line segments are turning left or right

Our next problem that needs to be considered is how to determine whether the line segments are turning left or right, which involves two continuous line segments \(\overrightarrow{p_1p_2}\). This section contains the most essential idea of the Convex Hull problem, since we need to determine the orientation of the line segments to establish whether they are convex or not. Utilizing the cross product can avoid the calculation of the angle between line segments. We calculate the cross product:

$$ (p_2 - p_0) \times (p_1 - p_0) $$

If the result is positive, then the line segments are turning clockwise at \(p_1\), which is right; otherwise, the line segments are turning left.

## Search for Convex Hull

The convex hull of a point set **Q** is a convex polygon **P** such that each point in **Q** is either on the boundary of **P** or in its interior. If we imagine all the points in the set **Q** as pins, the convex hull is like a tensed rubber band that wraps all the pins. The image below shows an example of a convex hull:

<p align="center">
  <img src="./images/example.png" alt="Convex Hull Example" width="50%">
  <br>
  <em>Fig.2: Example of the convex hull of a points set.</em>
</p>

We will delve into one of the most commonly used algorithms for locating the convex hull, known as Graham's Scan, with a time complexity of _O(n log n)_.

## Graham's Scan Algorithm

The Graham Scan algorithm is a method of computing the convex hull of a finite set of points in the plane with time complexity O(N log N). The convex hull is the smallest convex polygon that contains all the points.

**Steps of the Algorithm:**

1. **Find the Lowest Point**: First, find the point with the lowest y-coordinate. If there are ties, choose the point with the lowest x-coordinate. This point is the starting point of the convex hull.
2. **Sort Points by Polar Angle**: Sort the remaining points based on the polar angle they make with the lowest point. This is usually done using the atan2 function.
3. **Process Points**: Starting with the lowest point, process each point in the sorted order. For each point, check if moving from the two points immediately preceding it forms a left or right turn.
4. **Discard Points that Make a Right Turn**: If a right turn is encountered, the second-to-last point is not part of the convex hull and should be removed. Continue checking until a left turn is encountered.
5. **Complete the Hull**: Once all points have been processed, the remaining points form the convex hull.

**Pseudocode for the Graham Scan Algorithm:**

```plaintext
GRAHAM-SCAN(Q)
1. let p0 be the point in Q with the minimum y-coordinate, or the leftmost such point in case of a tie
2. let <p1, p2, ..., pm> be the remaining points in Q, sorted by polar angle in counterclockwise order around p0 (if more than one point has the same angle, remove all but the one that is farthest from p0)
3. if m < 2
4.     return "convex hull is empty"
5. else let S be an empty stack
6.     PUSH(p0, S)
7.     PUSH(p1, S)
8.     PUSH(p2, S)
9.     for i = 3 to m
10.        do while the angle formed by points NEXT-TO-TOP(S), TOP(S), and pi makes a nonleft turn
11.            do POP(S)
12.        PUSH(pi, S)
13. return S
```
The implementation of Graham's Scan can be found in the cpp file in this folder.



