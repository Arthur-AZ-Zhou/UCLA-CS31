#include <iostream>
#include <string>
using namespace std; 

class Restaurant { //have mutators or setters and accessors or getters
    public: 
        //usually you define functions outside, but if it's short enough you can put it inline
        void setName(string name) { //called inline function
            this->name = name;
        }
        
        void setRating(int rating) {this->rating = rating;}

        void print() const; //recommended to have const bc getters should not change data

    private: //you can have helper functions in private
        string name;
        int rating;
};

void Restaurant::print() const { //have to use :: as scope
    cout << name << " -- " << rating << endl;
}

int main() {
    Restaurant favLunchPlace;
    Restaurant favDinnerPlace;

    favLunchPlace.setName("Central Deli");
    favLunchPlace.setRating(4);

    favDinnerPlace.setName("Friends Cafe");
    favDinnerPlace.setRating(5);

    cout << "My favorite restaurants: " << endl;
    favLunchPlace.print();
    favDinnerPlace.print();
}

