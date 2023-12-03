# Convex Hull

## Cross Product: A Fundamental Tool in Computational Geometry

### Definition and Formula

The cross product is a binary operation on two vectors in three-dimensional space. Given two vectors **A** = (A<sub>x</sub>, A<sub>y</sub>, A<sub>z</sub>) and **B** = (B<sub>x</sub>, B<sub>y</sub>, B<sub>z</sub>), their cross product **A** × **B** is defined as:

$$ \textbf{A} \times \textbf{B} = (A_{y}B_{z} - A_{z}B_{y}, A_{z}B_{x} - A_{x}B_{z}, A_{x}B_{y} - A_{y}B_{x})  $$

This results in a new vector that is orthogonal (perpendicular) to both **A** and **B**. The magnitude of **A** × **B** is equal to the area of the parallelogram that **A** and **B** span, which is a key concept in geometric interpretations.

<div style="text-align:center">
  <img src="./images/Cross_product_vector.png" alt="Big Theta Notation" width="25%">
    <figcaption>Caption: Cross product vector.</figcaption>
</div>

### Application in 2D Computational Geometry

In two-dimensional geometry, especially in algorithms like the Convex Hull, the cross product is often simplified. Considering 2D vectors **A** = (A<sub>x</sub>, A<sub>y</sub>) and **B** = (B<sub>x</sub>, B<sub>y</sub>), the "2D cross product" can be represented as the scalar:

$$ \textbf{A} \times \textbf{B} = A_{x}B_{y} - A_{y}B_{x} $$

This scalar is crucial for determining the orientation of three points (say A, B, and C). If the result is positive, B lies to the left of the line formed by A and C, indicating a counter-clockwise turn. If it's negative, B lies to the right, indicating a clockwise turn. This concept is fundamental in Convex Hull algorithms like Graham's Scan and Jarvis's March, where the order and orientation of points are pivotal for determining the hull's boundary.

### Importance in Convex Hull Algorithms

In the context of computing the Convex Hull, the cross product helps in identifying the outermost points that form the "hull" of a set of points. By iterating over points and using the cross product to check turns at each step, algorithms can effectively "wrap" around the set of points, much like stretching a rubber band around them. This simple yet powerful application of the cross product is what makes it indispensable in computational geometry.

