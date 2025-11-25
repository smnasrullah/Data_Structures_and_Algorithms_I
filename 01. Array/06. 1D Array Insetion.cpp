#include<bits/stdc++.h>
using namespace std;
int main() {
    int *array;
    int i, siz, element, position;
    cout << "Enter the size of the array: ";
    cin >> siz;
    array = (int *)malloc(siz * sizeof(int));
    cout << "Enter " << siz << " elements:" << endl;
    for (i = 0; i < siz; i++)
    {
        cin >> array[i];
    }
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert: ";
    cin >> position;
    if (position < 0 || position > siz)
    {
        cout << "Invalid position." << endl;
        free(array);
        return 1;
    }
    siz++;
    array = (int *)realloc(array, siz * sizeof(int));
    for (int i = siz-1; i > position; i--)
    {
        array[i] = array[i - 1];
    }

    array[position] = element;
    cout << "Array after insertion:" << endl;
    for (int i = 0; i < siz; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    free(array);
    return 0;
}
