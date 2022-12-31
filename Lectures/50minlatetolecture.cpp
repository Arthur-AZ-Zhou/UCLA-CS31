#include <iostream>
#include <string> 
using namespace std;

const int MAXSODA = 100;

class Soda {
    public:
    Soda();
    void setName(string name);
    string getName() const;

    private:
    string name;
};

Soda::Soda() {
    name = "NA";
}

void Soda::setName(string name) {
    this->name = name;
}

string Soda::getName() const {
    return name;
}

class VM {
    public:
    VM(int n);
    ~VM();
    void restock(string name,int quantity);
    Soda* getSoda(string name);
    bool buySoda(string name);

    private:
    Soda* inventory[MAXSODA];
    int quantity[MAXSODA];
    int numSoda;
};

VM::VM(int n) {
    numSoda = n;
    for(int i=0;i<numSoda;i++)
    inventory[ i ] = new Soda();
}

VM::~VM() {
    for (int i = 0; i < numSoda; i++) {
        delete inventory[i];
    }
}

void VM::restock(string name, int quantity) {
    for(int i=0;i<numSoda;i++) {
        if (inventory[i]->getName() == "NA") {
            inventory[i]->setName(name);
            this->quantity[i] = quantity;
            break;
        }
    }
}

Soda* VM::getSoda(string name) {
    for (int i = 0; i < MAXSODA; i++) {
        if (inventory[i]->getName() == name) {
            return inventory[i];
        }
    }

    return nullptr;
}

bool VM::buySoda(string name) {
    for (int i = 0; i < MAXSODA; i++) {
        if (inventory[i]->getName() == name) {
            if (quantity[i] > 0) {
                quantity[i]--;
                return true;
            }

            return false;
        }
    }

    return false;
}

int main() {
    VM vm(5);
    vm.restock("Coke",4);
    vm.restock("Diet Coke",5);
    vm.restock("Sprite",1);
    vm.restock("Pepsi",0);
    vm.restock("Lemonade",1);
    if(vm.buySoda("Coke"))
        cout << "I bought " << vm.getSoda("Coke")->getName() << endl;
    else
        cout << "Coke is sold out!!" << endl;
    if(vm.buySoda("Pepsi"))
        cout << "I bought " << vm.getSoda("Pepsi")->getName() << endl;
    else
        cout << "Pepsi is sold out!!" << endl;
    return 0;
}