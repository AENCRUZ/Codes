#include <iostream>
using namespace std;

int main() {
    char letter;

    cout << "Enter a letter: ";
    cin >> letter;

    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        cout << "VOWEL";
    } else {
        cout << "CONSONANT";
    }

    return 0;
}


