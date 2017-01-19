#include<iostream>
#include<map>
using namespace std;

class node
{
    public: 
        int data;
        node* next;
};

void print(node* tHead)
{
    if (tHead==nullptr)
        return;
    cout<<tHead->data<<" ";
    return print(tHead->next);
    
}

node* insertNode(node* head,int pos,int data)
{
    node* newNode=new node;
    newNode->data=data;
    if (pos==1)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        node*tHead=head;
        for(int i=0;i<pos-2 && tHead->next!=nullptr;tHead=tHead->next,i++);
        newNode->next=tHead->next;
        tHead->next=newNode;
        cout<<"Successfully Created the Node"<<endl;
       
    }
     return head;
} 


node* removeDuplicates(node* head)
{
    map<int, int>dataTab;
    /*
        Initially store the head value in the map with data of the head as the key & 1 as the content
        later keep checking for the next node for its data & keep inserting them in the map.
        we search for the existing value if it there , then delete the node
    */
    dataTab[head->data]=1;
    for(node* tHead=head;tHead->next!=nullptr;)
    {
        node* NodeToRemove;
        auto it=dataTab.find(tHead->next->data);
        if (it==dataTab.end())
         {
             dataTab[tHead->next->data]=1;
             tHead=tHead->next;
         }
        else
        {
            /*
                store the next node to be deleted
                attach the current node to the next of next
                finally free the memory held by the node to be deleted
                
            */
            NodeToRemove=tHead->next;
            tHead->next=NodeToRemove->next;
            delete NodeToRemove;
        }
            
    }
    return head;
}

int main ()
{
   node* head=nullptr,*head1=nullptr,*head2=nullptr,*merge=nullptr;
   int temp;
  
  
   head=insertNode(head,1,0);   
   head=insertNode(head,2,5);
   head=insertNode(head,4,8);
   head=insertNode(head,5,2);
   head=insertNode(head,6,2);
   head=insertNode(head,7,5);
   print(head);
   cout<<endl;
   head=removeDuplicates(head);
   print(head);
   cout<<endl;
}