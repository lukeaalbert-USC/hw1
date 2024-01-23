#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
#include <iostream>
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  return 0;
}

void test1()
{
  ULListStr dat;
  dat.push_back("1");
  dat.push_front("2");
  dat.push_front("3");
  dat.push_back("4");
  dat.push_front("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_front("10");
  dat.push_front("11");
  dat.push_back("12");
  dat.push_front("13");
  dat.push_back("14");
  dat.push_back("15");
  dat.push_back("16");
  dat.push_back("17");
  dat.push_front("18");
  dat.push_front("19");
  dat.push_front("20");
  dat.push_front("21");
  dat.push_front("22");
  dat.push_front("23");
  //23, 22, |21, 20, 19, 18, 13, 11, 10, 5, 3,  2, |1,  4,  6,  7,  8,  9, 12,14,15,  16, |17
  //0,  1,  |2,  3,  4,  5,  6,  7,  8,  9, 10, 11,|12, 13, 14, 15, 16, 17,18,19,20, 21, |22
  cout << dat.get(1) << " " << dat.get(9) << " " << dat.get(5) << " " << dat.get(22) << " " << dat.get(16) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}