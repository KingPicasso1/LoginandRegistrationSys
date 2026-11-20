#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string DATA_FILE = "users.txt";

bool userExists(const string& username) {
    ifstream file(DATA_FILE);
    string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "\n--- Register ---\n";
    cout << "Enter username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Error: Username already exists. Try another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(DATA_FILE, ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error: Unable to open data file.\n";
    }
}

void loginUser() {
    string username, password, storedUser, storedPass;
    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(DATA_FILE);
    bool authenticated = false;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            authenticated = true;
            break;
        }
    }
    file.close();

    if (authenticated) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n=== Login & Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
