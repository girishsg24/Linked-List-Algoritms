#include <iostream>
#include <vector>
#include <unordered_map>

struct Node{
  int val;
  Node* next;
};

Node* insert_tail(Node* head, int val)
{
  if(head == nullptr)
  {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
  }
  
  head->next = insert_tail(head->next, val);
  return head;
}

Node* insert_sorted(Node* head, int val)
{
  if(head == nullptr)
  {
    Node* newNode = new(Node);
    newNode->val = val;
    return newNode;
  }
  
  if (head->val<val)
    head->next = insert_sorted(head->next,val);
  else
  {
    Node* newNode = new(Node);
    newNode->val = val;
    newNode->next = head;
    return newNode;
  }
  return head;
}

Node* insert_head(Node* head, int val)
{
  Node* newNode = new(Node);
  newNode->val = val;
  if(head == nullptr)
    return newNode;
  newNode->next = head;
  return newNode; 
}

void print(Node* head)
{
  if(head == nullptr)
    return;
  std::cout<<head->val<<" ";
  print(head->next); 

}

int main ()
{
   Node* head = nullptr;
   head = insert_tail(head,6);
   head = insert_tail(head,4);
   head = insert_tail(head,3);
   head = insert_head(head,9);
   head = insert_head(head,5);
   head = insert_head(head,4);
   print(head);
   std::cout<<std::endl;
   head = nullptr;
   head = insert_sorted(head,5);
   head = insert_sorted(head,3);
   head = insert_sorted(head,0);
   head = insert_sorted(head,5);
   head = insert_sorted(head,9);
   head = insert_sorted(head,2);
   print(head);
   std::cout<<std::endl;
   return 0;
}
