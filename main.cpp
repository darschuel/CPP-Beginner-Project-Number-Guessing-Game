#include <iostream>
#include <string>
#include <random>
#include <limits>


using namespace std;

int randomNumGenerator() {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> dist(1,100);
    return dist(generator);
}

int readInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please type a valid number!\n";
    }
    return value;
}

string higherOrLower(int guess, int randomNum) {
    string convo;
    if (guess > randomNum) {
        convo = "Too high! Try again!\n";
    } else if (guess < randomNum) {
        convo = "Too low! Try again!\n";
    } else {
        convo = "Correct! You won!\n";
    }
    return convo;
}

void numberChecker(int& attempts, int randomNum) {
    while (true) {
        int guess;

        cout << "Your guess: \n";
        guess = readInt();

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number between 1 and 100!\n";
            continue;
        }
        attempts++;
        cout << higherOrLower(guess, randomNum) << endl;

        if (guess == randomNum) {
            break;
        }
    }
}

int main() {
    while (true) {
        string retry;
        int attempts = 0;
        int randomNum = randomNumGenerator();
        cout << "I have chosen a number from 1 to 100.\nTry to guess it!\n\n";
        numberChecker(attempts, randomNum);


        cout << "Number of attempts: " << attempts << endl;
        while (true) {
            cout << "Try again? (Yes/No): " << endl;
            cin >> retry;
            if (retry == "Yes" || retry == "No") { break; }
            cout << "Please type a valid answer!\n";
        }
        if (retry == "No") {
            cout << "Thank you for playing!\n";
            break;
        }
    }

    return 0;
}