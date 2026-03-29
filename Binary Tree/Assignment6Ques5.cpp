#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int val;
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

int idx = -1;
void insert(Node* &root, int key){
    if(root == NULL){
        root = new Node(key);
        return;
    }
    if(root->val > key){
        insert(root->left, key);
    }
    else{
        insert(root->right, key);
    }
}

int ele = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx]== -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    
    return root;

}

int count = 0;
int searchNode(Node* root, int key){
    if(root == NULL){
        return -1;
    }
    count++;
    if(root->val > key){
        searchNode(root->left, key);
    }
    else if(root->val < key){
        searchNode(root->right, key);
    }else{
        return count;
    }


}

void deleteEle(Node* root, int key){
    
}


void preOrder(Node* root){
    if( root == NULL) return;
    cout<<root->val<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){

        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }

        cout<<curr->val<< " ";
        if (curr->left != NULL){
            q.push(curr->left);
        }
        if (curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}



int main(){
    vector<int> p = {1 ,2 ,-1 ,-1 , 3 , 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(p);
    levelOrder(root);
    cout<<"after inserting"<<endl;
    insert(root, 30);
    levelOrder(root);
    cout<<searchNode(root, 5);
    return 0;
}