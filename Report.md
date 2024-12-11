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
    

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   int main() {      // Initialize items in the store      // Handle user input and menu navigation  }   `

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