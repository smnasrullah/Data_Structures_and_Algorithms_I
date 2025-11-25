#include<bits/stdc++.h>
using namespace std;

int main(){

    string s1, s2;
    cin>>s1>>s2;
    int c;
    for(int i=0;i<s1.length()-s2.length()+1;i++){
        c=0;
        for(int j = 0;j<s2.length();j++){
            if(s2[j] == s1[i+j]){
                c++;
            }
            else{
                break;
            }
        }
        if(c==s2.length()){
            break;
        }
    }

    if(c==s2.length()){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}
