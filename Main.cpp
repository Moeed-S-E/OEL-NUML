#include <iostream>
#include <string>

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