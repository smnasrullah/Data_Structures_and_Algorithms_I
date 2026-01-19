//Singly Linked List
#include<bits/stdc++.h>
using namespace std;

//Create a Node
class Node
{
public:
    int DATA;
    Node* next;

    Node(int v)
    {
        DATA=v;
        next = nullptr;
    }
};

//Operation on Node in Linked List
class Linkedlist
{
public:
    Node* start;
    Linkedlist()
    {
        start = nullptr;
    }

    // TRAVERSAL
    void traverse(){
        Node* PTR = start;
        while(PTR != nullptr){
            cout<<PTR->DATA<<" ";
            PTR = PTR->next;
        }
        cout<<endl;
    }

    //SEARCHING
    void searching(int V)
    {
        Node* PTR = start;
        Node* POS = nullptr;
        int flag = 0;
        while(PTR != nullptr)
        {
            if (PTR->DATA == V)
            {
                POS = PTR;
                flag = 1;
                break;
            }
            else
                PTR = PTR->next;
        }
        if(flag == 1)
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
    }


//INSERTION

    // INSERT AT FIRST
    void insertFirst(int v){
        Node* NEW = new Node(v);
        NEW->next = start;
        start = NEW;
    }

    // INSERT AT LAST
    void insertLast(int v){
        Node* NEW = new Node(v);
        Node* PTR = start;
        while(PTR->next != nullptr){
            PTR = PTR->next;
        }
        PTR->next = NEW;
    }

    // INSERT BEFORE A NODE
    void insertBefore(int  v, int k){
        Node* NEW = new Node(v);
        Node* PTR = start;
        while(PTR->next->DATA != k){
            PTR = PTR->next;
        }
        NEW->next = PTR->next;
        PTR->next = NEW;
    }

    //INSER AFTER A NODE
    void insertAfter(int  v, int k){
        Node* NEW = new Node(v);
        Node* PTR = start;
        while(PTR->DATA != k){
            PTR = PTR->next;
        }
        NEW->next = PTR->next;
        PTR->next = NEW;
    }

// DELETION

    // DELETE FIRST NODE
    void deleteFirst()
    {
        if( start == nullptr)
            cout<<"No Node";
        start = start->next;
    }

    // DELETE LAST NODE
    void deleteLast(){
        if( start == nullptr)
            cout<<"No Node";
        Node* PTR = start;
        while(PTR->next->next != nullptr){
            PTR = PTR->next;
        }
        PTR->next = nullptr;
    }

    // dELETE AFTER A NODE
    void deleteAfter(int k){
        Node* PTR = start;
        if( PTR == nullptr)
            cout<<"No Node";

        else
        {
            while(PTR->DATA!=k)
                PTR = PTR->next;

        if(PTR->next == nullptr)
            cout<<"Not Possible";
        if(PTR->next->next == nullptr)
            PTR->next = nullptr;
        else
            PTR->next = PTR->next->next;
        }

    }

    // DELETE BEFORE A NODE
    void deleteBefore(int k){
        Node* PTR = start;
        if( PTR == nullptr)
            cout<<"No Node";

        if(PTR->DATA == k)
            {cout<<"Not Possible";}
        if(PTR->next->DATA == k)
            start = PTR->next;
        else
        {
           while(PTR->next->next->DATA!=k){
             PTR = PTR->next;
        }
           PTR->next = PTR->next->next;
        }
    }
};

int main(){

    Linkedlist lst;
    lst.insertFirst(2);
    lst.traverse();
    lst.insertFirst(10);
    lst.traverse();
    lst.insertFirst(3);
    lst.traverse();
    lst.insertLast(5);
    lst.traverse();
    lst.insertLast(7);
    lst.traverse();
    lst.insertBefore(9, 5);
    lst.traverse();
    lst.insertAfter(11, 5);
    lst.traverse();
    lst.deleteFirst();
    lst.traverse();
    lst.deleteLast();
    lst.traverse();
    lst.deleteBefore(2);
    lst.traverse();
    lst.searching(10);
    lst.deleteAfter(11);
    lst.traverse();

    return 0;
}

