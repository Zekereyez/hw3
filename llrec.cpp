#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    // recursion baabyyyyy
    // should be an easy and fast implementation 
    // need helper function for this 
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    // the value must be equal or less than the pivot in order to be 
    // in the smaller node list
    if (head->val <= pivot) {
        smaller = head;
        llpivot(head->next, smaller->next, larger, pivot);
    }
    // if strictly bigger then we assign into the larger node list
    else {
        larger = head;
        llpivot(head->next, smaller, larger->next, pivot);
    }
}
