
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

    bool search(Node* head, int x){
        Node* temp = head;
        while(temp !=NULL){
            if(temp->data ==x){
                return true;
            }
            temp = temp->next;
        }
        return false;
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

    int length(Node* head){
        Node* temp = head;
        int count =0;
        while(temp != NULL){
            count ++;
            temp = temp ->next;
        }
        return count;
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
    if(LL.search(LL.head,4)){
        cout<<"4 is in LinkedList"<<endl;
    }
    LL.show();
    cout<<"Total number of nodes in LinkedList= "<<LL.length(LL.head)<<endl;
    return 0;
}