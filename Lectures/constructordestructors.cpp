#include <iostream>
#include <string>
using namespace std; 

class Toy {
    public:
    string getName() {
        return name;
    }
    void setName(string setName) {
        name = setName;
    }

    private:
    string name;
};

class Pet {
    public:
    Pet(string name, int initialHealth) {
        m_name = name;
        m_health = initialHealth;
        m_favorite_toy = nullptr;
    }
    ~Pet() { //the destructor, if the pet goes away with or without a favorite toy the memory leak is cleaned
        delete m_favorite_toy;
    }
    void addToy() {
        delete m_favorite_toy; //delete old one so no memory leak
        m_favorite_toy = new Toy;
    }
    void cleanup() {
        delete m_favorite_toy;
    }

    private:
    int m_health;
    string m_name;
    Toy* m_favorite_toy;
};

int main() {
    Pet p1("Fido", 20);
    p1.addToy();
    //if you delete p1, the toy will still exist and will become a memory leak
    // p1.cleanup(); //to clean up the toy, but it's easy to forget
    p1.addToy(); //but if you call addToy() twice, it leaves the first toy as garbage, so we have to delete previous favorite toy in addToy()
}