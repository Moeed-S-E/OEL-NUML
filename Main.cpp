#include <iostream>
#include<string>

using namespace std;

// Item's Structure
struct Item
{
    string name;
    double price; // reason to use double is because int max store 4 bytes 
    int stock;
};

// Shopping Cart Structure 
struct CartItem{
    Item item;
    int quantiy;
};

// Function to Display the Items
void displayItems(){
    cout<<"Available Items: \n";
    // ...... 
    // code later on I will add
    // ..... 
}


int main(){
    
    return 0;
}