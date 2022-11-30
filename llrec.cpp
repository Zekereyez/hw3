#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    // recursion baabyyyyy
    // should be an easy and fast implementation 
    // need helper function for this 
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    // suggestive case where we know we are at the penultimate node
    if (head->next == nullptr) {
      if (head->val <= pivot) {
        smaller = head;
        larger = nullptr;
      }
      else {
        smaller = nullptr;
        larger = head;
      }
      head = nullptr;
    }
    // the value must be equal or less than the pivot in order to be 
    // in the smaller node list
    else if (head->val <= pivot) {
        smaller = head;
        head = head->next;
        llpivot(head, smaller->next, larger, pivot);
    }
    // if strictly bigger then we assign into the larger node list
    else {
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    }
}
