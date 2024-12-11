E-commerce Shopping Cart System - Report
========================================

1\. Introduction
----------------

The E-commerce Shopping Cart System is designed to simulate the typical shopping experience in an online store. The primary objective of this system is to provide a platform for users to browse available items, add items to their shopping cart, update the quantity of items, remove items from the cart, and proceed with the checkout process.

This project implements core functionalities of an online shopping experience using basic programming techniques. The system is designed in C++ and utilizes structures, arrays, loops, functions, and a switch-case statement to implement the required operations. The system is simple, intuitive, and easy to extend, making it suitable for beginner-level programmers.

2\. Project Objectives
----------------------

*   Simulate an e-commerce shopping cart experience.
    
*   Implement functions for adding, updating, and removing items in the cart.
    
*   Display the total price of items in the cart.
    
*   Use an array of structures to store item details like name, price, and stock.
    
*   Utilize loops for cart operations.
    
*   Use a switch-case menu to allow the user to interact with the system.
    
*   Design the program in a way that is easy to understand for novice programmers.
    

3\. Methodology
---------------

The system was developed using **C++** and involves the following steps:

1.  **Define Structures**: The program uses two primary structures: one for storing product details (name, price, stock) and another for managing the cart (which includes references to the items and their quantities).
    
2.  **Menu System**: The user interacts with the system through a simple text-based menu. The menu allows users to browse items, add them to the cart, view their cart, update quantities, remove items, and check out.
    
3.  **Functions Implementation**:
    
    *   **Display Items**: Shows the available items in the store.
        
    *   **Add to Cart**: Lets the user add items to the cart, checking for stock availability.
        
    *   **Update Cart**: Allows the user to update the quantity of an item already in the cart.
        
    *   **Remove from Cart**: Lets the user remove an item from the cart.
        
    *   **Checkout**: Clears the cart and provides a simple checkout message.
        
4.  **User Input Validation**: The system ensures that the user enters valid quantities, and that items are not added beyond available stock or cart capacity.
    
5.  **Cart Management**: The cart is implemented using a vector (dynamic array) to manage items and their quantities. This allows easy updates, additions, and removals.
    

4\. Code Explanation
--------------------

### 4.1. Data Structures

Two main structures are used:

1.  struct Item { int productID; string name; string category; double price; int stock;};
    
2.  struct CartItem { Item\* item; // Pointer to an item in the store int quantity;};
    

### 4.2. Key Functions

1.  void displayItems(const vector& storeItems) { // Iterates through each item in the storeItems vector}
    
2.  int getValidQuantity(int availableStock) { // Continuously prompts the user for a valid quantity}
    
3.  void addToCart(vector& storeItems, vector& cart, int& cartSize, const int MAX\_CART) { // Adds the item to the cart if space is available}
    
4.  void updateQuantityInCart(vector& cart) { // Updates the quantity based on user input}
    
5.  void removeFromCart(vector& cart) { // Removes the item from the cart}
    
6.  void viewCart(const vector& cart) { // Displays cart items and calculates total price}
    
7.  void checkout(int& cartSize, vector& cart) { // Clears the cart after checkout}
    

### 4.3. Main Program Flow

The program starts by displaying a menu with options for the user. The menu includes the following choices:

1.  Display available items.
    
2.  Add an item to the cart.
    
3.  View the cart and total price.
    
4.  Update the quantity of an item in the cart.
    
5.  Remove an item from the cart.
    
6.  Proceed to checkout.
    
7.  Exit the program.
    
````
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Item's Structure
struct Item
{
    int productID;
    string name;
    string category;
    double price;
    int stock;
};

// Shopping Cart Structure
struct CartItem
{
    Item* item; // Pointer to Item for cart to avoid copying
    int quantity;
};

// Function to Display the Items
void displayItems(const vector<Item>& storeItems)
{
    cout << "Available Items: \n";
    for (const auto& item : storeItems)
    {
        cout << item.productID << ". " << item.name << " ("
             << item.category << ") - $" << item.price
             << " (Stock: " << item.stock << ")" << endl;
    }
}

// Function to Check Available Stock
int getValidQuantity(int availableStock)
{
    int quantity = 0;
    while (true) // loop infinitely
    {
        cout << "Enter Quantity to add: ";
        cin >> quantity;
        if (cin.fail() || quantity <= 0 || quantity > availableStock)
        {
            cout << "Invalid quantity. Please enter a number between 1 and " << availableStock << ".\n";
        }
        else
        {
            break;
        }
    }
    return quantity;
}

// Function to add item to the cart
void addToCart(vector<Item>& storeItems, vector<CartItem>& cart, int& cartSize, const int MAX_CART)
{
    int itemNumber;
    cout << "Enter the item number to add to the cart: ";
    cin >> itemNumber;

    if (itemNumber < 1 || itemNumber > storeItems.size())
    {
        cout << "Invalid item number. Please select a valid item.\n";
        return;
    }

    Item& item = storeItems[itemNumber - 1];

    if (item.stock <= 0)
    {
        cout << "Item is out of stock.\n";
        return;
    }

    // Get valid quantity from user
    int quantity = getValidQuantity(item.stock);

    // Check if there is enough space in the cart
    if (cartSize >= MAX_CART)
    {
        cout << "Cart is full. You can't add more items.\n";
        return;
    }

    // Add the item to the cart (passing by reference)
    CartItem cartItem;
    cartItem.item = &item; // Assign pointer to item in cart
    cartItem.quantity = quantity;

    cart.push_back(cartItem); // Dynamically add to the cart
    cartSize++;

    // Update the stock in the store
    item.stock -= quantity;

    cout << quantity << " " << item.name << "(s) added to your cart.\n";
}

// Function to update the quantity of an item in the cart
void updateQuantityInCart(vector<CartItem>& cart)
{
    int itemNumber, newQuantity;

    cout << "Enter the item number to update: ";
    cin >> itemNumber;

    // Validate item number
    if (itemNumber < 1 || itemNumber > cart.size())
    {
        cout << "Invalid item number.\n";
        return;
    }

    CartItem& cartItem = cart[itemNumber - 1];

    cout << "Enter new quantity for " << cartItem.item->name << ": ";
    cin >> newQuantity;

    // Ensure the new quantity is valid
    if (newQuantity <= 0)
    {
        cout << "Invalid quantity. It must be greater than 0.\n";
        return;
    }
    
    // Update the quantity in the cart
    cartItem.quantity = newQuantity;

    cout << "Quantity of " << cartItem.item->name << " updated to " << newQuantity << ".\n";
}

// Function to remove an item from the cart
void removeFromCart(vector<CartItem>& cart)
{
    int itemNumber;
    cout << "Enter the item number to remove from the cart: ";
    cin >> itemNumber;

    // Validate item number
    if (itemNumber < 1 || itemNumber > cart.size())
    {
        cout << "Invalid item number.\n";
        return;
    }

    CartItem& cartItem = cart[itemNumber - 1];
    
    // Return the stock to the store
    cartItem.item->stock += cartItem.quantity;

    // Remove the item from the cart
    cart.erase(cart.begin() + itemNumber - 1);

    cout << cartItem.item->name << " has been removed from the cart.\n";
}

// Function to view the cart and calculate the total price
void viewCart(const vector<CartItem>& cart)
{
    double total = 0.0;
    cout << "\nYour Cart:\n";
    for (const auto& cartItem : cart)
    {
        cout << cartItem.item->name << " x " << cartItem.quantity << " = $" << cartItem.item->price * cartItem.quantity << endl;
        total += cartItem.item->price * cartItem.quantity;
    }
    cout << "\nTotal: $" << total << endl;
}

// Function to checkout and clear the cart
void checkout(int& cartSize, vector<CartItem>& cart)
{
    cart.clear(); // Clear the cart
    cartSize = 0;
    cout << "\nCheckout completed!\n";
}

int main()
{
    const int MAX_CART = 10;  // Max Cart is how much Items we can store in Cart.

    // Using vector for storeItems
    vector<Item> storeItems = {
        {1, "Laptop", "Electronics", 1000.00, 10},
        {2, "Phone", "Electronics", 500.00, 20},
        {3, "Tablet", "Electronics", 300.00, 15},
        {4, "Headphones", "Accessories", 50.00, 30}};

    int cartSize = 0;
    vector<CartItem> cart;

    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Display Items\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Update Cart Item Quantity\n";
        cout << "5. Remove Item from Cart\n";
        cout << "6. Checkout\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayItems(storeItems);
            break;
        case 2:
            addToCart(storeItems, cart, cartSize, MAX_CART);
            break;
        case 3:
            viewCart(cart);
            break;
        case 4:
            updateQuantityInCart(cart);
            break;
        case 5:
            removeFromCart(cart);
            break;
        case 6:
            checkout(cartSize, cart);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

````

### 4.4. Error Handling

*   **Invalid Item Selection**: If the user selects an invalid item number, an error message is displayed.
    
*   **Invalid Quantity**: The system ensures that quantities entered are within the available stock.
    
*   **Cart Capacity**: The program checks if the cart has space to add more items.
    

5\. Features of the System
--------------------------

*   **Browse Available Items**: Users can browse through the list of available items, each with a unique ID, name, category, price, and stock.
    
*   **Add to Cart**: Users can add items to their shopping cart, specifying the quantity, ensuring it doesn't exceed the available stock.
    
*   **View Cart**: The user can view the items currently in the cart and see the total price of all items.
    
*   **Update Cart**: Users can change the quantity of items already in their cart.
    
*   **Remove from Cart**: Users can remove items from the cart, which also updates the stock in the store.
    
*   **Checkout**: At checkout, the cart is cleared, and the purchase process is considered complete.
    

6\. Conclusion
--------------

The E-commerce Shopping Cart System fulfills the basic requirements of simulating an online shopping experience. The system is simple yet functional and provides a foundation for further development and improvement. It demonstrates the use of essential programming concepts such as data structures, loops, functions, and conditional statements. The project is a valuable learning exercise for beginner programmers and serves as a good base for building more complex systems.

Future improvements could include the integration of file storage for saving cart data, more advanced error handling, and the addition of features like user authentication, product recommendations, or a graphical user interface (GUI).

7\. Future Work
---------------

*   **Persistence**: Saving the cart data to a file or database for future sessions.
    
*   **Graphical User Interface**: Implementing a GUI to enhance the user experience.
    
*   **Multi-user Support**: Adding features to handle multiple users with separate carts.
    
*   **Inventory Management**: Adding features to manage and update the store's inventory more efficiently.