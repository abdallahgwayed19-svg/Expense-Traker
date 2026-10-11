#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Expense {
    string description;
    double amount;
    string category;
};

void saveToFile(const vector<Expense>& expenses) {
    ofstream outFile("expenses.txt");
    if (!outFile) {
        cout << "Error: Could not open file for saving data.\n";
        return;
    }
    for (const auto& e : expenses) {
        outFile << e.description << "," << e.amount << "," << e.category << "\n";
    }
    outFile.close();
}

void loadFromFile(vector<Expense>& expenses) {
    ifstream inFile("expenses.txt");
    if (!inFile) {
        return;
    }
    Expense e;
    string amountStr;
    while (getline(inFile, e.description, ',') && 
           getline(inFile, amountStr, ',') && 
           getline(inFile, e.category)) {
        e.amount = stod(amountStr);
        expenses.push_back(e);
    }
    inFile.close();
}

void addExpense(vector<Expense>& expenses) {
    Expense e;
    cout << "\n--- Add New Expense ---\n";
    cout << "Enter description: ";
    cin.ignore();
    getline(cin, e.description);
    
    cout << "Enter amount: ";
    cin >> e.amount;
    
    cout << "Enter category: ";
    cin.ignore();
    getline(cin, e.category);
    
    expenses.push_back(e);
    saveToFile(expenses);
    cout << "Expense added and saved successfully!\n\n";
}

void displayExpenses(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "\nNo expenses tracked yet.\n\n";
        return;
    }
    cout << "\n---------------- Expense List ----------------\n";
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << i + 1 << ". Description: " << expenses[i].description 
             << " | Amount: " << expenses[i].amount 
             << " | Category: " << expenses[i].category << "\n";
    }
    cout << "----------------------------------------------\n\n";
}

void showTotalExpenses(const vector<Expense>& expenses) {
    double total = 0;
    for (const auto& e : expenses) {
        total += e.amount;
    }
    cout << "\n========================================\n";
    cout << " Total Expenses: " << total << "\n";
    cout << "========================================\n\n";
}

int main() {
    vector<Expense> expenses;
    int choice;

    loadFromFile(expenses);

    while (true) {
        cout << "=== Expense Tracker System ===\n";
        cout << "1. Add Expense\n";
        cout << "2. Display All Expenses\n";
        cout << "3. Calculate Total Expenses\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addExpense(expenses);
        } else if (choice == 2) {
            displayExpenses(expenses);
        } else if (choice == 3) {
            showTotalExpenses(expenses);
        } else if (choice == 4) {
            cout << "Data saved. Exiting program...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n\n";
        }
    }
    return 0;
} 
    
    
