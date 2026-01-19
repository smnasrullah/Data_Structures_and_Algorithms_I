#include <iostream>
using namespace std;
#define MAX_SIZE 100
struct Item {
    int value;
    int priority;
};

class PriorityQueue {
private:
    Item arr[MAX_SIZE];  // fixed-size array
    int size;       // current number of elements

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert an element into the queue
    void enqueue(int value, int priority) {
        if (size == MAX_SIZE) {
            cout << "Queue is Full!" << endl;
            return;
        }

        arr[size].value = value;
        arr[size].priority = priority;
        size++;
    }

    // Find index of element with highest priority
    int getHighestPriorityIndex() {
        int highest = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i].priority > arr[highest].priority) {
                highest = i;
            }
        }
        return highest;
    }

    // Remove element with highest priority
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        int highestIndex = getHighestPriorityIndex();

        // Shift elements to fill the gap
        for (int i = highestIndex; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Get the element with highest priority without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int highestIndex = getHighestPriorityIndex();
        return arr[highestIndex].value;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Priority Queue contents:\n";
        for (int i = 0; i < size; i++) {
            cout << "Value: " << arr[i].value
                 << ", Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);

    pq.display();

    cout << "\nHighest priority element: " << pq.peek() << endl;

    pq.dequeue();
    cout << "\nAfter removing highest priority element:\n";
    pq.display();

    return 0;
}

