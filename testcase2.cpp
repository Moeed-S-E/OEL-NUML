// #include <iostream>
// #include <string>

// using namespace std;

// // Item's Structure
// struct Item
// {
//     int productID;
//     string name;
//     string category;
//     double price;
//     int stock;
// };

// // Shopping Cart Structure
// struct CartItem
// {
//     Item* item; // Changed to pointer for reference
//     int quantity;
// };

// // Function to Display the Items
// void displayItems(Item storeItems[], const int currentItemCount)
// {
//     cout << "Available Items: \n";
//     for (int i = 0; i < currentItemCount; i++)
//     {
//         cout << storeItems[i].productID << ". " << storeItems[i].name << " ("
//              << storeItems[i].category << ") - $" << storeItems[i].price
//              << " (Stock: " << storeItems[i].stock << ")" << endl;
//     }
// }

// // Function to Check Available Stock
// int getValidQuantity(int availableStock)
// {
//     int quantity = 0;
//     while (true) // loop infinitely
//     {
//         cout << "Enter Quantity to add: ";
//         cin >> quantity;
//         if (cin.fail() || quantity <= 0 || quantity > availableStock)
//         {
//             cout << "Invalid quantity. Please enter a number between 1 and " << availableStock << ".\n";
//         }
//         else
//         {
//             break;
//         }
//     }
//     return quantity;
// }

// // Function to add item to the cart
// void addToCart(Item storeItems[], CartItem cart[], int& cartSize, const int MAX_ITEMS, const int MAX_CART)
// {
//     int itemNumber;
//     cout << "Enter the item number to add to the cart: ";
//     cin >> itemNumber;

//     if (itemNumber < 1 || itemNumber > MAX_ITEMS)
//     {
//         cout << "Invalid item number. Please select a valid item.\n";
//         return;
//     }

//     Item& item = storeItems[itemNumber - 1];

//     if (item.stock <= 0)
//     {
//         cout << "Item is out of stock.\n";
//         return;
//     }

//     // Get valid quantity from user
//     int quantity = getValidQuantity(item.stock);

//     // Check if there is enough space in the cart
//     if (cartSize >= MAX_CART)
//     {
//         cout << "Cart is full. You can't add more items.\n";
//         return;
//     }

//     // Add the item to the cart (passing by reference)
//     cart[cartSize].item = &item; // Assign pointer to item in cart
//     cart[cartSize].quantity = quantity;
//     cartSize++;

//     // Update the stock in the store
//     item.stock -= quantity;

//     cout << quantity << " " << item.name << "(s) added to your cart.\n";
// }

// void viewCart(CartItem cart[], int cartSize)
// {
//     double total = 0.0;
//     cout << "\nYour Cart:\n";
//     for (int i = 0; i < cartSize; ++i)
//     {
//         CartItem& cartItem = cart[i];
//         cout << cartItem.item->name << " x " << cartItem.quantity << " = $" << cartItem.item->price * cartItem.quantity << endl;
//         total += cartItem.item->price * cartItem.quantity;
//     }
//     cout << "\nTotal: $" << total << endl;
// }

// void checkout(int& cartSize)
// {
//     cartSize = 0;
//     cout << "\nCheckout completed!\n";
// }

// int main()
// {
//     const int MAX_ITEMS = 10; // Max Items is for maximum items of store
//     const int MAX_CART = 10;  // Max Cart is how much Items we can store in Cart.
//     Item storeItems[MAX_ITEMS] = {
//         {1, "Laptop", "Electronics", 1000.00, 10},
//         {2, "Phone", "Electronics", 500.00, 20},
//         {3, "Tablet", "Electronics", 300.00, 15},
//         {4, "Headphones", "Accessories", 50.00, 30}};

//     int currentItemCount = 4;

//     CartItem cart[MAX_CART];
//     int cartSize = 0;

//     int choice;

//     do
//     {
//         cout << "\nMenu:\n";
//         cout << "1. Display Items\n";
//         cout << "2. Add to Cart\n";
//         cout << "3. View Cart\n";
//         cout << "4. Checkout\n";
//         cout << "5. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             displayItems(storeItems, currentItemCount);
//             break;
//         case 2:
//             addToCart(storeItems, cart, cartSize, MAX_ITEMS, MAX_CART);
//             break;
//         case 3:
//             viewCart(cart, cartSize);
//             break;
//         case 4:
//             checkout(cartSize);
//             break;
//         case 5:
//             cout << "Exiting...\n";
//             break;
//         default:
//             cout << "Invalid choice. Try again.\n";
//         }
//     } while (choice != 5);

//     return 0;
// }
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
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
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
            checkout(cartSize, cart);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
