// Create a table of all the different basic data types and the number of bytes that
// each uses. Use sizeof to find the answers. Try out various combinations of long and 
// unsigned, etc.

#include <iostream>
using namespace std;

int main() {
    // short = 2
    // int = 4
    // long = 8 
    // long long = 8
    // unsigned short = 2 
    // unsigned int = 4
    // unsigned long = 8 
    // unsigned long long = 8
    // size_t = 8
    short cshort;
    int cint;
    long clong;
    long long clonglong;
    unsigned short cuslong;
    unsigned int cuilong;
    unsigned long cullong;
    unsigned long long culllong;
    size_t csizet;
    cout << "short" << " " << sizeof(cshort) << endl;
    cout << "int" << " " << sizeof(cint) << endl;
    cout << "long" << " " <<  sizeof(clong) << endl;
    cout << "long long" << " " << sizeof(clonglong) << endl;
    cout << "unsigned short" << " " << sizeof(cuslong) << endl;
    cout << "unsigned int" << " " << sizeof(cuilong) << endl;
    cout << "unsigned long" << " " << sizeof(cullong) << endl;
    cout << "unsigned long long" << " " << sizeof(culllong) << endl;
    cout << "size_t" << " " << sizeof(csizet) << endl;
    return 0;
}
