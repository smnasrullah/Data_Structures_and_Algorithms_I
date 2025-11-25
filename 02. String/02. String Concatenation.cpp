#include <iostream>
using namespace std;

int main() {
    string str, strr;
    cin>>str>>strr;

    int n1=str.length();
    int n2 = strr.length();

    char ar[n1+n2+1];
    int i=0;
    while(str[i]!='\0'){
        ar[i] = str[i];
        i++;
    }
    int j=0;

    while(strr[j]!='\0'){
        ar[i] = strr[j];
        i++;
        j++;
    }
    ar[i] = '\0';
    cout<<ar;
}
