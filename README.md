# Data Structures and Algorithms with C++

[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Status](https://img.shields.io/badge/Status-Completed-success.svg)]()

A comprehensive collection of Data Structures and Algorithms (DSA) implementations, assignment solutions, and study materials developed during the M.Sc-M.Tech coursework at **IIT Jodhpur**.

---

## 📌 Overview

This repository serves as a centralized hub for fundamental and advanced DSA concepts implemented in C++. It includes hand-crafted implementations of core data structures, optimized solutions to lab assignments, and curated PDF notes for theoretical understanding.

## 📂 Repository Structure

The project is organized by data structure categories. Each directory contains source code (`.cpp`), executable files (`.exe`), and supplementary reading materials (`.pdf`).

```text
.
├── 🌳 Binary Tree/         # BST implementations and tree traversal assignments
├── 📉 Heap/                # Max-Heap and Priority Queue implementations
├── 🔗 LinkedList/          # Singly, Doubly, and Circular Linked Lists
├── 👥 Queue/               # Linear, Circular, and Linked List-based Queues
└── 📚 Stack/               # Array and Linked List-based Stacks, and Applications
```

---

## 🛠️ Implementation Details

### [1. Linked Lists](./LinkedList/)
Focuses on dynamic memory management and pointer manipulation.
- **Implementations:** `singlyLinkedList.cpp`, `DoublyLinkedList.cpp`.
- **Assignments:** Problems covering list reversal, merging, and cycle detection.
- **Resources:** `Linked List comprehensive notes.pdf`.

### [2. Stacks](./Stack/)
Covers LIFO (Last-In-First-Out) principles and their applications.
- **Implementations:** `StackArray.cpp`, `StackLinkedlist.cpp`, `TwoStack.cpp`.
- **Applications:** Infix to Postfix conversion, balanced parentheses.
- **Resources:** `Stack_Complete_Note.pdf`.

### [3. Queues](./Queue/)
Implementations of FIFO (First-In-First-Out) data structures.
- **Implementations:** `QueueArray.cpp`, `QueueLinkedList.cpp`, `CircularQueue.cpp`.
- **Assignments:** Josephus problem, sliding window maximum, etc.
- **Resources:** `QueueNotes.pdf`.

### [4. Binary Trees](./Binary%20Tree/)
Hierarchical data structures and search optimizations.
- **Implementations:** `IntroBinaryTree.cpp`, `BSTLinkedList.cpp` (Binary Search Tree).
- **Assignments:** Tree traversals (Inorder, Preorder, Postorder), height calculation, and BST validation.

### [5. Heaps](./Heap/)
Implementation of Priority Queues using binary heaps.
- **Implementations:** `MaxHeap.cpp`.

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (e.g., `g++` supporting C++17 or higher).
- A terminal or IDE (VS Code recommended).

### Compilation and Execution
To compile and run any `.cpp` file:

```bash
# Navigate to the directory
cd "LinkedList"

# Compile the source code
g++ Assignment3Ques1.cpp -o solution

# Execute the binary
./solution
```

---

## 📘 Learning Resources
Each module is accompanied by detailed PDF notes and practice sheets (found within the respective folders) to bridge the gap between theory and implementation.

- **Stack Notes:** `Stack/Stack_Complete_Note.pdf`
- **Queue Notes:** `Queue/QueueNotes.pdf`
- **Linked List Notes:** `LinkedList/Linked List comprehensive notes.pdf`

---

## 👤 Author
**Souvik Ghorui**  
M.Sc-M.Tech Student, IIT Jodhpur  
[GitHub Profile](https://github.com/SouvikGhorui)

## ⚖️ License
This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---
*Disclaimer: These implementations are for educational purposes. If you are a student at IIT Jodhpur or any other institution, please ensure you follow your local academic integrity guidelines.*
