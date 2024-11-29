#include <iostream>
#include<string>

using namespace std;

// Item's Structure
struct Item
{   int productID;
    string name;
    string category;
    double price; // reason to use double is because int max store 4 bytes 
    int stock;
};
// Max ITems is for maximum items of store
const int MAX_ITEMS = 10;
// Max Cart is how much Items we can store in Cart.
const int MAX_CART = 10;
// Shopping Cart Structure 

///////////////////////////////////
Item storeItems[MAX_ITEMS] = {
    {1, "Laptop", "Electronics", 1000.00, 10},
    {2, "Phone", "Electronics", 500.00, 20},
    {3, "Tablet", "Electronics", 300.00, 15},
    {4, "Headphones", "Accessories", 50.00, 30}
};
struct CartItem{
    Item item;
    int quantiy;
};

CartItem cart[MAX_CART];
int cartSize = 0;

// Function to Display the Items
void displayItems(){
    cout<<"Available Items: \n";
    for (size_t i = 0; i < MAX_ITEMS; i++)
    {
        cout<<storeItems[i].productID<<". "<<storeItems[i].name<<" ("
            <<storeItems[i].category<<") - $"<<storeItems[i].price
            <<" (Stock: "<<storeItems[i].stock<<")"<<endl;
    }
    
}


int main(){
    // Item Item;

    return 0;
}