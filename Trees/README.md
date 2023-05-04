# TREES
* A tree is an abstract data type that stores elements hiearchically.
* A tree is defined as a set of **nodes** storing elements such that the nodes have a **parent-child** relationship.
* If a tree is non empty, it has a special node, called the **root** of the tree, that has no parent.
* Each node of tree different from the root has a unique **parent** node.
* Every node with parent is a **child** of that parent.
* Two nodes that are children of the same parent are **siblings**.
* A node is **external** if that node has no childrem. They are also known as **leaves**.
* A node is **internal** if it has one or more children.

## TRAVERSAL OF TREE
A **traversal** of a tree is a systematic way of accessing, or "visiting", all the positions of that tree.
### Several Traversal Schemes of Trees:
1. **Pre Order Traversal** : In a Pre Order Traversal of a tree,  the root of that tree is visited first and then the subtrees rooted at its children are traversed recursively. If the tree is ordered, then the subtrees are traversed recursively.
2. **In Order Traversal** : In a In Order Traversal of a tree, the tree can be informally viewed as visiting the nodes of that tree "from left to right".
3. **Post Order Traversal** : This is the opposite of the Pre Order Traversal, because it recursively traverses the subtrees rooted at the children of the root first, and then visits the root.

## Structure of the File
1. [`NonRecursiveInOrderTraversal.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/NonRecursiveInOrderTraversal.c) - Demonstrates the Non Recursive In Order Traversal in Tree.
2. [`NonRecursivePostOrderTraversal.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/NonRecursivePostOrderTraversal.c) - Demonstrates the Non Recursive Post Order Traversal in Tree.
3. [`NonRecursivePreOrderTraversal.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/NonRecursivePreOrderTraversal.c) - Demonstrates the Non Recursive Pre Order Traversal in Tree.
4. [`NonRecursiveTraversal.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/NonRecursiveTraversal.c) - Demonstrates the Non Recursive Traversal of all three types (In, Pre, Post) in Tree.
5. [`RecursiveInOrderTraversal.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/RecursiveInOrderTraversal.c) - Demonstrates the Recursive In Order Traversal in Tree.
6. [`RecursivePostOrderTraversal.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/RecursivePostOrderTraversal.c) - Demonstrates the Recursive Post Order Traversal in Tree.
7. [`RecursivePreOrderTraveral.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/RecursivePreOrderTraveral.c) - Demonstrates the Recursive Pre Order Traversal in Tree.
8. [`RecursiveTraversal.c`](https://github.com/fromjyce/DSA-in-C/blob/main/Trees/RecursiveTraversal.c) - Demonstrates the Recursive Traversal of all three types (In, Post, Pre) in Tree.
