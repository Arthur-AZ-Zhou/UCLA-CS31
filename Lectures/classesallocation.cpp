#include <iostream>
#include <string>
using namespace std; 

class Target {
    public:
    string getStr() {
        return str;
    }
    void setStr(string setStr) {
        str = setStr;
    }

    private:
    string str = "target";
};

int main() {
    Target* tpa[4];
    int nTargets = 0;

    for (nTargets = 0; nTargets < 4; nTargets++) {
        tpa[nTargets] = new Target;
    }
    cout << nTargets << endl;

    tpa[1]->setStr("Whole foods");
    tpa[2]->setStr("walgreens");
    tpa[3]->setStr("walmart");
    // tpa[2] = tpa[3]; //bc of this walgreens is now garbage, in bigger programs you get a lot of garbage and you get memory leak
    delete tpa[2]; //delete deletes the object the pointer points to, pointer still exists
    tpa[2] = tpa[3];
    nTargets--;
    tpa[3] = nullptr; //unnecessary but comforting
    for (int i = 0; i < nTargets; i++) {
        cout << tpa[i]->getStr() << endl;
    }

    //named local variables go on the stack
    //variables declared oustide of any function live in the "global storage area"
    //dynamically allocated objects live on the heap
}