
// 1.Write a C++ program to create a singly linked list from n integers given by the user.
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

};
class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = tail = NULL;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }


    void pop_back(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        while(temp->next != tail){
            temp = temp ->next; 
        }
        temp -> next = NULL;
        delete tail;
        tail = temp; 
    }
    void show(){ //O(n)
        Node* temp;
        temp = head;
        while(temp !=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void pop(int x){
        if (head ==NULL){
            return;
        }
        Node* temp = head;
        if(head->data == x){
            pop_front();
            return;
        }
        while((temp-> next !=NULL)&& (temp->next->data !=x) ){    
            temp = temp ->next;
        }
        if(temp->next ==NULL){
            return;
        }
        if(temp->next ==tail){
            pop_back();
            return;
        }
        Node* toDelete = temp->next;
        temp->next=toDelete->next;
        delete toDelete;
        return; 
    }


};


int main(){
    int n;
    int temp;
    cout<<"Enter the number of element you want to enter"<<endl;
    cin>>n;
    LinkedList LL;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>temp;
        LL.push_back(temp);   
    }
    LL.show();
    LL.pop(3);
    LL.show();
    return 0;
}