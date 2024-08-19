#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    string value; // Can be either a question or an animal guess
    bool isQuestion;
    Node* yes;
    Node* no;

    Node(const string& val, bool isQ) : value(val), isQuestion(isQ), yes(nullptr), no(nullptr) {}
};

class AnimalGuessingGraph {
private:
    Node* root;

public:
    AnimalGuessingGraph() {
        // Initialize with a simple guess
        root = new Node("lizard", false); // The initial guess is "lizard"
    }

    void playGame(Node* currentNode) {
        cout << "Think of an animal and hit enter when you're ready." << endl;
        cin.ignore(); // Clear the input buffer

        while (true) {
            if (!currentNode->isQuestion) {
                // If it's not a question, it means it's a guess
                cout << "Is it a " << currentNode->value << "? (yes/no): ";
                string answer;
                getline(cin, answer);

                if (answer == "yes") {
                    cout << "Good! I guessed your animal." << endl;
                    break;
                } else if (answer == "no") {
                    cout << "Bummer! What animal were you thinking of?" << endl;
                    string newAnimal;
                    getline(cin, newAnimal);

                    cout << "What is a yes/no question that I can use to identify a " << newAnimal << "?" << endl;
                    string newQuestion;
                    getline(cin, newQuestion);

                    cout << "For a " << newAnimal << ", is the answer yes or no? (yes/no): ";
                    string newAnswer;
                    getline(cin, newAnswer);

                    // Create new nodes for the new animal and the old guess
                    Node* yesNode = (newAnswer == "yes") ? new Node(newAnimal, false) : new Node(currentNode->value, false);
                    Node* noNode = (newAnswer == "yes") ? new Node(currentNode->value, false) : new Node(newAnimal, false);

                    // Replace the current guess with the new question
                    currentNode->value = newQuestion;
                    currentNode->isQuestion = true;
                    currentNode->yes = yesNode;
                    currentNode->no = noNode;
                    break;
                }
            } else {
                // If it's a question, ask the user and navigate the graph accordingly
                cout << currentNode->value << " (yes/no): ";
                string answer;
                getline(cin, answer);

                if (answer == "yes") {
                    currentNode = currentNode->yes;
                } else if (answer == "no") {
                    currentNode = currentNode->no;
                }
            }
        }
    }

    void startGame() {
        do {
            playGame(root);
            cout << "Try again? (yes/no): ";
            string playAgain;
            getline(cin, playAgain);

            if (playAgain != "yes") {
                break;
            }
        } while (true);
    }
};

int main() {
    AnimalGuessingGraph game;
    cout << "Let's play the 'Guess the Animal' game." << endl;
    game.startGame();
    return 0;
}
