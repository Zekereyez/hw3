#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include "stack.h"

using namespace std;



int main() {

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------

    cout << "STACK TESTING" << endl;
    cout << "Creating Templated Stack of String" << endl;
    Stack<string> stack;
    string word1 = "I love";
    string word2 = "CS104";
    stack.push(word2);
    stack.push(word1);
    cout << "\n" << stack.top() << endl;
    stack.pop();
    cout << "\n" << stack.top() << endl;
    stack.pop();

    cout << "STACK TESTING" << endl;
    cout << "Creating Templated Stack of INT" << endl;
    Stack<int> stackInt;
    for (int i = 0; i < 10; ++i) {
        stackInt.push(i * 2);
    }
    while (!stackInt.empty()) {
        cout << "Stack Current Size:" << stackInt.size() << endl;
        cout << endl << stackInt.top() << endl;
        stackInt.pop();
        cout << endl;
    }
    stackInt.pop(); // should throw error
    
    return 0;

}
