#include<bits/stdc++.h>
using namespace std;

class BST{
public:
    struct Node{
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    BST(){
        root = nullptr;
    }

    Node* createNode(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    void createRoot(int value){
        if(root != nullptr){
            cout<<"Root already exists"<<endl;
            return;
        }
        root = createNode(value);
    }

    void insertLeft(Node* parent, int child){
        if(parent->left != nullptr){
            cout<<"Left child already exists"<<endl;
            return;
        }
        parent->left = createNode(child);
    }

    void insertRight(Node* parent, int child){
        if(parent->right != nullptr){
            cout<<"Right child already exists"<<endl;
            return;
        }
        parent->right = createNode(child);
    }

    void insertAtBST(int value){
        if(root == nullptr){
            root = createNode(value);
            return;
        }

        Node* currentNode = root;
        Node* parentNode = nullptr;

        while(currentNode != nullptr){
            parentNode = currentNode;
            if(value < currentNode->data){
                currentNode = currentNode->left;
            }
            else if(value > currentNode->data){
                currentNode = currentNode->right;
            }
        }

        if(parentNode->data > value){
            insertLeft(parentNode, value);
        }
        else if(parentNode->data < value){
            insertRight(parentNode, value);
        }

    }

    Node* recursiveInsert(Node* root, int value){
        if(root == nullptr){
            root = createNode(value);
            return root;
        }
        if(value < root->data){
            root->left = recursiveInsert(root->left, value);
        }
        if(value > root->data){
            root->right = recursiveInsert(root->right, value);
        }
        return root;

    }

    Node* searchBST(Node* root, int value){
        if(root == nullptr || root->data == value)
            return root;
        if(value < root->data)
            return searchBST(root->left, value);
        else
            return searchBST(root->right, value);
    }

    void displayInorder(Node* root){
        if(root == nullptr) return;

        displayInorder(root->left);
        cout<<root->data<<" ";
        displayInorder(root->right);
    }


};

int main(){
    BST t;
/**
    t.insertAtBST(50);
    t.insertAtBST(30);
    t.insertAtBST(20);
    t.insertAtBST(40);
    t.insertAtBST(70);
    t.insertAtBST(60);
    t.insertAtBST(80);
**/
    t.root = t.recursiveInsert(t.root,50);
    t.root = t.recursiveInsert(t.root,30);
    t.root = t.recursiveInsert(t.root,20);
    t.root = t.recursiveInsert(t.root,40);
    t.root = t.recursiveInsert(t.root,70);
    t.root = t.recursiveInsert(t.root,60);
    t.root = t.recursiveInsert(t.root,80);

    BST::Node* found = t.searchBST(t.root, 20);
    if(found == nullptr){
        cout<<"Node 20 not found"<<endl;
    }
    else{
        cout<<"Node 20 is found"<<endl;
    }
    t.displayInorder(t.root);

return 0;
}


