#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node* buildTree(vector<int> preorder ){
    idx++;
    if(preorder[idx]== -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    
    return root;

}

//preorder traversal
void preOrder(Node* root){
    if( root == NULL) return;
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

//inorder traversal
void inOrder(Node* root){
    if (root == NULL) return;
    inOrder(root->left);
    cout<< root->data<<endl;
    inOrder(root->right);
}

//postorder traversal
void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<< endl;
}


//level order
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

        cout<<curr->data<< " ";
        if (curr->left != NULL){
            q.push(curr->left);
        }
        if (curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

// Height of tree
int height(Node* root){
    if(root == NULL) return 0;
    int leftht = height(root -> left);
    int rightht = height(root -> right);
    return max(leftht, rightht)+1; 
}

// Count Nodes 
int countNode(Node* root){
    if (root == NULL){
        return 0;
    }
    int countLeft = countNode(root->left);
    int countRight = countNode(root->right);
    return countLeft + countRight + 1;
}

// sum of nodes 
int sumOfNodes(Node* root){
    if(root == NULL) return 0;
    int leftsum = sumOfNodes(root-> left);
    int rightsum = sumOfNodes(root-> right);
    return leftsum + rightsum + root->data;
}

int main(){
    vector<int> preorder = {1 ,2 ,-1 ,-1 , 3 , 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    levelOrder(root);
    cout<<"Height of the binary tree= " <<height(root)<<endl;
    cout<<"Total number of nodes = "<<countNode(root)<<endl;
    cout<<"Sum of nodes = "<< sumOfNodes(root)<< endl;

    return 0;
}
