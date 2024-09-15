#include <iostream>
#include <vector>
using namespace std;

// Base class
class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    // Encapsulation: Using methods to access and modify private data
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    // Abstraction: Pure virtual function
    virtual void calculateInterest() = 0;

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double bal) {
        balance = bal;
    }
};

// Derived class for Savings Account
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, double rate) : Account(accNum, bal), interestRate(rate) {}

    void calculateInterest() override {
        balance += balance * interestRate;
    }

    void display() const override {
        cout << "Savings Account - ";
        Account::display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

// Derived class for Current Account
class CurrentAccount : public Account {
public:
    CurrentAccount(int accNum, double bal) : Account(accNum, bal) {}

    void calculateInterest() override {
        // No interest for current accounts
    }

    void display() const override {
        cout << "Current Account - ";
        Account::display();
    }
};

// Encapsulation: Class with private members and public methods
class Customer {
private:
    string name;
    vector<Account*> accounts;

public:
    Customer(string n) : name(n) {}

    void addAccount(Account* account) {
        accounts.push_back(account);
    }

    void displayAccounts() const {
        cout << "Customer: " << name << endl;
        for (const auto& account : accounts) {
            account->display();
        }
    }

    void transferFunds(int fromAccNum, int toAccNum, double amount) {
        Account* fromAccount = nullptr;
        Account* toAccount = nullptr;

        for (auto& account : accounts) {
            if (account->getAccountNumber() == fromAccNum) {
                fromAccount = account;
            }
            if (account->getAccountNumber() == toAccNum) {
                toAccount = account;
            }
        }

        if (fromAccount && toAccount) {
            if (fromAccount->getBalance() >= amount) {
                fromAccount->withdraw(amount);
                toAccount->deposit(amount);
                cout << "Transfer successful!" << endl;
            } else {
                cout << "Insufficient balance for transfer!" << endl;
            }
        } else {
            cout << "Invalid account number(s)!" << endl;
        }
    }

    void displayTotalBalance() const {
        double totalBalance = 0;
        for (const auto& account : accounts) {
            totalBalance += account->getBalance();
        }
        cout << "Total Balance for " << name << ": " << totalBalance << endl;
    }
};

int main() {
    // Creating accounts
    SavingsAccount savings(1001, 5000.0, 0.03);
    CurrentAccount current(1002, 10000.0);

    // Creating customer
    Customer customer("Alice");
    customer.addAccount(&savings);
    customer.addAccount(&current);

    // Displaying customer accounts
    customer.displayAccounts();

    // Performing transactions
    savings.deposit(1000);
    current.withdraw(2000);

    // Calculating interest
    savings.calculateInterest();

    // Displaying updated accounts
    customer.displayAccounts();

    // Transferring funds
    customer.transferFunds(1001, 1002, 500);

    // Displaying updated accounts after transfer
    customer.displayAccounts();

    // Displaying total balance
    customer.displayTotalBalance();

    return 0;
}
