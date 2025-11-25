#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    int n1 = s1.size();
    cout << "Enter second string: ";
    cin >> s2;
    int n2 = s2.size();
    if(n1==n2)
    {
        if (s1 == s2) {
        cout << "Same" << endl;
    }
    }
    else
        cout << "Not Same" << endl;
    return 0;
}
