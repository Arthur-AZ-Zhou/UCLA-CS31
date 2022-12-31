#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std; 

//when planning a class, - usually indicates a private term and + usually indicates a public item
class Restaurant {
   public:
      Restaurant(); //the constructor
      Restaurant(string restaurantName, int userRating);
      void SetName(string restaurantName);
      void SetRating(int userRating);
      void Print();
   private:
      string name;
      int rating;
};

Restaurant::Restaurant() {  // Default constructor
   name = "NoName";         // Default name: NoName indicates name was not set
   rating = -1;             // Default rating: -1 indicates rating was not set
}

Restaurant::Restaurant(string restaurantName, int userRating) { //can overload a constructor, make another more specific one
   name = restaurantName;
   rating = userRating;
}

void Restaurant::SetName(string restaurantName) {
   name = restaurantName;
}

void Restaurant::SetRating(int userRating) {
   rating = userRating;
}

// Prints name and rating on one line
void Restaurant::Print() {
   cout << name << " -- " << rating << endl;
}

int main() { //to run multiple files on g++, do g++ constructors.cpp Product.cpp and then call ./a.out
   Restaurant favLunchPlace;  // Automatically calls the default constructor

   favLunchPlace.Print();
   favLunchPlace.SetName("Central Deli");
   favLunchPlace.SetRating(4);
   favLunchPlace.Print();

   vector<Product> productList;
   Product currProduct;
   int currPrice;
   string currName;
   unsigned int i;
   Product resultProduct;

   cin >> currPrice;
   while (currPrice > 0) {
      cin >> currName;
      currProduct.SetPriceAndName(currPrice, currName);
      productList.push_back(currProduct);
      cin >> currPrice;
   }

   resultProduct = productList.at(0);
   for (i = 0; i < productList.size(); ++i) {
      if (productList.at(i).GetPrice() < resultProduct.GetPrice()) {
         resultProduct = productList.at(i);
      }
   }

   cout << resultProduct.GetName() << ": " << resultProduct.GetPrice() << endl;
}