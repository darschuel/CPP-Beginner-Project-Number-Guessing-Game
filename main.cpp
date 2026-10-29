#include <iostream>
#include <string>

using namespace std;

int randomNumGenerator() {
    srand(time(nullptr));
    return rand() % 100 + 1;
}

string higherOrLower(int guess, int randomNum) {
    string convo;
    if (guess > randomNum) {
        convo = "Too high! Try again!\n";
    } else if (guess < randomNum) {
        convo = "Too low! Try again!\n";
    } else if (guess == randomNum) {
        convo = "Correct! You won!\n";
    }
    return convo;
}

void numberChecker(int attempts, int randomNum, int guess) {
    while (true) {
        attempts++;
        int nextTryGuess;
        cout << higherOrLower(guess, randomNum);
        if (guess == randomNum) { break; }
        cin >> nextTryGuess;
        guess = nextTryGuess;
    }
}

int main() {
    while (true) {
        string retry;
        int attempts = 0;
        int randomNum = randomNumGenerator();
        int guess;
        cout << "I have chosen a number from 1 and 100.\nTry to guess it!\n\n";
        cout << "Your guess: \n";

        cin >> guess;
        numberChecker(attempts, randomNum, guess);

        cout << "Number of attempts: " << attempts << endl;
        while (true) {
            cout << "Try again? (Yes/No): " << endl;
            cin >> retry;
            if (retry == "Yes" || retry == "No") { break; };
            cout << "Please type a valid answer!\n";
        }
        if (retry == "No") {
            cout << "Thank you for playing!\n";
            break;
        }
    }

    return 0;
}