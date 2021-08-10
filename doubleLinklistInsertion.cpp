#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
};


void insert_front(Node **head,int val){
    Node* newNode = new Node();
    newNode->data= val;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(*head==NULL){
        *head=newNode;
        return;
    }

   (*head)->prev = newNode;
    newNode->next= (*head);
    (*head)= newNode;
}

void insert_end(Node *head,int val){
    Node* newNode = new Node();
    newNode->data= val;
    newNode->next=NULL;
    while(head->next!=NULL){
        head=head->next;
    }
    newNode->prev=head;
    head->next=newNode;
}

// 10 20  30  x 40
void insertAfter(Node *head,int val){
    Node* newNode = new Node();
    newNode->data= val;
    newNode->next=NULL;
    newNode->next=head->next;
    head->next=newNode;
    newNode->prev=head;
}


// 10 20 x 30 40
void insertBefore(Node *head,int val){
    Node* newNode = new Node();
    newNode->data= val;
    newNode->next=head;
    newNode->prev=head->prev;
    head->prev->next= newNode;
    head->prev=newNode;
}



void print(Node *head){
    while((head)!=NULL){
        cout<<(head)->data<<" "; 
        head=head->next;
    }
}


int main() {
    Node *head= NULL;
    insert_front(&head,40);
    insert_front(&head,30);
    insert_front(&head,20);
    insert_front(&head,10);
    print(head);cout<<endl;
    // insert_end(head,50);
    // insert_end(head,60);
    // insert_end(head,70);
    // insert_end(head,50);
    // print(head);cout<<endl;
    // head=head->next;
    // head=head->next; // now poinnting 30
    // insertBefore(head,100);
    // head=head->prev;
    // cout<<head->data;
    // // print(head);
}