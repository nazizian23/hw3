#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node*& head,Node*& smaller,Node*& larger,int pivot){

  //Base case: empty list sets outputs to NULL
  if(head==NULL){
    smaller=NULL;
    larger=NULL;
    return;
  }
  //Saves the current node, and advances the head
  Node* curr=head;
  head=head->next;
  //Recursively splits the rest of the list
  llpivot(head,smaller,larger,pivot);

  //Add current to smaller if it is less than or equal to the pivot
  if(curr->val<=pivot){
    curr->next=smaller;
    smaller=curr;

  }
  //adds current to larger if >pivot
  else{
    curr->next=larger;
    larger=curr;
  }
  //Clears out the original list
  head=NULL;


}