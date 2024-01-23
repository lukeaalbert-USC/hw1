#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// ********* START: WRITE YOUR CODE HERE *********

 void ULListStr::push_back(const std::string& val)
 {
  if (empty()) //case where list is empty. 
  { //Allocate new item, put in value, increase "last index," set
    // head and tail of entire list to this new first item. Increase Size.
    Item* FirstItem = new Item;
    FirstItem -> val[FirstItem -> last] = val; 
    FirstItem -> last++;
    head_ = FirstItem;
    tail_ = FirstItem;
    size_++;
  }
  else //ELSE, when there already exists some item...
  {
    if (tail_ -> last == ARRSIZE) //If the array in the item is full,
    { //allocate a new item, connect it with rest of list, change tail and size. 
      Item* newItem = new Item;
      tail_ -> next = newItem;
      newItem -> prev = tail_;
      tail_ = newItem;
    }
    tail_ -> val[tail_ -> last] = val; //add value in, increase last index.
    tail_ -> last++;
    size_++;
  }
 }

  void ULListStr::push_front(const std::string& val)
  {
    if (empty()) //case where list is empty. 
    { //Allocate new item, put in value, increase "last index," set
      // head and tail of entire list to this new first item. Increase Size.
      Item* FirstItem = new Item;
      FirstItem -> val[FirstItem -> last] = val; 
      FirstItem -> last++;
      head_ = FirstItem;
      tail_ = FirstItem;
      size_++;
    }
    else
    {
      if (head_ -> first == 0) //If Item Array is empty...
      { //Here, we allocate a new node and set it's first and last index to
        // ARRSIZE, as we are pushing this index at the front. 
        Item* newItem = new Item;
        head_ -> prev = newItem;
        newItem -> next = head_;
        newItem -> last = ARRSIZE;
        newItem -> first = ARRSIZE;
        head_ = newItem;
      }
      head_ -> val[head_ -> first - 1] = val;
      head_ -> first--;
      size_++;
    }
  }

  std::string const & ULListStr::back() const
  {
    return tail_ -> val[tail_-> last - 1]; //back item is the tail node's last value minus 1, as last is exclusive
  }

  std::string const & ULListStr::front() const
  {
    return head_ -> val[head_-> first]; //first item is head node's first item
  }

  void ULListStr::pop_back()
  {
    if (tail_ == NULL && head_ == NULL) //if poping from an empty list, return.
    {
      return;
    }
    if (tail_ -> first == tail_ -> last - 1) //if only 1 node left in tail_
    {
      Item* toDel = tail_;
      if (tail_ != head_) //if we AREN'T removing the final item from the entire linked list...
      {
        tail_ = tail_ -> prev;
        tail_ -> next = NULL;
      }
      else //else, if we ARE removing the final item from the entire linked list, change head and tail to null.
      {
        head_ = NULL;
        tail_ = NULL;
      }
      delete toDel; 
      size_--;
    }
    else
    {
      tail_ -> last--;
      size_--;
    }
  }

  void ULListStr::pop_front()
  {
    if (tail_ == NULL && head_ == NULL) //is poping an empty list, return.
    {
      return;
    }
    if (head_ -> first == head_ -> last - 1) //if only 1 node left in head_
    {
      Item* toDel = head_;
      if (tail_ != head_) //if we AREN'T removing the final item from the entire linked list...
      {
        head_ = head_ -> next;
        head_ -> prev = NULL;
      }
      else //else, if we ARE removing the final item from the entire linked list, change head and tail to null.
      {
        head_ = NULL;
        tail_ = NULL; 
      }
      delete toDel;
      size_--;
    }
    else
    {
      head_ -> first++;
      size_--;
    }
  }

  std::string* ULListStr::getValAtLoc(size_t loc) const
  {
    if (loc < 0 || loc >= size_) //if loc is invalid, return NULL.
    {
      return NULL;
    }
    if (head_ == NULL) //if getting val at loc of completely empty list, return NULL.
    {
      return NULL;
    }
    Item* iterator = head_;
    int count = 0;

    while (loc >= iterator -> last - iterator -> first) //Move through list from head towards tail, checking if index is
    { //in each node of linked list.
      count++;
      loc = loc - (iterator -> last - iterator -> first);
      if (iterator -> next == NULL) 
      {
        break;
      }
      iterator = iterator -> next;
    }

    if (count == 0) //if we haven't moved from head at all, then item must be in head
    {
      return &(iterator -> val[iterator -> first + loc]);
    }   
    return &(iterator -> val[loc]);
  }

// ********* END: WRITE YOUR CODE HERE *********

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
