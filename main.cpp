#include <iostream>
using namespace std;

class ATM {
private:
    double balance;
    string pin;

public:
    // Constructor to initialize the ATM with a starting balance and pin
    ATM(double initial_balance, string initial_pin) {
        balance = initial_balance;
        pin = initial_pin;
    }

    // Function to check if the entered pin is correct
    bool authenticate(string entered_pin) {
        return entered_pin == pin;
    }

    // Function to display the current balance
    void checkBalance() {
        cout << "Current balance: $" << balance << endl;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: $" << amount << endl;
            checkBalance();
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << endl;
            checkBalance();
        } else {
            cout << "Invalid amount or insufficient balance." << endl;
        }
    }
};

int main() {
    // Create an ATM object with an initial balance of $1000 and a pin
    ATM myATM(1000.0, "1234");

    string entered_pin;
    cout << "Welcome to the ATM service." << endl;
    cout << "Please enter your PIN: ";
    cin >> entered_pin;

    if (myATM.authenticate(entered_pin)) {
        int choice;
        do {
            cout << "\nATM Menu:" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    myATM.checkBalance();
                    break;
                case 2: {
                    double deposit_amount;
                    cout << "Enter the amount to deposit: $";
                    cin >> deposit_amount;
                    myATM.deposit(deposit_amount);
                    break;
                }
                case 3: {
                    double withdraw_amount;
                    cout << "Enter the amount to withdraw: $";
                    cin >> withdraw_amount;
                    myATM.withdraw(withdraw_amount);
                    break;
                }
                case 4:
                    cout << "Thank you for using the ATM service. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    } else {
        cout << "Invalid PIN. Access denied." << endl;
    }

    return 0;
}
