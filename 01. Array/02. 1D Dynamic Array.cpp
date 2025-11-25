#include<bits/stdc++.h>
using namespace std;

int main()
{
    int siz,i,k,start,close, sum=1;

    cout<<"Enter the size of array: ";
    cin>>siz;

    vector<int>a;

    cout<<"Enter the elements: "<<endl;

    for(i=0;i<siz;i++)
    {
        cin>>k;
        a.push_back(k);
    }

    cout<<"Give star Index: ";
    cin>>start;
    cout<<"Give End Index: ";
    cin>>close;

    for(i=start; i<close+1; i++)
    {
        sum = sum* a[i];
    }
    cout<<"Multiplication= "<<sum;

    return 0;
}

