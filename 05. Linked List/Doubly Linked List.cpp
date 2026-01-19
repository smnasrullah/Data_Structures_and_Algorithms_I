#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int v)
    {
        data = v;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node* start;

    DoublyLinkedList()
    {
        start = nullptr;
    }

//TRAVERSING
    void traverse()
    {
        Node* p = start;
        while(p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

//INSERTDATA
    void insertData(int k)
    {
        Node* newNode = new Node(k);
        newNode->next = start;

        if(start != nullptr)
        {
            start->prev = newNode;
        }

        start = newNode;
    }

//SORTED DATA
    void sortedlist()
    {
        if(start == nullptr || start->next == nullptr) return;

        bool swapped;
        do
        {
            swapped = false;
            Node* current = start;
            Node* nextNode = start->next;

            while(nextNode != nullptr)
            {
                if(current->data > nextNode->data)
                {
                    swapped = true;

                    if(current->prev != nullptr)
                    {
                        current->prev->next = nextNode;
                    }
                    else
                    {
                        start = nextNode;
                    }

                    Node* temp = nextNode->next;
                    nextNode->prev = current->prev;
                    nextNode->next = current;
                    current->prev = nextNode;
                    current->next = temp;

                    if(temp != nullptr)
                    {
                        temp->prev = current;
                    }

                    nextNode = current->next;
                }
                else
                {
                    current = nextNode;
                    nextNode = nextNode->next;
                }
            }
        }
        while(swapped);
    }

//REVERSE
    void Reverse()
    {
        Node* p = start;
        Node* temp = nullptr;

        while(p != nullptr)
        {
            temp = p->prev;
            p->prev = p->next;
            p->next = temp;
            p = p->prev;
        }

        if(temp != nullptr)
        {
            start = temp->prev;
        }
    }

//FINDMIDDLE
    Node* findMiddle()
    {
        if(start == nullptr) return nullptr;

        Node* slow = start;
        Node* fast = start;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

//INSERT AFTER MIDDLE
    void insertAfterMiddle(int k)
    {
        Node* middle = findMiddle();
        if(middle == nullptr) return;

        Node* newNode = new Node(k);
        newNode->next = middle->next;
        newNode->prev = middle;

        if(middle->next != nullptr)
        {
            middle->next->prev = newNode;
        }

        middle->next = newNode;
    }

//DELETE AFTER MIDDLE
    void deleteAfterMiddle()
    {
        Node* middle = findMiddle();
        if(middle == nullptr || middle->next == nullptr) return;

        Node* nodeToDelete = middle->next;
        middle->next = nodeToDelete->next;

        if(nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->prev = middle;
        }

        delete nodeToDelete;
    }

//FIND CYCLE IN A LINKED LIST
    void Cycle()
    {
        if(start == nullptr) return;

        Node* slow = start;
        Node* fast = start;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                cout << "Cycle detected!" << endl;
                return;
            }
        }
        cout << "No cycle found" << endl;
    }

//CYCLE START NODE
    void cycleNode()
    {
        if(start == nullptr) return;

        Node* slow = start;
        Node* fast = start;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                slow = start;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                cout << "Cycle starts : " << slow->data << endl;
                return;
            }
        }

        cout << "No cycle in the list" << endl;
    }

//CREATE CYCLE FROM A NODE
    void createCycle(int value)
    {
        if(start == nullptr) return;

        Node* p = start;
        Node* cycleNode = nullptr;

        while(p->next != nullptr)
        {
            if(p->data == value)
            {
                cycleNode = p;
            }
            p = p->next;
        }

        if(cycleNode != nullptr)
        {
            p->next = cycleNode;
            cout << "Cycle Create" << endl;
        }
        else
        {
            cout << "Value " << value << " not found in list, cycle not created." << endl;
        }
    }
};

int main()
{
    DoublyLinkedList dl;

    dl.insertData(5);
    dl.traverse();
    dl.insertData(10);
    dl.traverse();
    dl.insertData(7);
    dl.traverse();
    dl.insertData(3);
    dl.traverse();
    dl.insertData(13);
    dl.traverse();

//SORT
    dl.sortedlist();
    dl.traverse();

//REVERSE
    dl.Reverse();
    dl.traverse();

//FINDMIDDLE
    cout << dl.findMiddle()->data << endl;

//INSERT AFTER MIDDLE
    dl.insertAfterMiddle(33);
    dl.traverse();

//DELETE AFTER MIDDLE
    dl.deleteAfterMiddle();
    dl.traverse();

    dl.Cycle();

    dl.cycleNode();

    dl.createCycle(10);
    dl.Cycle();
    dl.cycleNode();

    return 0;
}
