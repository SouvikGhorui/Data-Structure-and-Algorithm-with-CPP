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
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
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
    void push_back(int val){ //O(1)
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){ //O(1)
        if(head==NULL){
            cout<<"There is nothing to delete!!";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){ //O(n)
        if(head ==NULL){
            cout<<"There is nothing to delete!!";
            return;
        }
        Node* temp = head;
        while(temp->next !=tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){ //O(n)
        if (pos <0){
            return;
        }
        else if(pos ==0){
            push_front(val);
        }
        else{
            Node* newNode = new Node(val);
            Node* temp = head;
            for(int i=0; i< pos-1;i++){
                if(temp ==NULL){
                    cout<<"Invaild pos";
                    return;
                }
                temp = temp->next;
            }
            newNode-> next = temp->next;
            temp->next = newNode;
        }
    }

    void Deletemiddle(int pos){
        if(head == NULL){
            return;
        }
        if(pos==0){
            pop_front();
            return;
        }
        Node* temp = head;
        for(int i = 0; i< pos -1; i ++){
            if(temp == NULL || temp->next ==NULL){
                return;
            }
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        if(toDelete == tail){
            tail = temp;  
        }
        temp->next = toDelete->next;
        toDelete->next = NULL;
        delete toDelete;
    }

    void search(int val){ //O(n)
        Node* temp = head;
        int count =0;
        while(temp !=NULL){
            if(temp->data ==val){
                cout<<"Value is in the "<<count<<" th place"<<endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout<<"Value is not in linkedlist"<<endl;
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
    List LL;
    LL.push_front(1);
    LL.push_front(2);
    LL.push_front(3);

    LL.insert(5,1);
    LL.show();
    LL.search(5);
    
    return 0;
}