#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;

    int i=0;
    int c=0;
    while(s[i]!='\0'){
        c++;
        i++;
    }
    cout<<"Length = "<<c;
    return 0;
}
