#include<bits/stdc++.h>
using namespace std;

// Precedence function
int prec(char c){
    if(c=='*' || c=='/'){
        return 50;
    }
    else if(c=='+' || c=='-'){
        return 20;
    }
    else{
        return 0;
    }
}

// 1. INFIX TO POSTFIX
string infixToPostfix(string ss){
    stack<char> st;
    string pp = "";

    for(int i=0; i<ss.length(); i++){
        if(isalnum(ss[i])){
            pp += ss[i];
        }
        else if(ss[i]=='('){
            st.push(ss[i]);
        }
        else if(ss[i]==')'){
            while(st.top()!='(' && st.empty()==false){
                pp+= st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(st.empty()==false && prec(st.top()) >= prec(ss[i])){
                pp+= st.top();
                st.pop();
            }
            st.push(ss[i]);
        }
    }

    while(st.empty()==false){
        pp+= st.top();
        st.pop();
    }

    return pp;
}

// 2. INFIX TO PREFIX
string infixToPrefix(string ss){
    // Reverse the infix expression
    reverse(ss.begin(), ss.end());

    // Replace ( with ) and vice versa
    for(int i=0; i<ss.length(); i++){
        if(ss[i]=='('){
            ss[i]=')';
        }
        else if(ss[i]==')'){
            ss[i]='(';
        }
    }

    // Get postfix of modified expression
    stack<char> st;
    string pp = "";

    for(int i=0; i<ss.length(); i++){
        if(isalnum(ss[i])){
            pp += ss[i];
        }
        else if(ss[i]=='('){
            st.push(ss[i]);
        }
        else if(ss[i]==')'){
            while(st.top()!='(' && st.empty()==false){
                pp+= st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(st.empty()==false && prec(st.top()) > prec(ss[i])){
                pp+= st.top();
                st.pop();
            }
            st.push(ss[i]);
        }
    }

    while(st.empty()==false){
        pp+= st.top();
        st.pop();
    }

    // Reverse the result to get prefix
    reverse(pp.begin(), pp.end());

    return pp;
}

// 3. POSTFIX TO INFIX
string postfixToInfix(string ss){
    stack<string> st;

    for(int i=0; i<ss.length(); i++){
        if(isalnum(ss[i])){
            string op(1, ss[i]);
            st.push(op);
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string exp = "(" + op2 + ss[i] + op1 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

// 4. PREFIX TO INFIX
string prefixToInfix(string ss){
    stack<string> st;

    // Read from right to left
    for(int i=ss.length()-1; i>=0; i--){
        if(isalnum(ss[i])){
            string op(1, ss[i]);
            st.push(op);
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string exp = "(" + op1 + ss[i] + op2 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main(){
    string input;
    int choice;

    cout << "Choose conversion type:" << endl;
    cout << "1. Infix to Postfix" << endl;
    cout << "2. Infix to Prefix" << endl;
    cout << "3. Postfix to Infix" << endl;
    cout << "4. Prefix to Infix" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter expression: ";
    cin >> input;

    string result;

    switch(choice){
        case 1:
            result = infixToPostfix(input);
            cout << "Postfix: " << result << endl;
            break;
        case 2:
            result = infixToPrefix(input);
            cout << "Prefix: " << result << endl;
            break;
        case 3:
            result = postfixToInfix(input);
            cout << "Infix: " << result << endl;
            break;
        case 4:
            result = prefixToInfix(input);
            cout << "Infix: " << result << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
