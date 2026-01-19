#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];

    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    for(int k=1;k<n;k++){
        int t =A[k];
        int i=k-1;
        while(i>=0 && A[i]>t){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = t;
    }

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}

