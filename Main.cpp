#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Item's Structure
struct Item
{
    int productID;
    string name;
    string category;
    double price; // reason to use double is because int max store 4 bytes
    int stock;
};

// Shopping Cart Structure
struct CartItem
{
    Item item;
    int quantiy;
};
void displayItems(Item storeItems[], const int SIZE);
int getValidQuantity(int availableStock);


int main()
{

    const int MAX_ITEMS = 10; // Max ITems is for maximum items of store
    const int MAX_CART = 10;  // Max Cart is how much Items we can store in Cart.
    Item storeItems[MAX_ITEMS] = {
        {1, "Laptop", "Electronics", 1000.00, 10},
        {2, "Phone", "Electronics", 500.00, 20},
        {3, "Tablet", "Electronics", 300.00, 15},
        {4, "Headphones", "Accessories", 50.00, 30}};

    CartItem cart[MAX_CART];
    int cartSize = 0;

    return 0;
}

// Function to Display the Items
void displayItems(Item storeItems[], const int SIZE)
{
    cout << "Available Items: \n";
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << storeItems[i].productID << ". " << storeItems[i].name << " ("
             << storeItems[i].category << ") - $" << storeItems[i].price
             << " (Stock: " << storeItems[i].stock << ")" << endl;
    }
}
// Function to Check Available Stock
int getValidQuantity(int availableStock)
{
    return 0;
}

/*
Function to validate user input for quantity
int getValidQuantity(int availableStock) {
    int quantity = 0;
    
    while (true) {
        cout << "Enter quantity to add: ";
        cin >> quantity;
        
        // Check for valid input (non-negative and less than or equal to available stock)
        if (cin.fail() || quantity <= 0 || quantity > availableStock) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid quantity. Please enter a number between 1 and " << availableStock << ".\n";
        } else {
            break;
        }
    }
    return quantity;
}

// Function to add item to the cart
void addToCart(Item storeItems[], CartItem cart[], int& cartSize, int MAX_ITEMS, int MAX_CART) {
    int itemNumber;
    
    // Get item number from the user
    cout << "Enter the item number to add to the cart: ";
    cin >> itemNumber;

    // Validate item number
    if (itemNumber < 1 || itemNumber > MAX_ITEMS) {
        cout << "Invalid item number. Please select a valid item.\n";
        return;
    }

    Item& item = storeItems[itemNumber - 1];  // Accessing item by ID (1-based)

    // Check if the item is in stock
    if (item.stock <= 0) {
        cout << "Item is out of stock.\n";
        return;
    }

    // Get valid quantity from user
    int quantity = getValidQuantity(item.stock);
    
    // Check if there is enough space in the cart
    if (cartSize >= MAX_CART) {
        cout << "Cart is full. You can't add more items.\n";
        return;
    }

    // Add the item to the cart
    cart[cartSize].item = item;
    cart[cartSize].quantity = quantity;
    cartSize++;

    // Update the stock in the store
    item.stock -= quantity;

    cout << quantity << " " << item.name << "(s) added to your cart.\n";
}
*/