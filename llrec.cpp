#include "llrec.h"
#include <iostream>

using namespace std; 
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  // we want to run this in O(n)
  // in every recursive iteration, we want to compare the value in the head node to the pivot, if smaller or equal to, send to smaller 
  // if larger, send to larger 
  // cout << head->val << endl; 
  // base case if head is last item in original list
  if (head == NULL)
  {

  }
  // compare value of current head to pivot, move accordingly 
  else if(head->val <= pivot)
  {
    Node* temp = head; 
    head = head->next;
    temp->next = NULL; 
    smaller = temp; 
    llpivot(head, smaller->next, larger, pivot); 
  }
  else
  {
    Node* temp = head; 
    head = head->next;
    temp->next = NULL; 
    larger = temp; 
    llpivot(head, smaller, larger->next, pivot); 
  }
};

