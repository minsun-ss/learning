// Write a program that reads a single char of input and then prints
// the same character in upper case. To do this convert character to an integer
// and work out if it is a lower character or not. If it is, convert to the code
// for an upper case letter. Then convert this back to an integer. 

// a 97
// z 122
// A 65
// Z 90

#include <iostream>
using namespace std;

int main() {
    char input;
    cout << "Give me a character and I'll convert to upper case!\n";
    cin >> input;

    int iinput = (int) input;
    char upper_input;
    if ((iinput >= 97) && (iinput <= 122)) {
         upper_input = (char) (iinput-32);
    } else {
        upper_input = input;
    }

    cout << "New character: " << upper_input << endl;
    return 0;
}
