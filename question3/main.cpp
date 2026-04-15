// Header comment by Trevor Romano
// this file drives the inventory menu for the smoothie shop

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "ingredient.h"
using namespace std;

int main() {
    vector<Ingredient> inventory;

    ifstream inputFile("ingredients.txt");
    if (!inputFile) {
        cout << "Error opening ingredients.txt" << endl;
        return 1;
    }

    string ingredientName;
    string category;
    int quantity;
    double price;
    int reorder;
    string supplier;

    while (inputFile >> ingredientName >> category >> quantity >> price >> reorder >> supplier) {
        Ingredient item(ingredientName, category, quantity, price, reorder, supplier);
        inventory.push_back(item);
    }

    inputFile.close();

    int choice;

    do {
        cout << "\nSmoothie Shop Inventory Management" << endl;
        cout << "1. Search by Category" << endl;
        cout << "2. List Ingredients Below Reorder Point" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Please enter your choice (1-3): ";
        cin >> choice;

        if (choice == 1) {
            string searchCategory;
            bool found = false;

            cout << "Enter category to search: ";
            cin >> searchCategory;

            for (size_t i = 0; i < inventory.size(); i++) {
                if (inventory[i].getCategory() == searchCategory) {
                    found = true;
                    break;
                }
            }

            if (found) {
                cout << "\n";
                cout << left << setw(18) << "Ingredient"
                     << setw(12) << "Category"
                     << right << setw(10) << "Quantity"
                     << setw(12) << "Price/lb"
                     << setw(16) << "Reorder Point"
                     << "  Supplier" << endl;
                cout << string(82, '-') << endl;

                for (size_t i = 0; i < inventory.size(); i++) {
                    if (inventory[i].getCategory() == searchCategory) {
                        inventory[i].PrintAll();
                    }
                }
            }
            else {
                cout << "Sorry, no " << searchCategory << " in inventory." << endl;
            }
        }
        else if (choice == 2) {
            bool anyNeedReorder = false;

            for (size_t i = 0; i < inventory.size(); i++) {
                if (inventory[i].needsReorder()) {
                    anyNeedReorder = true;
                    break;
                }
            }

            if (anyNeedReorder) {
                cout << "\n";
                cout << left << setw(18) << "Ingredient"
                     << setw(12) << "Category"
                     << right << setw(10) << "Quantity"
                     << setw(12) << "Price/lb"
                     << setw(16) << "Reorder Point"
                     << "  Supplier" << endl;
                cout << string(82, '-') << endl;

                for (size_t i = 0; i < inventory.size(); i++) {
                    if (inventory[i].needsReorder()) {
                        inventory[i].PrintAll();
                    }
                }
            }
            else {
                cout << "All ingredients are sufficiently stocked." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }

    } while (choice != 3);

    return 0;
}
