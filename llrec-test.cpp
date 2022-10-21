#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include "llrec.h"
#include "stack.h"

using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
// void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

struct Even {
    bool operator()(int value) {
        return (value % 2 == 0);
    }
};






int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    cout << "New list with pivot of 8" << endl;
    cout << "Filtered list with even comparison" << endl;
    Even obj;
    head = llfilter(head, obj);
    print(head);

    // cout << "STACK TESTING" << endl;
    // cout << "Creating Templated Stack of String" << endl;
    // Stack<string> stack;
    // string word1 = "I love";
    // string word2 = "CS104";
    // stack.push(word1);
    // stack.push(word2);
    // cout << "\n" << stack.top() << endl;
    // stack.pop();
    // cout << "\n" << stack.top() << endl;
    // stack.pop();


    
    return 0;

}
