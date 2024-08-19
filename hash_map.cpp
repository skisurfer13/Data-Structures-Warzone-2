#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class AnimalGuessingGame {
private:
    unordered_map<string, pair<string, bool>> knowledgeBase; // Key: path ("yes-no-yes"), Value: {question/guess, isQuestion}

public:
    AnimalGuessingGame() {
        // Initialize with a simple animal guess
        knowledgeBase[""] = {"lizard", false}; // Root guess (not a question)
    }

    void playGame() {
        cout << "Think of an animal and hit enter when you're ready." << endl;
        cin.ignore(); // Clear the input buffer

        string path = "";
        while (true) {
            if (knowledgeBase[path].second == false) { // It's a guess, not a question
                cout << "Is it a " << knowledgeBase[path].first << "? (yes/no): ";
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

                    // Update the knowledge base
                    string yesPath = path + "-yes";
                    string noPath = path + "-no";

                    knowledgeBase[yesPath] = (newAnswer == "yes") ? make_pair(newAnimal, false) : make_pair(knowledgeBase[path].first, false);
                    knowledgeBase[noPath] = (newAnswer == "yes") ? make_pair(knowledgeBase[path].first, false) : make_pair(newAnimal, false);

                    // Replace the current guess with the new question
                    knowledgeBase[path] = {newQuestion, true}; // Now it's a question, not a guess
                    break;
                }
            } else { // It's a question
                cout << knowledgeBase[path].first << " (yes/no): ";
                string answer;
                getline(cin, answer);

                if (answer == "yes") {
                    path += "-yes";
                } else if (answer == "no") {
                    path += "-no";
                }
            }
        }
    }
};

int main() {
    AnimalGuessingGame game;

    cout << "Let's play the 'Guess the Animal' game." << endl;

    do {
        game.playGame();
        cout << "Try again? (yes/no): ";

        string playAgain;
        getline(cin, playAgain);

        if (playAgain != "yes") {
            break;
        }
    } while (true);

    return 0;
}
