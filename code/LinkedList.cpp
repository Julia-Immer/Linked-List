#include "LinkedList.h"
#include <string>
#include <memory>


// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList(){

  SetTop(shared_ptr<node>(NULL));
}

//deconstructor,
LinkedList::~LinkedList(){
}


shared_ptr<node> LinkedList::InitNode(int data){

  //create standalone node and add data to it
  shared_ptr<node> new_node(new node);
  new_node -> data = data;
  new_node -> next = shared_ptr<node>(NULL); 

  return new_node;
}


string LinkedList::Report(){
  string report = "";
  shared_ptr<node> curr_node(GetTop());

  //Add the data of each node to the report
  while (curr_node) {
    report += to_string(curr_node->data) + " ";
    curr_node = curr_node -> next;
  }
  return report;
}

void LinkedList::Append(shared_ptr<node> new_node){

  //find end and set pointer of last node to new node address
  shared_ptr<node> curr_node(GetTop());
  if(curr_node){    
    while (curr_node -> next) {
      curr_node = curr_node -> next;
    }
    //found the last node pointer and we set it to point to the new node
    curr_node -> next = new_node;
  }
  //else add the node to the beginning
  else {
    SetTop(new_node);
  }
}

void LinkedList::AppendData(int value){
  shared_ptr<node> new_node(new node);

  //create new node and add the node to the end 
  Append(new_node);

  //add the value to the node
  new_node -> data = value;

}

void LinkedList::InsertData(int insert_index, int data){
  //initialize and insert the node
  shared_ptr<node> new_node = InitNode(data);
  Insert(insert_index, new_node);

}

void LinkedList::Insert(int insert_index, shared_ptr<node> new_node){
  int index = 0;
  shared_ptr<node> curr_node = GetTop();

  if (!GetTop()) {
    return;
  }
  
  if (insert_index == 0) {
    new_node -> next = GetTop();
    SetTop(new_node);
    return;
  }

  if (insert_index < 0) {
    return;
  }

  while (curr_node != NULL) {
    if (index == insert_index - 1) {
      if (curr_node -> next) {
        new_node -> next = curr_node -> next;
        curr_node -> next = new_node;
      }
      else {
        curr_node -> next = new_node;
      }
    }
    //advance to the next node
    curr_node = curr_node -> next;
    index++;
  }

}


void LinkedList::Remove(int remove_index){
  int index = 0;
  shared_ptr<node> curr_node = GetTop();

  if (!GetTop()) {
    return;
  }
  
  if (remove_index == 0) {
    SetTop(curr_node -> next);
    return;
  }

  if (remove_index < 0) {
    return;
  }

  while (curr_node != NULL) {

    if (index == remove_index - 1) {
      if (curr_node -> next) {
        curr_node -> next = curr_node -> next -> next;
      }
    }
    //advance to the next node
    curr_node = curr_node -> next;

    index++;
  }

}

int LinkedList::Size(){
  int count = 0;
  shared_ptr<node> curr_node = GetTop();

  while (curr_node) {
    count++;
    curr_node = curr_node -> next;
  }
  return count;
}

bool LinkedList::Contains(int value){
  shared_ptr<node> curr_node = GetTop();

  //find the matching value in the data by searching each node
  while (curr_node) {
    if ((curr_node -> data) == value){
      return true;
    }
    curr_node = curr_node -> next;
  }
  return false;
}

// This function is implemented for you
// It returns the top pointer
shared_ptr<node> LinkedList::GetTop(){
  return top_ptr_;
}

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::SetTop(shared_ptr<node> top_ptr){
  top_ptr_ = top_ptr;
}
