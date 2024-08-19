#include <iostream>
#include <string>
using namespace std;

enum StateType { QUESTION, GUESS };

struct State {
    StateType type;
    string value;  // The question or animal guess
    State* yesState;
    State* noState;

    State(StateType t, const string& val) : type(t), value(val), yesState(nullptr), noState(nullptr) {}
};

class AnimalGuessingFSM {
private:
    State* rootState;

public:
    AnimalGuessingFSM() {
        // Initialize with a simple guess
        rootState = new State(GUESS, "lizard");
    }

    void playGame(State* currentState) {
        cout << "Think of an animal and hit enter when you're ready." << endl;
        cin.ignore(); // Clear the input buffer

        while (true) {
            if (currentState->type == GUESS) {
                // If the state is a guess
                cout << "Is it a " << currentState->value << "? (yes/no): ";
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

                    // Create new states for the new animal and the current guess
                    State* yesState = (newAnswer == "yes") ? new State(GUESS, newAnimal) : new State(GUESS, currentState->value);
                    State* noState = (newAnswer == "yes") ? new State(GUESS, currentState->value) : new State(GUESS, newAnimal);

                    // Replace the current guess with the new question
                    currentState->value = newQuestion;
                    currentState->type = QUESTION;
                    currentState->yesState = yesState;
                    currentState->noState = noState;
                    break;
                }
            } else {
                // If the state is a question
                cout << currentState->value << " (yes/no): ";
                string answer;
                getline(cin, answer);

                if (answer == "yes") {
                    currentState = currentState->yesState;
                } else if (answer == "no") {
                    currentState = currentState->noState;
                }
            }
        }
    }

    void startGame() {
        do {
            playGame(rootState);
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
    AnimalGuessingFSM game;
    cout << "Let's play the 'Guess the Animal' game." << endl;
    game.startGame();
    return 0;
}
