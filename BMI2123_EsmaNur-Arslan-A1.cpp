#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
};

class DoubleLinkedList{
    public:
        Node* head;
    public:
        DoubleLinkedList(){
            head=NULL;
        }
        

    void addFront(int data);
    void addTail(int data);
    void addSecond(int data);
    void getFront();
    void getTail();
    void removeFront();
    void removeTail();
    void removeAll();
    void isEmpty();
    void printListItems();
};

void DoubleLinkedList::printListItems(){
    Node* node=head;
    while(node->next!=NULL){
        cout<<node->data<<" ";node=node->next;}
    cout<<node->data<<endl;
}

void DoubleLinkedList::addFront(int data){
    Node* temp= new Node();
    temp->data=data;
    temp->next=head;
    temp->prev=NULL;
    if(head!=NULL)
    head->prev=temp;
    head=temp;
}



void DoubleLinkedList::addTail(int data){

    Node* temp=new Node();
    temp->data=data;
    temp->next=NULL;
    Node* node=head;
    while(node->next!=NULL)
        node=node->next;
    node->next=temp;
    temp->prev=node;
}

void DoubleLinkedList::addSecond(int data){

    Node* temp=new Node();
    temp->data=data;
    Node* node=head;
    while(node->next->prev!=NULL){
       node->next->prev=temp;
       temp->next=node->next;
       node->next=temp;
       
    }
    temp->prev=head;   
   

}

void DoubleLinkedList::getFront(){
    Node* node=head;
    if (node->prev==NULL)
        cout<<"front item is "<<node->data<<endl;
}

void DoubleLinkedList::getTail(){
    Node* node=head;
    while(node->next!=NULL){
        node=node->next;
    }
    cout<<"tail item is "<<node->data<<endl;

}

void DoubleLinkedList::removeFront(){
    Node* node=head;
    if(node->prev==NULL){
        node=head;
        head=node->next;
        head->prev=NULL;
    }
}

void DoubleLinkedList::removeTail(){
    Node* node=head;
    while(node->next!=NULL){
        node=node->next;
    }
    node->prev->next=NULL;
    node->prev=NULL;
      
}

void DoubleLinkedList::removeAll(){
    Node* node=head;
    while(head!=NULL){
        node=head;
        head=head->next;
        
    }}
    
void DoubleLinkedList::isEmpty(){
   if(head==NULL)
        cout<<"list is empty";
        else
            cout<<"list is not empty";
}

int main(){
    DoubleLinkedList newList;
    Node* head=NULL;
    newList.addFront(50);
    newList.addFront(75);
    newList.addFront(100);
    newList.addTail(25);
    newList.addSecond(55);
    newList.printListItems();
    newList.getFront();
    newList.getTail();
    newList.removeFront();
    newList.printListItems();
    newList.removeTail();
    newList.printListItems();
    newList.removeAll();
    newList.isEmpty();
    return 0;
};
