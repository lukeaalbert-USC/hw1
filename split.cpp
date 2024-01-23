/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students
will receive no credit fo_r non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"


/* Add a prototype fo_r a helper function here if you need */
void addVal(Node*& curr, Node*& toAdd);

void split(Node*& in, Node*& odds, Node*& evens)
{
    if (in == nullptr) //base case; we've reached the end of the linked list.
    {
      return;
    }

    //We must find a way to keep track of the current node we are working with
    //and also delete the node from the in linked list (as specified in instructions)

    Node* temp = in -> next;

    if (in -> value % 2 == 0)
    {
      addVal(evens, in);
    }
    else
    {
      addVal(odds, in);
    }
    
  split(temp, odds, evens); //call split on the rest of the items

  in = nullptr;
}

/* If you needed a helper function, write it here */

void addVal(Node*& curr, Node*& toAdd)
{
  if (curr == nullptr)
  {
    curr = toAdd;
    curr -> next = nullptr;
    return;
  }
  if (curr -> next != nullptr)
  {
    addVal(curr -> next, toAdd);
    return;
  }
  curr -> next = toAdd;
  curr -> next -> next = nullptr;
}