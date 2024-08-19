Here is a time complexity analysis for the four data structures (Binary Tree, Hash Map, Graph, and Finite State Machine) used in the **Animal Guessing Game**:

---

## ⏱️ Time Complexity Analysis

| Operation/Structure             | Binary Tree       | Hash Map            | Graph              | Finite State Machine (FSM) |
|---------------------------------|-------------------|--------------------|-------------------|-----------------------------|
| **Insertion**                   | O(log n) (balanced) | O(1)               | O(1)              | O(1)                        |
| **Search**                      | O(log n) (balanced) | O(1)               | O(n)              | O(1)                        |
| **Traversal for Questioning**   | O(log n)          | O(n)               | O(n)              | O(1)                        |
| **Expansion/Learning New Info** | O(1)              | O(1)               | O(1)              | O(1)                        |

### 1. **Binary Tree**:
   - **Insertion**: O(log n) – If the tree is balanced, inserting new information (new questions or animals) follows a logarithmic pattern due to binary search principles.
   - **Search**: O(log n) – Searching for the correct path during questioning (following yes/no branches) is logarithmic.
   - **Traversal for Questioning**: O(log n) – Each yes/no decision halves the remaining nodes, leading to logarithmic traversal times.
   - **Expansion/Learning New Info**: O(1) – Adding a new animal and a new question involves a constant time operation since it only updates the immediate node and adds two child nodes.

> **Note**: These complexities assume a balanced binary tree. If the tree is unbalanced, the worst-case time complexity can degrade to O(n).

### 2. **Hash Map**:
   - **Insertion**: O(1) – Inserting a new path (yes/no decisions) and associating it with a question or guess is an average constant-time operation.
   - **Search**: O(1) – Accessing any path is done in constant time since the key (path) is used directly to retrieve the value (question/guess).
   - **Traversal for Questioning**: O(n) – Traversing the entire map to find the correct path (if you need to display all paths) requires linear time.
   - **Expansion/Learning New Info**: O(1) – Learning involves adding a new key-value pair or updating an existing key, both of which are constant time.

> **Drawback**: The hash map doesn’t naturally maintain order, so displaying questions/animals in a structured way can be complex and may require additional sorting.

### 3. **Graph**:
   - **Insertion**: O(1) – Adding a new question or animal as a node involves constant time since it only requires adding edges to existing nodes.
   - **Search**: O(n) – Searching for the correct path in the graph can be linear in the worst case, especially in non-trivial graphs.
   - **Traversal for Questioning**: O(n) – Traversing a graph to determine which node (question/guess) to present next can involve visiting multiple nodes.
   - **Expansion/Learning New Info**: O(1) – Similar to insertion, expanding the graph involves adding nodes and edges, which are constant time operations.

> **Flexibility**: The graph structure allows for more complex relationships between questions and answers, but can lead to inefficiencies in traversal if not carefully managed.

### 4. **Finite State Machine (FSM)**:
   - **Insertion**: O(1) – Adding a new state (question/guess) or transition (yes/no answer) is constant time.
   - **Search**: O(1) – Each state transition is based on the user’s input ("yes" or "no"), and each transition is resolved in constant time.
   - **Traversal for Questioning**: O(1) – The FSM operates in fixed steps, with each question leading to a direct transition, making it highly efficient.
   - **Expansion/Learning New Info**: O(1) – Adding new states and transitions involves constant time since only the immediate state is updated.

> **Efficiency**: FSMs are highly optimized for sequential decision-making processes, making them ideal for interactive applications like this guessing game.

---
