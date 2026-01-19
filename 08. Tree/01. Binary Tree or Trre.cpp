#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    struct Node{
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Tree(){
        root = nullptr;
    }

   Node* createNode(int value){
        Node* newNode = new Node();
        newNode->data = value;
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

    void displayPreorder(Node* root){
        if(root == nullptr) return;

        cout<<root->data<<" ";
        displayPreorder(root->left);
        displayPreorder(root->right);
    }

    void displayInorder(Node* root){
        if(root == nullptr) return;

        displayInorder(root->left);
        cout<<root->data<<" ";
        displayInorder(root->right);
    }

    void displayPostorder(Node* root){
        if(root == nullptr) return;

        displayPostorder(root->left);
        displayPostorder(root->right);
        cout<<root->data<<" ";
    }

    void displayLevelwise(Node* root){
        queue<Node*>q;
        q.push(root);

        while(q.empty()==false){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                Node* currentNode = q.front();
                cout<<currentNode->data<<" ";
                if(currentNode->left != nullptr)
                    q.push(currentNode->left);

                if(currentNode->right != nullptr)
                    q.push(currentNode->right);
                q.pop();
            }
            cout<<endl;
        }
    }

    int heightOfTree(Node* root){
        queue<Node*> q;
        q.push(root);
        int height = 0;

        while(!q.empty()){
            height++;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                Node* currentNode = q.front();
                q.pop();

                if(currentNode->left != nullptr)
                    q.push(currentNode->left);
                if(currentNode->right != nullptr)
                    q.push(currentNode->right);
            }

        }
        return height;
    }


    int widthOfTree(Node* root){
        queue<Node*> q;
        q.push(root);
        int width = 0;

        while(!q.empty()){
            int sz = q.size();
            width = max(width, sz);

            for(int i = 0; i < sz; i++){
                Node* currentNode = q.front();
                q.pop();

                if(currentNode->left != nullptr)
                    q.push(currentNode->left);
                if(currentNode->right != nullptr)
                    q.push(currentNode->right);
            }

        }
        return width;
    }


    void mirror(Node* root){
        if(root == nullptr) return;

        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }

};

int main(){
    //Creating the Tree

    Tree t;
    t.createRoot(1);
    t.insertLeft(t.root, 2);
    t.insertRight(t.root, 3);
    t.insertLeft(t.root->left, 4);
    t.insertRight(t.root->left, 5);
    t.insertLeft(t.root->right, 6);
    t.insertRight(t.root->right, 7);

    // Displaying the Tree
    cout<<"PreOrder Traversal: ";
    t.displayPreorder(t.root);
    cout<<endl;
    cout<<"InOrder Traversal:  ";
    t.displayInorder(t.root);
    cout<<endl;
    cout<<"PostOrder Traversal:";
    t.displayPostorder(t.root);
    cout<<endl;
    cout<<"Levelwise Traversal:";
    t.displayLevelwise(t.root);

    // Tree height and Width
    cout<<"Height of the Tree: "<<t.heightOfTree(t.root)<<endl;

    return 0;

}




