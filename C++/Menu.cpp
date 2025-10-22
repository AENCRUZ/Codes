#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int MENU_SIZE = 4;
    string menuItems[MENU_SIZE] = {"Coffee", "Tea", "Sandwich", "Pastry"};
    double prices[MENU_SIZE] = {2.50, 1.75, 5.00, 3.00};

    int choice = 0;
    int quantity = 0;
    double totalCost = 0.0;

    cout << "Welcome to the Cafe!\n";
    cout << "Menu:\n";
    for (int i = 0; i < MENU_SIZE; ++i) {
        cout << i + 1 << ". " << menuItems[i] << " - $"
             << fixed << setprecision(2) << prices[i] << "\n";
    }

    while (true) {
        cout << "\nEnter the number of the item you'd like to order (0 to finish): ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > MENU_SIZE) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Enter the quantity: ";
        cin >> quantity;

        if (quantity < 0) {
            cout << "Quantity cannot be negative. Please try again.\n";
            continue;
        }

        double itemCost = prices[choice - 1] * quantity;
        totalCost += itemCost;

        cout << "Added " << quantity << " " << menuItems[choice - 1]
             << "(s) to your order. Item cost: $"
             << fixed << setprecision(2) << itemCost << "\n";
    }

    cout << "\nYour total order cost is: $"
         << fixed << setprecision(2) << totalCost << "\n";
    cout << "Thank you for ordering!\n";

    return 0;
}
