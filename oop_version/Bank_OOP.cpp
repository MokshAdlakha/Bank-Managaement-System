#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accNumber;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNumber;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void display() const {
        cout << "Acc No: " << accNumber
             << ", Name: " << name
             << ", Balance: " << balance << endl;
    }

    int getAccNumber() const {
        return accNumber;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful! New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful! New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void showDetails() const {
        cout << "Found: " << name << ", Balance: " << balance << endl;
    }
};

vector<Account> accounts;

void createAccount() {
    Account acc;
    acc.createAccount();
    accounts.push_back(acc);
    cout << "Account created!\n";
}

void displayAccounts() {
    for (int i = 0; i < accounts.size(); i++) {
        accounts[i].display();
    }
}

void depositMoney(int accNum, double amount) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccNumber() == accNum) {
            accounts[i].deposit(amount);
            return;
        }
    }
    cout << "Account not found!\n";
}

void withdrawMoney(int accNum, double amount) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccNumber() == accNum) {
            accounts[i].withdraw(amount);
            return;
        }
    }
    cout << "Account not found!\n";
}

void searchAccount(int accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccNumber() == accNum) {
            accounts[i].showDetails();
            return;
        }
    }
    cout << "Account not found!\n";
}

void deleteAccount(int accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccNumber() == accNum) {
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
        cout << "\n-- Bank Management System (OOP Version) --\n";
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
