#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int length = str.size();
    int i;
    cout << "Original string: " << str << endl;

    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}
