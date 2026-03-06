# Login and Registration System in C++

## Project Overview

This project implements a simple **Login and Registration System in C++** using file handling.
The system allows users to register with a username and password, store their credentials in a local file, and log in using those credentials.

The program follows a **modular and object-oriented design**, ensuring clean structure and easy maintainability. It also performs validation to ensure usernames are unique and credentials meet minimum requirements.

## Features

* User Registration with username and password
* Username uniqueness validation
* Minimum credential length validation
* Secure storage of credentials in a local file
* User login authentication
* Clear console messages for user feedback
* Menu-driven interface
* Modular implementation using a class

## Technologies Used

* Programming Language: C++
* Concepts Used:

  * Object-Oriented Programming (OOP)
  * File Handling (ifstream, ofstream)
  * String Manipulation
  * Conditional Statements
  * Loops

## File Structure

LoginSystem.cpp
users.txt (created automatically after first registration)

* **LoginSystem.cpp** contains the entire program logic.
* **users.txt** acts as a local database storing user credentials.

## Credential Storage Format

User credentials are stored in the file using the following format:

username:password

Example:

hetarth123:pass123
john456:hello789
alice999:secure456

Each line represents one registered user.

## Program Workflow

### 1. Registration

* User enters a username and password.
* The system validates:

  * Username and password must contain at least 5 characters.
  * Username must not already exist in the database.
* If validation succeeds, credentials are saved to the file.

### 2. Login

* User enters their username and password.
* The program reads the database file line by line.
* Stored credentials are compared with the input.
* Access is granted only if both match exactly.

### 3. Exit

* Terminates the application.

## How File Handling Works

The system uses C++ file streams to manage user data.

* **ifstream** is used to read the database file.
* **ofstream** with append mode is used to add new users.

When reading the file:

1. Each line is read using `getline`.
2. The program locates the `:` separator.
3. Username and password are extracted using string substrings.
4. Extracted credentials are compared with user input.

## Compilation and Execution

### Compile

g++ LoginSystem.cpp -o LoginSystem

### Run

./LoginSystem

For Windows:
LoginSystem.exe

## Example Menu

===== Login System Menu =====

1. Register
2. Login
3. Exit

Enter choice:

## Possible Future Improvements

* Password hashing for improved security
* Password hiding during input
* Password reset functionality
* User profile management
* Graphical User Interface (GUI)

## Author

Hetarth Bhavsar
