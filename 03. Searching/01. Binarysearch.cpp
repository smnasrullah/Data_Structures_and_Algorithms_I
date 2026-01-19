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

    int l=0;
    int u=sz-1;

    while(l<=u){
        int m=(l+u)/2;
        if(k==v[m]){
            cout<<"Found";
            return 0;
        }
        else if(k<v[m]){
            u = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout<<"Not Found";
    return 0;
}
