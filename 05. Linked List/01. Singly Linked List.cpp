#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int d;
    Node* next;

    Node(int v){
        d=v;
        next = nullptr;
    }

};

class Linkedlist{
public:
    Node* start;
    Linkedlist(){
        start = nullptr;
    }

    void traverse(){
        Node* p = start;
        while(p != nullptr){
            cout<<p->d<<" ";
            p = p->next;
        }
        cout<<endl;
    }

    void insertFirst(int v){
        Node* newNode = new Node(v);
        newNode->next = start;
        start = newNode;
    }

    void insertLast(int v){
        Node* newNode = new Node(v);
        Node* p = start;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = newNode;
    }

    void insertBefore(int  v, int k){
        Node* newNode = new Node(v);
        Node* p = start;
        while(p->next->d != k){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }

    void insertAfter(int  v, int k){
        Node* newNode = new Node(v);
        Node* p = start;
        while(p->d != k){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }

    void deleteFirst(){
        start = start->next;
    }

    void deleteLast(){
        Node* p = start;
        while(p->next->next != nullptr){
            p = p->next;
        }
        p->next = nullptr;
    }

    void deleteBefore(int k){
        Node* p = start;
        while(p->next->next->d!=k){
            p = p->next;
        }
        p->next = p->next->next;
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
    lst.deleteBefore(9);
    lst.traverse();

    return 0;
}
