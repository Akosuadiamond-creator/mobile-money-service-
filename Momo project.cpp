 
#include <iostream>
using namespace std;

string pin = "000";
double balance = 1000.00;
int attempts = 0;

void authenticate() {
     string input_pin;
    cout << "Enter your PIN: ";
    cin >> input_pin;
    if (input_pin != pin) {
        attempts++;
        if (attempts >= 3) {
            cout << "You've entered your PIN incorrectly 3 times. Exiting program." << endl;
            exit(0);
        } else {
            cout << "Invalid PIN. Please try again." << endl;
            authenticate();
        }
    } else {
        cout << "Authentication successful." << endl;
    }
}

void reset_pin() {
    string new_pin;
    cout << "Enter your new PIN: ";
    cin >> new_pin;
    pin = new_pin;
    cout << "Your PIN has been reset successfully." << endl;
}

void check_balance() {
    cout << "Your current balance is $" << balance << "." << endl;
}

void send_money() {
    double amount;
    string destination;
    cout << "Enter the amount you want to send: $";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient funds." << endl;
        send_money();
    } else {
        cout << "Enter the destination mobile number: ";
        cin >> destination;
        balance -= amount;
        cout << "$" << amount << " has been sent to " << destination << "." << endl;
    }
}

int main() {
    int option;
    do {
        cout << "Welcome to our mobile money service." << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset PIN" << endl;
        cout << "3. Checkbalance" << endl;
        cout << "4. Send money" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        switch (option) {
            case 1:
                authenticate();
                break;
            case 2:
                reset_pin();
                break;
            case 3:
                check_balance();
                break;
            case 4:
                send_money();
                break;
            case 5:
                cout << "Thank you for using our mobile money service." << endl;
                break;
            default:
                cout << "Invalid option. Please choose a number from 1 to 5." << endl;
        }
    } while (option != 5);
    return 0;}
