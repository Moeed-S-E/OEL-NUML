# OEL

## Course Code: CSPF-121
## Programming Fundamentals
## Semester: 1

# Open Ended Lab Project :-  E-Commerce Shopping Cart System


## Overview

This project simulates an online store where users can view available items, add them to their shopping cart, and proceed to checkout. The store is pre-populated with a fixed set of products. Users can add items to their cart based on available stock, view their cart contents, and check out. The project demonstrates basic concepts of C++ programming such as data structures, loops, conditionals, and basic input/output operations.

## Project Details

The store system uses two main data structures:

### 1. **Item Structure**
Represents an item in the store (e.g., laptop, phone).
- `productID`: A unique identifier for the item.
- `name`: Name of the product.
- `category`: Category to which the product belongs (e.g., Electronics, Accessories).
- `price`: Price of the item (represented by a `double` to handle decimal values).
- `stock`: Number of units available in stock.

### 2. **CartItem Structure**
Represents an item added to the shopping cart.
- `item`: An instance of the `Item` structure.
- `quantity`: Number of units of the item added to the cart.

## Features

### 1. **Display Available Items**
The program displays the list of available items, including their ID, name, category, price, and stock availability.

### 2. **Add Items to Cart**
Users can select an item to add to the cart by entering its number (from the displayed list).
The program checks if the item is in stock and prompts the user for a valid quantity (i.e., a number between 1 and the available stock).
Users can add multiple items to the cart until the cart is full (maximum of 10 items).

### 3. **View Cart**
Users can view the contents of their cart, including the names, quantities, and total prices of the items they added.
The total price of the cart is calculated based on the quantities and prices of the items.

### 4. **Checkout**
When users are ready, they can proceed to checkout, which clears the cart and displays a message confirming the checkout is complete.

### 5. **Exit**
The user can choose to exit the program at any time.

## Requirements

- C++ compiler (e.g., GCC, Clang) to compile and run the program.
- Basic knowledge of C++ programming concepts such as arrays, loops, conditionals, and structures.
