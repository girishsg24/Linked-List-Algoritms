#include <iostream>
#include <vector>
#include <map>

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

bool detect_cycle(Node* head)
{
 std:: map <Node*, int> nodesTable;
  while(head!=nullptr && nodesTable.find(head)==nodesTable.end())
  {
    nodesTable[head]=1;
    head = head->next;
  }
  if (head == nullptr)
    return false;
  else
    return true;
}

Node* get_tail(Node* head)
{
  if (head==nullptr) return nullptr;
  if (head->next == nullptr) return head;
  return get_tail(head->next);
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
   head = insert_head(head,99);
   Node* loopNode = head;
   head = insert_sorted(head,5);
   head = insert_sorted(head,3);
   head = insert_sorted(head,0);
   head = insert_sorted(head,5);
   head = insert_sorted(head,9);
   head = insert_sorted(head,2);
   get_tail(head)->next = loopNode;
   std::cout<<detect_cycle(head)<<std::endl;
   //print(head);
   std::cout<<std::endl;
 //  std::cout<<kthToLast(head,0)<<std::endl;
 //  std::cout<<(kthToLast(head,1))<<std::endl;
 //  std::cout<<kthToLast(head,3)<<std::endl;
   return 0;
}
