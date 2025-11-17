// Cast char values to int values to find codes used for the characters
// 'a', 'z', 'A', 'Z', '0', and '9'. What codes are used for a carriage
// return, a line, and a tab?


#include <iostream>
using namespace std;

int main() {
    cout << "a " << (int) 'a' << endl;
    cout << "z " << (int) 'z' << endl;
    cout << "A " << (int) 'A' << endl;
    cout << "Z " << (int) 'Z' << endl;
    cout << "Carriage return " << (int) '\r' << endl;
    cout << "New line " << (int) '\n' << endl;
    cout << "Tab " << (int) '\t' << endl;
    return 0;
}
