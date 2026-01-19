#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];

    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    for(int k=0;k<n-1;k++){
        int sv = INT_MAX;
        int sp = -1;
        for(int i=k;i<n;i++){
            if(A[i]<sv){
                sv = A[i];
                sp = i;
            }
        }
        int t = A[k];
        A[k] = A[sp];
        A[sp] = t;
    }

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}

