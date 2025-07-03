#include <iostream>
#include <vector>
using namespace std;

struct Account {
    int accNumber;
    string name;
    double balance;
};

vector<Account> accounts;

void createAccount() {
    Account acc;
    cout << "Enter Account Number: ";
    cin >> acc.accNumber;
    cout << "Enter Name: ";
    cin >> acc.name;
    cout << "Enter Initial Balance: ";
    cin >> acc.balance;
    accounts.push_back(acc);
    cout << "Account created!\n";
}

void displayAccounts() {
    for (int i = 0; i < accounts.size(); i++) {
        cout << "Acc No: " << accounts[i].accNumber
             << ", Name: " << accounts[i].name
             << ", Balance: " << accounts[i].balance << endl;
    }
}

void depositMoney(int accNum, double amount) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNumber == accNum) {
            accounts[i].balance += amount;
            cout << "Deposit successful! New Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

void withdrawMoney(int accNum, double amount) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNumber == accNum) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                cout << "Withdrawal successful! New Balance: " << accounts[i].balance << endl;
            } else {
                cout << "Insufficient balance!\n";
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

void searchAccount(int accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNumber == accNum) {
            cout << "Found: " << accounts[i].name << ", Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

void deleteAccount(int accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNumber == accNum) {
            accounts.erase(accounts.begin() + i);
            cout << "Account deleted.\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

int main() {
    int choice, accNum;
    double amount;

    do {
        cout << "--Bank Management System--\n";
        cout << "1. Create Account\n2. Display Accounts\n3. Deposit\n4. Withdraw\n5. Search\n6. Delete\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3:
                cout << "Enter Acc No: "; cin >> accNum;
                cout << "Amount to deposit: "; cin >> amount;
                depositMoney(accNum, amount); break;
            case 4:
                cout << "Enter Acc No: "; cin >> accNum;
                cout << "Amount to withdraw: "; cin >> amount;
                withdrawMoney(accNum, amount); break;
            case 5:
                cout << "Enter Acc No: "; cin >> accNum;
                searchAccount(accNum); break;
            case 6:
                cout << "Enter Acc No: "; cin >> accNum;
                deleteAccount(accNum); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

