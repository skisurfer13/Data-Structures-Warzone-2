#include <iostream>
#include <string>
using namespace std;

struct AnimalNode {
    string question; // a question to ask the user
    string guess;    // the name of an animal to guess
    AnimalNode* yesAnswer; // null or pointer to the "yes" AnimalNode
    AnimalNode* noAnswer;  // null or pointer to the "no" AnimalNode
};

// Function to dynamically create a new AnimalNode
AnimalNode* createAnimalNode(const string& question, const string& guess, AnimalNode* yesAnswer, AnimalNode* noAnswer) {
    AnimalNode* newNode = new AnimalNode;
    newNode->question = question;
    newNode->guess = guess;
    newNode->yesAnswer = yesAnswer;
    newNode->noAnswer = noAnswer;
    return newNode;
}

// Function to play the game
void playGame(AnimalNode* currentNode) {
    cout << "Think of an animal and hit enter when you're ready." << endl;
    cin.ignore(); // clear the input buffer

    while (true) {
        if (currentNode->guess != "") {
            cout << "Is it a " << currentNode->guess << "? (yes/no)";
            string answer;
            getline(cin, answer);

            if (answer == "yes") {
                cout << "Good! I guessed your animal." << endl;
                break;
            }

            else if (answer == "no") {
                cout << "Bummer! What animal were you thinking of?" << endl;
                string newAnimal;
                getline(cin, newAnimal);

                cout << "What is a yes/no question that I can use to identify a " << newAnimal << "?" << endl;
                string newQuestion;
                getline(cin, newQuestion);

                cout << "For a " << newAnimal << ", is the answer yes or no? (yes/no)" << endl;
                string newAnswer;
                getline(cin, newAnswer);

                AnimalNode* newYesAnswer = (newAnswer == "yes") ? createAnimalNode("", newAnimal, nullptr, nullptr) : createAnimalNode("", currentNode->guess, nullptr, nullptr);
                AnimalNode* newNoAnswer = (newAnswer == "yes") ? createAnimalNode("", currentNode->guess, nullptr, nullptr) : createAnimalNode("", newAnimal, nullptr, nullptr);

                currentNode->question = newQuestion;
                currentNode->yesAnswer = newYesAnswer;
                currentNode->noAnswer = newNoAnswer;
                currentNode->guess = "";
                break;
            }
        }

        else {
            if (currentNode->yesAnswer == nullptr && currentNode->noAnswer == nullptr) {
                cout << "Is it a " << currentNode->guess << "? (yes/no)";
                string answer;
                getline(cin, answer);

                if (answer == "yes") {
                    cout << "Good! I guessed your animal." << endl;
                }

                else {
                    cout << "Bummer! I couldn't guess your animal." << endl;
                }
                break;
            }

            else {
                cout << currentNode->question << " (yes/no)";
                string answer;
                getline(cin, answer);

                if (answer == "yes") {
                    currentNode = currentNode->yesAnswer;
                }

                else if (answer == "no") {
                    currentNode = currentNode->noAnswer;
                }
            }
        }
    }
}


int main() {
    AnimalNode* rootNode = createAnimalNode("", "lizard", nullptr, nullptr);

    cout << "Let's play the 'Guess the Animal' game." << endl;

    // Do-while loop to execute the game till the user enters no
    do {
        playGame(rootNode);
        cout << "Try again? (yes/no)";

        string playAgain;
        getline(cin, playAgain);

        if (playAgain != "yes") {
            break;
        }
    } while (true);

    return 0;
}

// Test parameters for debugging sequence 
const string test_question = "Does it speak?";
const string test_guess = "Parrot";
AnimalNode* alphaAnswer = nullptr; // These are already nullptr
AnimalNode* betaAnswer = nullptr;  // These are already nullptr
AnimalNode* rootNode = nullptr;

// Function to initialize test parameters 
void SetupTestParameters() {
    // Setting up test parameters
    alphaAnswer = createAnimalNode("Does it bark?", "dog", nullptr, nullptr);
    betaAnswer = createAnimalNode("Does it fly?", "bird", nullptr, nullptr);
    rootNode = createAnimalNode("Does it speak?", "", alphaAnswer, betaAnswer);
}




