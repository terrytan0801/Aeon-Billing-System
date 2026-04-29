# Aeon-Billing-System
A C++ console-based AEON POS system with login, registration, inventory management, and billing features.

# 🛒 AEON POS System (C++)

This project is a console-based Point of Sale (POS) system developed in C++.  
It simulates a basic AEON supermarket system with user authentication and inventory management.

---

## 🔧 Features

- 🔐 User Authentication
  - Login system
  - Registration system

- 📦 Inventory Management
  - Multiple categories (Fruits, Canned Food, Drinks, Snacks)
  - Load stock data from `.txt` files
  - Track stock and sold items

- 🛒 POS System Interface
  - Menu-driven interface
  - User interaction via console

- 💾 File Handling
  - Read and write `.txt` files
  - Update stock data dynamically

---

## 📁 Project Structure
main.cpp // Main program (interface & control flow)
header.cpp // Function implementations
header.h // Declarations & struct definitions
global.cpp // Global variables (inventory arrays)

fruitstock.txt
canfoodstock.txt
drinksstock.txt
snackstock.txt
member_detail.txt


---

## ▶️ How to Run

```bash
g++ main.cpp header.cpp global.cpp -o main
./main


🚀 Future Improvements
🧾 Receipt generation
💰 Billing system (total calculation)
🔍 Search item feature
📊 Sales report (best-selling items)
🗂 Category-based UI

👨‍💻 Author

- Terry
- Alex
- Wong Xiao Tong
- Alan 
