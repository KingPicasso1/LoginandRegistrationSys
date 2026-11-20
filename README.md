# LoginandRegistrationSys
A lightweight, console-based authentication system written in C++ using standard file handling (`fstream`) to store and verify user credentials.
# C++ Login & Registration System

A lightweight, console-based authentication system written in C++ using standard file handling (`fstream`) to store and verify user credentials.

## ✨ Features
- **User Registration:** Create a new account with duplicate-username validation.
- **User Login:** Authenticate credentials against stored records.
- **Persistent Storage:** Saves user data locally in `users.txt`.
- **Input Validation:** Handles invalid menu entries gracefully.

## 🛠️ Tech Stack
- **Language:** C++ (C++11 or later)
- **Libraries:** `<iostream>`, `<fstream>`, `<string>`


## ⚠️ Note
This project is built for learning file I/O and basic authentication logic in C++. Passwords are stored in plain text—for production applications, always use cryptographic hashing (e.g., SHA-256 or bcrypt via OpenSSL).


