#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    int sz, k, s;
    cin>>sz;

    for(int i=0; i<sz;i++){
        cin>>s;
        v.push_back(s);
    }
    cin>>k;

    for(int i=0; i<sz;i++){
        if(v[i] == k){
            cout<<"Found";
            return 0;
        }
    }
    cout<<" Not Found";
    return 0;
}
