#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to represent an expense
struct Expense {
    int id;         // Unique ID for each expense
    string name;    // Name or description of the expense
    double amount;  // Amount spent
};

double allowance = 0.0; // Weekly allowance
vector<Expense> expenses; // List of expenses
int nextId = 1; // To assign unique IDs to expenses

// Function prototypes
void setAllowance();     // Sets the weekly allowance
void addExpense();       // Adds a new expense to the list
void viewExpenses();     // Displays all recorded expenses
void updateExpense();    // Updates an existing expense
void deleteExpense();    // Deletes an expense by ID
void showMenu();         // Displays the main menu
void checkAllowance();   // Warns the user if the allowance is low or used up

int main() {
    int choice; // User's menu choice

    do {
        showMenu(); // Display menu options
        cout << "Enter your choice: ";
        cin >> choice;

        // Process user's choice
        switch (choice) {
            case 1: setAllowance(); break;
            case 2: addExpense(); break;
            case 3: viewExpenses(); break;
            case 4: updateExpense(); break;
            case 5: deleteExpense(); break;
            case 6: cout << "Exiting program. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6); // Keep running until user chooses to exit

    return 0;
}

// Function: Displays the main menu options
void showMenu() {
    cout << endl << "=== Allowance and Expense Tracker ===" << endl;
    cout << "1. Set Weekly Allowance" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. View Expenses" << endl;
    cout << "4. Update Expense" << endl;
    cout << "5. Delete Expense" << endl;
    cout << "6. Exit" << endl;
}

// Function: Sets the user's weekly allowance
void setAllowance() {
    cout << "Enter your weekly allowance: ";
    cin >> allowance;

    if (allowance < 0) { // Validate that the allowance is not negative
        cout << "Allowance cannot be negative. Please try again." << endl;
        return;
    }

    cout << "Allowance set to PHP " << fixed << setprecision(2) << allowance << "." << endl;
    checkAllowance(); // Warn the user if allowance is low
}

// Function: Adds a new expense
void addExpense() {
    if (allowance <= 0) { // Ensure allowance is set before adding an expense
        cout << "Please set your allowance first." << endl;
        return;
    }

    Expense exp; // Create a new expense
    exp.id = nextId++; // Assign a unique ID to the expense

    cout << "Enter expense name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, exp.name);

    cout << "Enter expense amount: ";
    cin >> exp.amount;

    if (exp.amount < 0) { // Ensure expense amount is valid
        cout << "Expense amount cannot be negative." << endl;
        return;
    }

    if (exp.amount > allowance) { // Check if there's enough allowance for the expense
        cout << "Insufficient allowance for this expense." << endl;
        return;
    }

    allowance -= exp.amount; // Deduct expense amount from allowance
    expenses.push_back(exp); // Add the expense to the list
    cout << "Expense added successfully! Remaining allowance: PHP " 
         << fixed << setprecision(2) << allowance << "." << endl;
    checkAllowance();
}

// Function: Displays all recorded expenses
void viewExpenses() {
    if (expenses.empty()) { // Check if there are no expenses
        cout << "No expenses recorded yet." << endl;
        return;
    }

    cout << endl << "=== Expenses ===" << endl;
    cout << "ID   Name                Amount" << endl;
    cout << "--------------------------------" << endl;

    for (const auto& exp : expenses) { // Loop through all expenses and display them
        cout << setw(4) << exp.id << "   " << setw(18) << left << exp.name 
             << "PHP " << fixed << setprecision(2) << exp.amount << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Remaining allowance: PHP " << fixed << setprecision(2) << allowance << "." << endl;
    checkAllowance();
}

// Function: Updates an existing expense by ID
void updateExpense() {
    int id;
    cout << "Enter the ID of the expense to update: ";
    cin >> id;

    for (auto& exp : expenses) { // Find the expense by ID
        if (exp.id == id) {
            cout << "Enter new expense name: ";
            cin.ignore();
            getline(cin, exp.name);

            double newAmount;
            cout << "Enter new expense amount: ";
            cin >> newAmount;

            if (newAmount < 0) { // Ensure the new amount is valid
                cout << "Expense amount cannot be negative." << endl;
                return;
            }

            if (newAmount > allowance + exp.amount) { // Check for sufficient allowance
                cout << "Insufficient allowance for this update." << endl;
                return;
            }

            allowance += exp.amount; // Refund the old amount
            exp.amount = newAmount; // Update to the new amount
            allowance -= newAmount; // Deduct the new amount
            cout << "Expense updated successfully! Remaining allowance: PHP " 
                 << fixed << setprecision(2) << allowance << "." << endl;
            checkAllowance();
            return;
        }
    }

    cout << "Expense with ID " << id << " not found." << endl;
}

// Function: Deletes an expense by ID
void deleteExpense() {
    int id;
    cout << "Enter the ID of the expense to delete: ";
    cin >> id;

    for (auto it = expenses.begin(); it != expenses.end(); ++it) { // Find the expense by ID
        if (it->id == id) {
            allowance += it->amount; // Refund the deleted expense amount
            expenses.erase(it); // Remove the expense from the list
            cout << "Expense deleted successfully! Remaining allowance: PHP " 
                 << fixed << setprecision(2) << allowance << "." << endl;
            checkAllowance();
            return;
        }
    }

    cout << "Expense with ID " << id << " not found." << endl;
}

// Function: Warns the user if allowance is low or fully used up
void checkAllowance() {
    static double initialAllowance = allowance; // Save the initial allowance
    const double warningThreshold = 0.2 * initialAllowance; // 20% of the initial allowance

    if (allowance <= 0) { // No allowance left
        cout << "WARNING: Your allowance is completely used up. Be careful with your spending!" << endl;
    } else if (allowance < warningThreshold) { // Allowance is low
        cout << "Reminder: Your remaining allowance is low. Spend wisely!" << endl;
    }
}
