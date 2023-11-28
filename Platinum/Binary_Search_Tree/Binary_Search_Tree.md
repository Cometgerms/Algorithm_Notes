# Binary Search Tree Overview

## Introduction
A Binary Search Tree (BST) is a data structure that maintains elements in a sorted order, allowing efficient insertion, deletion, and lookup operations. Each node in a BST contains a key, and optionally, additional data.

## Characteristics
- **Binary Tree**: A BST is a binary tree where each node has at most two children.
- **Ordered Structure**: For any node `n`, all keys in the left subtree of `n` are less than `n`'s key, and all keys in the right subtree are greater.

## Operations
### Insertion
To insert a new key, the tree is traversed from the root downwards, comparing the new key with the keys in the nodes and deciding whether to go left or right.

### Search
Searching involves comparing the search key with the keys in the nodes and moving left or right accordingly.

### Deletion
Three cases arise:
1. **Leaf Node**: Direct removal.
2. **One Child**: Replace the node with its child.
3. **Two Children**: Typically replaced by its in-order successor or predecessor.

### Traversal
- **In-Order**: Left subtree, Node, Right subtree. (Produces sorted order)
- **Pre-Order**: Node, Left subtree, Right subtree.
- **Post-Order**: Left subtree, Right subtree, Node.

## Complexity
- **Time Complexity**:
    - Average case: `O(log n)` for insertions, deletions, and searches.
    - Worst case: `O(n)`, when the tree becomes a linear structure.
- **Space Complexity**: `O(n)` for storing `n` nodes.

## Implementation in cpp
The implementation of a Binary Search Tree in C++ can be found in the file [Binary_Search_Tree.cpp](./Binary_Search_Tree.cpp) in this same directory.


