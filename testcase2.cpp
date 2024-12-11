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
