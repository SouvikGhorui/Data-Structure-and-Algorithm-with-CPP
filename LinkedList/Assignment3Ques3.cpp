
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

    void ReverseLL(Node* head){
        if(head == NULL){
            return;
        }
        ReverseLL(head->next);
        cout<<head->data<<" ";
        

    }

    void middleEle(Node* head){
        Node* temp = head;
        for(int i=0;i<lengthLL(temp)/2;i++){
            temp = temp ->next;
        }
        cout<<"Middle element = "<<temp->data;
    }

    int lengthLL(Node* head){
        Node* temp = head;
        if(temp == NULL){
            return 0;
        }
        int count = 0;
        while(temp!=NULL){
            count ++;
            temp= temp->next;
        }
        return count;
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
    // LL.ReverseLL(LL.head);
    cout<<LL.lengthLL(LL.head)<<endl;
    LL.middleEle(LL.head);
    return 0;
}