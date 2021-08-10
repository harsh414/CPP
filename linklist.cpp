#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void insertFront(Node **head,int val){ // inserts node at front of ll;
    Node *newNode = new Node();
    newNode->data= val;
    if(head==NULL){
        *head= newNode;
        return;
    }
    newNode->next=*head;
    *head=newNode;
}

// 8 9 10 x
void insertEnd(Node *head,int val){ // inserts node at end of ll;
    Node *newNode = new Node();
    newNode->data= val;
    if(head==NULL){
        head= newNode;
        return;
    }
    while(head->next!= NULL){
        head= head->next;
    }
    head->next= newNode;
    newNode->next=NULL;
}

void print(Node *head){
    while (head !=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void deleteNode(Node *head, int val){
    Node* temp = head;
    Node* prev = NULL;
    if(head->data== val){
        head= temp->next;
        delete temp;
        return;
    }

    while (temp->data != val && temp!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    if (temp == NULL)
        return;
    prev->next= temp->next;
    delete temp;
    
}
int main(){
    Node *head= NULL;
    insertFront(&head,10);
    insertFront(&head,9);
    insertFront(&head,8);  
    // output 8 9 10
    insertEnd(head,100);
    deleteNode(head,10); //jey 10;
    print(head);
}