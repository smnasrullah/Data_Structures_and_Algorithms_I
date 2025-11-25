#include <iostream>
using namespace std;

int main() {
    char STR1[100], SubSTR[100];
    int n, m;
    cin.getline(STR1, 100);
    cin >> m;
    cin >> n;
    int i = m;
    int j = 0;

    while (STR1[i] != '\0' && n > 0) {
        SubSTR[j] = STR1[i];
        i = i + 1;
        j = j + 1;
        n = n - 1;
    }
    SubSTR[j] = '\0';
    cout << "Extracted Substring: " << SubSTR << endl;

    return 0;
}
