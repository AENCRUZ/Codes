#include <iostream>
using namespace std;

int main() {
    int grade;
    cout << "Input your Grade: ";
    cin >> grade;

    if (grade >= 90) {
        cout << "A";
    } 
    else if (grade >= 80 && grade <= 89) {
        cout << "B";
    } 
    else if (grade >= 70 && grade <= 79) {
        cout << "C";
    } 
    else if (grade >= 60 && grade <= 69) {
        cout << "D";
    } 
    else if (grade <= 59) {
        cout << "F";
    } 
    else {
        cout << "INVALID";
    }

    return 0;
}