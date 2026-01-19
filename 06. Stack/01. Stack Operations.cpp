#include<bits/stdc++.h>
using namespace std;

void peekStack(int st[], int top){
    cout<<"Current Top: "<<st[top]<<endl;
}

int insertStack(int st[], int top, int sz){
    int k;
    cin>>k;
    if(top==(sz-1)){
        peekStack(st, top);
        return top;
    }
    top++;
    st[top]  = k;
    peekStack(st, top);
    return top;
}

int deleteStack(int st[], int top){
    if(top == -1){
        return top;
    }

    top--;
    peekStack(st, top);
    return top;
}

int main(){
    int sz = 10;
    int st[sz];
    int top = -1;
    top = insertStack(st, top, sz);
    top = insertStack(st, top, sz);
    top = insertStack(st, top, sz);
    top = insertStack(st, top, sz);
    top = deleteStack(st, top);
    top = deleteStack(st, top);
    return 0;
}
