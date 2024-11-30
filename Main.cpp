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
    int quantity;
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
// Function to Check Available Stock
int getValidQuantity(int availableStock)
{
    int quantity = 0;

    while (true) // loop infinitly run
    {
        cout<<"Enter Quanity to add: ";
        cin>>quantity;
        if (cin.fail() || quantity <= 0 || quantity > availableStock)
        {
            cout << "Invalid quantity. Please enter a number between 1 and " << availableStock << ".\n";
        }else
        {
            break;
        }
        
        
    }
    

    return quantity;
}




// Function to add item to the cart
void addToCart(Item storeItems[], CartItem cart[], int& cartSize, int MAX_ITEMS, int MAX_CART){
    int itemNumber;
    cout << "Enter the item number to add to the cart: ";
    cin >> itemNumber;


    if (itemNumber < 1 || itemNumber > MAX_ITEMS) {
        cout << "Invalid item number. Please select a valid item.\n";
        return;
    }
    Item& item = storeItems[itemNumber - 1];

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

void viewCart(CartItem cart[],int& cartSize) {
    double total = 0.0;
    cout << "\nYour Cart:\n";
    for (int i = 0; i < cartSize; ++i) {
        CartItem item = cart[i];
        cout << item.item.name << " x " << item.quantity << " = $" << item.item.price * item.quantity << endl;
        total += item.item.price * item.quantity;
    }
    cout << "\nTotal: $" << total << endl;
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

    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Items\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayItems(storeItems, MAX_ITEMS);
                break;
            case 2:
                addToCart(storeItems, cart, cartSize, MAX_ITEMS, MAX_CART);
                break;
            case 3:
                viewCart(cart, cartSize); 
                break;
            case 4:
                // checkout(cart, cartSize);
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
