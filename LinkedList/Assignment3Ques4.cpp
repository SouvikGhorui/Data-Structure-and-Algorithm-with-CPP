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
        head = NULL;
        tail = NULL;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail-> next = newNode;
            tail = newNode;
        }
    }

    void show(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp ->next;
        }
        cout<<"NULL"<<endl;

    }
    void push_front(int val){ //O(1)
        Node* newNode = new Node(val);
        if(head ==NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode ->next = head;
            head = newNode;
        }
    }
    void insert(int pos,Node* node){
        int count = 0;
        Node* temp = head;
        if(pos ==0){
            push_front(node->data);
            return;
        }
        while(count != pos-1){
            temp =temp->next;
            count ++;
        }
        node->next=temp->next;
        temp->next = node;

    }
    void remove_insert(int remove_pos, int insert_pos){
        Node* temp = head;
        int count= 0;
        if(remove_pos ==0){
            head = head->next;
        }
        else{
        while(count != remove_pos-1){
            temp= temp->next;
            count ++;
        }
    }
        Node* tempNode = new Node(temp->next->data);
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    
        // Now we insert the new node to the desired location
        insert(insert_pos,tempNode);
    

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

    LL.remove_insert(3,4);
    LL.show();

    return 0;
}