#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter number: ";
    cin >> num;

    if (num > 0) {
        cout << "number " << num << " is a POSITIVE number";
    } else if (num < 0) {
        cout << "number " << num << " is a NEGATIVE number";
    } else if (num == 0) {
        cout << "number " << num << " is ZERO";
    } else {
        cout << "INVALID";
    }

    return 0;
}

