/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
using namespace std;

void listOutput(Node*& in, Node*& evens, Node*& odds);
void testCase1();
void testCase2();
void testCase3();
void testCase4();
void testCase5();
void testCase6();

void listOutput(Node*& in, Node*& odds, Node*& evens)
{
}

int main(int argc, char* argv[])
{
  testCase1(); //add test case of choice here. free to edit.
  return 0;
}



//         ************TEST CASES***********
//************************************************
//************************************************
//************************************************
//************************************************


void testCase1() //1-5 test case
{
  Node e(5, nullptr);
  Node d(4, &e);
  Node c(3, &d);
  Node b(2, &c);
  Node a(1, &b);

  Node* evens = nullptr;
  Node* odds = nullptr;

  Node* in = &a;

  split(in, odds, evens);
  listOutput(in, odds, evens);
}

void testCase2() //all odds test case
{
  Node e(5, nullptr);
  Node d(1, &e);
  Node c(1, &d);
  Node b(1, &c);
  Node a(1, &b);

  Node* evens = nullptr;
  Node* odds = nullptr;

  Node* in = &a;

  split(in, evens, odds);
  listOutput(in, evens, odds);
}

void testCase3() //empty list test case
{
  Node* evens = nullptr;
  Node* odds = nullptr;

  Node* in = nullptr;

  split(in, evens, odds);
  listOutput(in, evens, odds);
}

void testCase4() //1 item test case
{
  Node a(1, nullptr);

  Node* evens = nullptr;
  Node* odds = nullptr;

  Node* in = &a;

  split(in, evens, odds);
  listOutput(in, evens, odds);
}

void testCase5() //big, non-linear numbers
{
  Node e(93423, nullptr);
  Node d(2000, &e);
  Node c(392, &d);
  Node b(19, &c);
  Node a(5, &b);

  Node* evens = nullptr;
  Node* odds = nullptr;

  Node* in = &a;

  split(in, odds, evens);
  listOutput(in, odds, evens);
}

void testCase6() //all 10 test case
{
  Node e(10, nullptr);
  Node d(10, &e);
  Node c(10, &d);
  Node b(10, &c);
  Node a(10, &b);

  Node* evens = nullptr;
  Node* odds = nullptr;

  Node* in = &a;

  split(in, odds, evens);
  listOutput(in, odds, evens);
}