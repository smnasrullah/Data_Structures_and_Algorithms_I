#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='*'){
        return 100;
    }
    else if(c=='+'){
        return 50;
    }
    else if(c=='-'){
        return 30;
    }
    return 0;
}

int main(){
    string in;
    cin>>in;
    string pp="";
    stack<char> s;

    for(int i=0;i<in.length();i++){
        if(in[i]=='('){
            s.push(in[i]);
        }
        else if(isalnum(in[i])){
            pp+= in[i];
        }
        else if(in[i]==')'){
            while(s.top()!='(' && s.empty()==false){
                pp += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(s.empty()==false && prec(s.top()) >= prec(in[i])){
                pp += s.top();
                s.pop();
            }
            s.push(in[i]);
        }
    }

    while(s.empty()==false){
        pp += s.top();
        s.pop();
    }

    cout<<pp;
    return 0;
}
