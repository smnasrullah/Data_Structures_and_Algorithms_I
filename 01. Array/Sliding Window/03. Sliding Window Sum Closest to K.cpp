#include<bits/stdc++.h>
using namespace std;
int main()
{
    int D,siz,i,j,k,WSize,sum;
    cout<<"Enter the size of array: ";
    cin>>siz;
    int a[siz];
    cout<<"Enter the elements: "<<endl;
    for(i=0;i<siz;i++)
    {
        cin>>k;
        a[i]=k;
    }
    cout<<"Give Window Size: ";
    cin>>WSize;
    int arr[siz-WSize+1];
    for(i=0; i<(siz-WSize+1); i++)
    {
        sum = 0;
        for(j=0;j<WSize;j++)
        {
            sum = sum + a[i+j];
        }
        arr[i]=sum;
    }
    cout<<"Give a Number: ";
    cin>>D;
    int z,diff= 999;
    for(i=0; i<(siz-WSize+1); i++)
    {
        if(abs(D-arr[i])<diff)
        {
            diff = abs(D-arr[i]);  // FIXED: Added abs() here
            z=arr[i];
        }
    }
    cout<<"Nearest Sum is "<<z;
    return 0;
}
