#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int v)
    {
        data = v;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node* start;

    LinkedList()
    {
        start = nullptr;
    }

    void insertAtEnd(int k)
    {
        Node* newNode = new Node(k);

        if(start == nullptr)
        {
            start = newNode;
            return;
        }

        Node* p = start;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newNode;
    }

    int findMiddle()
    {
        if(start == nullptr) return -1;

        Node* slow = start;
        Node* fast = start;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main()
{
    int n;
    cin >> n;

    LinkedList ll;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ll.insertAtEnd(x);
    }

    cout << ll.findMiddle() << endl;

    return 0;
}
