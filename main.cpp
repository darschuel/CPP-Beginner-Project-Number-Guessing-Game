#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int randomNumGenerator() {
    srand(time(nullptr));
    return rand() % 100 + 1;
}

int main() {
    int randomNum = randomNumGenerator();
    int guess;
    cout << randomNum;
    //cout << "I have chosen a number from 1 and 100.\nTry to guess it!\n\n";
    //cout << "Your guess: \n";

    //cin >> guess;


    return 0;
}