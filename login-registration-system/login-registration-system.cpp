#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class UserSystem {
private:
    string databaseFile = "users.txt";

public:

    // Function to check if username already exists in file
    bool usernameExists(string username) {
        ifstream file(databaseFile);
        string line, storedUser, storedPass;

        // Read file line by line
        while (getline(file, line)) {
            int pos = line.find(':'); // Find separator position
            storedUser = line.substr(0, pos); // Extract username

            if (storedUser == username) {
                file.close();
                return true; // Username already exists
            }
        }

        file.close();
        return false; // Username not found
    }

    // Registration function
    void registerUser() {
        string username, password;

        cout << "\n--- User Registration ---\n";
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        // Validation
        if (username.length() < 5 || password.length() < 5) {
            cout << "Error: Username and Password must be at least 5 characters long.\n";
            return;
        }

        // Check if username already exists
        if (usernameExists(username)) {
            cout << "Username Taken. Please choose another.\n";
            return;
        }

        // Open file in append mode to add new user
        ofstream file(databaseFile, ios::app);

        /*
        File I/O Logic:
        ios::app ensures data is added to the end of the file
        Each user is stored in format:
        username:password
        Example:
        john123:pass123
        */

        file << username << ":" << password << endl;

        file.close();

        cout << "Registration Successful!\n";
    }

    // Login function
    void loginUser() {
        string username, password;
        string line, storedUser, storedPass;

        cout << "\n--- User Login ---\n";
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ifstream file(databaseFile);

        bool loginSuccess = false;

        /*
        File Reading Logic:
        The program reads each line from the file,
        separates username and password using ':' delimiter,
        then compares them with user input.
        */

        while (getline(file, line)) {
            int pos = line.find(':');

            storedUser = line.substr(0, pos);
            storedPass = line.substr(pos + 1);

            if (storedUser == username && storedPass == password) {
                loginSuccess = true;
                break;
            }
        }

        file.close();

        if (loginSuccess)
            cout << "Login Successful! Access Granted.\n";
        else
            cout << "Login Failed. Invalid username or password.\n";
    }
};

int main() {
    UserSystem system;
    int choice;

    while (true) {
        cout << "\n===== Login System Menu =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.registerUser();
            break;

        case 2:
            system.loginUser();
            break;

        case 3:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}