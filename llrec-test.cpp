#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
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





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------

    /* UNCOMMENT THIS SECTION TO TEST LLPIVOT */ 
    
    // Node* head = readList(argv[1]);
    // cout << "Original list: ";
    // print(head);

    // Node* smaller = NULL;
    // Node* larger = NULL;
    // llpivot(head, smaller, larger, 8);
    
    // cout << "Smaller List: " << endl;
    // print(smaller);
    // cout << "Larger List: " << endl; 
    // print(larger);

    // dealloc(head);
    // dealloc(smaller);
    // dealloc(larger); 

    // Node* head2 = readList(argv[1]); 
    // cout << "Original list: ";
    // print(head2);

    // Node* smaller2; 
    // Node* larger2; 
    // llpivot(head2, smaller2, larger2, 12);
    // cout << "Smaller List: " << endl;
    // print(smaller2);
    // cout << "Larger List: " << endl; 
    // print(larger2); 
   
    // dealloc(head2);
    // dealloc(smaller2);
    // dealloc(larger2); 

    /* UNCOMMENT THIS SECTION TO TEST LLFILTER */ 
    
    /* Tests with input file */ 
    // Node* head3 = readList(argv[1]);
    // cout << "Original list: ";
    // print(head3);

    // isEven c1; 
    // head3 = llfilter(head3, c1);
    // cout << "Filtered List: ";
    // print(head3);
    // dealloc(head3); 
    
    /* Tests manually created linked list */ 
    // Node* t1 = new Node(2, NULL);
    // Node* t2 = new Node(4, NULL);
    // Node* t3 = new Node(-5, NULL);
    // Node* t4 = new Node(20, NULL); 
    // Node* t5 = new Node(25, NULL);
    // Node* t6 = new Node(26, NULL);
    // t1->next = t2; 
    // t2->next = t3;
    // t3->next = t4;
    // t4->next = t5;
    // t5->next = t6; 

    // cout << "Original list: ";
    // print(t1);
    // isOdd c2; 
    // t1 = llfilter(t1, c2);
    // cout << "Filtered List: ";
    // print(t1); 
    // dealloc(t1); 

    /* Filtering out nodes less than 10 */ 
    // Node* head4 = readList(argv[1]);
    // cout << "Original list: ";
    // print(head4);

    // lessThan10 c3; 
    // head4 = llfilter(head4, c3);
    // cout << "Filtered List: ";
    // print(head4);
    // dealloc(head4); 

    return 0;
}
