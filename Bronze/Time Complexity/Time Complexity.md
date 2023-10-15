# Time Complexity

## Introduction

Time Complexity plays a crucial role in optimizing programs and excelling in programming competitions. Understanding how the time complexity of an algorithm affects its performance is vital for writing efficient code. In USACO, a popular competitive programming platform, it's common to have a time limit of 2 seconds for C++ submissions. To ensure your programs run within this limit, it's essential to have a firm grasp of time complexity analysis.

## Asymptotic Notations

Asymptotic notation ignores the slower-growing part of a function and its coefficient and constants in order to show the important part showing the growing trend of this function.
A simple mnemonic for understanding notations related to asymptotic notation is as follows:

Use uppercase for "greater/less than or equal to" (non-strict) and lowercase for "greater/less than" (strict).
- "Equal to" is represented by $\Theta$.
- "Less than" is represented by $O$.
- "Greater than" is represented by $\Omega$.

### Big $`\Theta`$ Notation
Big $\Theta$ represents the algorithm's worst time complexity situation. It tells both the upper limit and lower limit of a function. The mathematical way of defining big $\Theta$ notation:

For function $f(n)$ and $g(n)$, we say $f(n) = \Theta(g(n))$ if and only if:
$`
\exists c_1,\space c_2, \space n_0 \, > \, 0: \space \forall n \, \geq  \, n_0, \space 0\leq c_1 \cdot g(n) \leq f(n) \leq c_2 \cdot g(n)
`$

### Big O Notation

Big O notation is a standardized way of expressing the worst-case time complexity of an algorithm. It quantifies how an algorithm's runtime scales as the input size, denoted as 'n,' becomes arbitrarily large. The Big O notation provides an upper bound on the running time, helping us understand how an algorithm's efficiency degrades with larger input sizes. **We always use Big O Notations rather than Big $\Theta$ Notations since we only care about the upper limit of a specific function rather than its lower limit.** The mathematical way of defining Big O notation



