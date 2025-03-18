#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class User {
public:
    string name;
    string phoneNumber;
    double balance;

    User(string n, string phone, double bal) : name(n), phoneNumber(phone), balance(bal) {}
};

class TelecomBillingSystem {
private:
    vector<User> users;
    
public:
    // User Management
    void addUser(string name, string phoneNumber, double balance) {
        users.push_back(User(name, phoneNumber, balance));
        cout << "User " << name << " added successfully!" << endl;
    }

    void displayUserInfo() {
        for (auto& user : users) {
            cout << "Name: " << user.name << ", Phone: " << user.phoneNumber << ", Balance: $" << fixed << setprecision(2) << user.balance << endl;
        }
    }

    // Usage Tracking
    void trackUsage(string phoneNumber, double usageAmount) {
        for (auto& user : users) {
            if (user.phoneNumber == phoneNumber) {
                user.balance -= usageAmount;
                cout << "Usage of $" << fixed << setprecision(2) << usageAmount << " tracked for " << user.name << endl;
                return;
            }
        }
        cout << "User not found!" << endl;
    }

    // Billing and Invoicing
    void generateInvoice(string phoneNumber) {
        for (auto& user : users) {
            if (user.phoneNumber == phoneNumber) {
                double invoiceAmount = user.balance;
                cout << "Invoice for " << user.name << " (" << user.phoneNumber << "): $" << fixed << setprecision(2) << invoiceAmount << endl;
                return;
            }
        }
        cout << "User not found!" << endl;
    }

    // Payment Processing
    void processPayment(string phoneNumber, double amount) {
        for (auto& user : users) {
            if (user.phoneNumber == phoneNumber) {
                user.balance += amount;
                cout << "Payment of $" << fixed << setprecision(2) << amount << " processed for " << user.name << endl;
                return;
            }
        }
        cout << "User not found!" << endl;
    }

    // Report and Analytics
    void generateReport() {
        double totalRevenue = 0;
        for (auto& user : users) {
            totalRevenue += user.balance;
        }
        cout << "Total revenue: $" << fixed << setprecision(2) << totalRevenue << endl;
    }
};

int main() {
    TelecomBillingSystem system;
    int choice;
    string name, phone;
    double balance, amount;

    do {
        cout << "\n--- Telecom Billing System ---" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Display All Users" << endl;
        cout << "3. Track Usage" << endl;
        cout << "4. Generate Invoice" << endl;
        cout << "5. Process Payment" << endl;
        cout << "6. Generate Report" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter user name: ";
                cin >> ws; // to handle the input of spaces in name
                getline(cin, name);
                cout << "Enter phone number: ";
                cin >> phone;
                cout << "Enter initial balance: $";
                cin >> balance;
                system.addUser(name, phone, balance);
                break;
            
            case 2:
                system.displayUserInfo();
                break;
            
            case 3:
                cout << "Enter phone number: ";
                cin >> phone;
                cout << "Enter usage amount: $";
                cin >> amount;
                system.trackUsage(phone, amount);
                break;
            
            case 4:
                cout << "Enter phone number: ";
                cin >> phone;
                system.generateInvoice(phone);
                break;
            
            case 5:
                cout << "Enter phone number: ";
                cin >> phone;
                cout << "Enter payment amount: $";
                cin >> amount;
                system.processPayment(phone, amount);
                break;
            
            case 6:
                system.generateReport();
                break;
            
            case 7:
                cout << "Exiting system..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 7);

    return 0;
}