# 🏦 Bank Management System

A **console-based Bank Management System** developed in **C++** as part of my **CodeAlpha Internship – Task 4**.

This project demonstrates the practical implementation of **Object-Oriented Programming (OOP)**, functions, arrays, input validation, authentication, transaction management, and basic banking operations.

---

## 📌 Project Overview

The Bank Management System allows customers to create profiles and bank accounts, securely log in, manage their balance, perform transactions, and view their transaction history.

The system is designed to simulate basic real-world banking operations through a simple and interactive command-line interface.

---

## ✨ Features

### 👤 Customer Management

* Create a new customer profile
* Generate a unique Customer ID
* Store customer name, phone number, CNIC, address, and date of birth
* View customer profile

### 🏦 Account Management

* Create Saving or Current accounts
* Assign accounts to existing customers
* Unique account number validation
* Minimum opening balance requirement of **Rs. 500**
* View account details

### 🔐 Authentication & Security

* Account login using account number and password
* Password validation
* Password requires:

  * Minimum 8 characters
  * At least one uppercase letter
  * At least one digit
* 4-digit MPIN validation
* Password and MPIN are hidden when displaying account details

### 💰 Banking Operations

* Deposit money
* Withdraw money
* Transfer money between accounts
* Check current balance
* Prevent withdrawals exceeding available balance
* Prevent transfers exceeding available balance
* MPIN verification for withdrawals and transfers

### 📊 Transaction Management

* Automatically generate transaction IDs
* Store transaction type
* Store transaction amount
* Store balance after transaction
* Store transaction date
* Store transaction description
* View transaction history for an account

### ✅ Input Validation

* 13-digit CNIC validation
* Name validation
* Password validation
* MPIN validation
* Account number uniqueness
* Customer ID verification
* Deposit and withdrawal amount validation
* Insufficient balance checking
* Receiver account verification
* Menu choice validation

---

## 🛠️ Technologies & Concepts

* **C++**
* Object-Oriented Programming (OOP)
* Classes & Objects
* Encapsulation
* Functions
* Arrays
* Strings
* Conditional Statements
* Loops
* References
* Input Validation
* Date & Time Handling
* Console-Based UI

### C++ Libraries Used

```cpp
#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <iomanip>
```

---

## 🧩 Main Classes

### `Customer`

Responsible for storing and managing customer information.

**Data includes:**

* Customer ID
* Name
* Phone Number
* CNIC
* Address
* Date of Birth

---

### `Account`

Handles bank account information and banking operations.

**Data includes:**

* Account Number
* Customer ID
* Account Type
* Balance
* Password
* MPIN
* Account Status

**Operations include:**

* Account creation
* Login
* Deposit
* Withdrawal
* Money transfer
* Account display

---

### `Transaction`

Stores information about banking transactions.

**Data includes:**

* Transaction ID
* Account Number
* Transaction Type
* Amount
* Balance After Transaction
* Date
* Description

---

## 📂 System Structure

The program uses arrays to maintain data:

```cpp
const int MAX_CUSTOMERS = 50;
const int MAX_ACCOUNTS = 100;
const int MAX_TRANSACTIONS = 500;
```

Therefore, the current implementation supports up to:

* **50 Customers**
* **100 Accounts**
* **500 Transactions**

---

## 🔄 Program Flow

```text
Start
  │
  ▼
Main Menu
  │
  ├── Login / Sign In
  │       │
  │       ├── Verify Account
  │       └── Customer Menu
  │              ├── View Profile
  │              ├── View Account
  │              ├── Deposit
  │              ├── Withdraw
  │              ├── Transfer
  │              ├── Transaction History
  │              └── Logout
  │
  ├── Sign Up
  │       │
  │       ├── Create Customer
  │       └── Create Account
  │
  └── Exit
```

---

## 💳 Transaction Types

The system supports:

| Transaction | Description                                 |
| ----------- | ------------------------------------------- |
| Deposit     | Adds money to the account                   |
| Withdrawal  | Removes money after MPIN verification       |
| Transfer    | Sends money to another account              |
| Received    | Records money received from another account |

---

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone YOUR_GITHUB_REPOSITORY_URL
```

### 2. Open the Project

Open the `.cpp` file in a C++ IDE such as:

* Code::Blocks
* Dev-C++
* Visual Studio
* VS Code with a C++ compiler

### 3. Compile and Run

Compile the program using a C++ compiler and run the generated executable.

> **Note:** This project uses `<windows.h>` and `Sleep()`, so it is intended for **Windows environments**.

---

## 🧪 Example Workflow

### Step 1 — Create Customer

```text
Main Menu
1) Login / Sign In
2) Sign Up
3) Exit

Choice: 2

1) Create Customer
2) Create Account
3) Go Back
```

Create a customer profile first.

### Step 2 — Create Account

Use the generated Customer ID to create a Saving or Current account.

The system requires an opening balance of at least:

```text
Rs. 500
```

### Step 3 — Login

Enter:

```text
Account Number
Password
```

After successful authentication, the Customer Menu will be displayed.

### Step 4 — Perform Transactions

The customer can:

```text
Deposit
Withdraw
Transfer
View Transaction History
```

---

## 🔒 Security & Validation

The project includes several validation mechanisms to make the banking simulation more reliable.

For example, passwords must contain:

```text
✓ Minimum 8 characters
✓ One uppercase letter
✓ One digit
```

MPIN must contain:

```text
✓ Exactly 4 digits
```

The system also verifies the MPIN before allowing withdrawals and transfers.

---

## 🎯 Learning Outcomes

Through this project, I improved my understanding of:

* Designing real-world applications using C++
* Object-Oriented Programming
* Creating classes and objects
* Encapsulation and private data members
* Passing objects by reference
* Managing multiple related data structures
* Implementing authentication
* Input validation
* Transaction processing
* Date and time handling
* Problem-solving and logical thinking

---

## 🚀 Future Improvements

Possible improvements for future versions include:

* File/database-based permanent data storage
* Admin dashboard
* Account blocking after multiple failed login attempts
* Better phone number validation
* Stronger password security
* Loan management
* Interest calculation
* ATM simulation
* Fund transfer receipts
* Search and filtering
* GUI using **Qt**
* Database integration

---

## 📌 Internship Information

**Internship:** CodeAlpha Internship
**Task:** Task 4
**Project:** Bank Management System
**Language:** C++
**Project Type:** Console-Based Application

---

## 👨‍💻 Developer

**Muhammad Ahmad**

This project was developed as part of my journey to strengthen my **C++ programming and software development skills** through practical projects.

---

## ⭐ Acknowledgment

Thanks to **CodeAlpha** for providing this internship opportunity and allowing me to work on practical programming projects.

If you find this project useful, feel free to ⭐ **star the repository** and explore the source code.

#CodeAlpha #CPlusPlus #Cpp #BankManagementSystem #OOP #Programming #Internship #SoftwareDevelopment
