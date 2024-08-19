

---

# 🐾 Data Structures Warzone: The Animal Guessing Game

Welcome to the **Data Structures Warzone**, where four powerful data structures go head-to-head in a battle of wits and strategy! In this repository, you’ll find the classic "Animal Guessing Game" implemented using four different data structures:

1. **Binary Tree**
2. **Hash Map**
3. **Graph**
4. **Finite State Machine (FSM)**

Each implementation showcases a unique approach to building an adaptive and interactive game that grows smarter the more you play it!

## 🧩 Problem Overview

The **Animal Guessing Game** is an interactive game where the program attempts to guess the animal you're thinking of by asking yes/no questions. If the program is stumped, it asks you to teach it by providing a new question and answer, making it smarter for the next round. 

As the game evolves, the data structure grows, storing new knowledge and expanding its decision-making capabilities.

## 💻 Implementations

### 1. **🌲 Binary Tree Implementation**
   - A classic approach using a binary tree structure, where each node is either a question or a guess.
   - Nodes dynamically branch out as the program learns new animals and questions.

### 2. **🔍 Hash Map Implementation**
   - Utilizes a hash map where each path of yes/no answers is the key, and the value is either a question or an animal guess.
   - Efficient lookups and easy to expand as the game learns.
   - Ideal for situations where quick access to information is crucial.

### 3. **🔗 Graph Implementation**
   - Models the game as a directed graph, with questions as nodes and answers as edges leading to other nodes.
   - Offers flexibility in representing complex relationships between questions and guesses.

### 4. **⚙️ Finite State Machine (FSM) Implementation**
   - Treats each question or guess as a distinct state, with transitions based on the user’s answers.
   - A structured and systematic approach to decision-making, breaking down the game into states and transitions.

## 📂 Repository Structure

```
data-structures-warzone/
├── binary_tree.cpp         # Binary Tree Implementation
├── hash_map.cpp            # Hash Map Implementation
├── graph.cpp               # Graph Implementation
├── fsm.cpp                 # Finite State Machine (FSM) Implementation
└── README.md               # You're here!
```

## ⚙️ How to Run

Each file is standalone and can be compiled and run using your preferred C++ compiler. For example, to run the Binary Tree implementation:

```bash
g++ binary_tree.cpp -o binary_tree
./binary_tree
```

Repeat the above for the other implementations to experience how each data structure performs the Animal Guessing Game.

## 🧠 Why This Repository?

This project showcases how different data structures handle:
- Adaptive decision-making.
- Dynamic growth as new information is learned.
- Efficient data storage and retrieval.

## 📊 Time Complexity Analysis

Here’s a brief comparison of the time complexities for each implementation:

| Operation/Structure             | Binary Tree        | Hash Map           | Graph            | Finite State Machine (FSM) |
|---------------------------------|-------------------|-------------------|-----------------|-----------------------------|
| **Insertion**                   | O(log n)          | O(1)              | O(n)            | O(1)                        |
| **Search**                      | O(log n)          | O(1)              | O(n)            | O(1)                        |
| **Dynamic Growth & Learning**   | O(log n)          | O(1)              | O(n)            | O(1)                        |


## 📚 Example Output

Here’s what you can expect when playing the game:

```
Let's play the 'Guess the Animal' game.
Think of an animal and hit enter when you're ready.

Is it a lizard? (yes/no): no
Bummer! What animal were you thinking of?
dog
What is a yes/no question that I can use to identify a dog?
Is it the cutest animal out there?
For a dog, is the answer yes or no? (yes/no): yes
Try again? (yes/no): yes
Think of an animal and hit enter when you're ready.

Is it the cutest animal out there? (yes/no): yes
Is it a dog? (yes/no): yes
Good! I guessed your animal.
```

The more you play, the smarter each data structure becomes, adding new questions and guesses with every game!

## 🎯 Conclusion

This repository is a fun and educational display of how different data structures can be applied to the same problem, each with its own advantages.

Feel free to explore, play around with the code, and contribute further!

---
