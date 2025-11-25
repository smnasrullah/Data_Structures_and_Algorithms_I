#include<bits/stdc++.h>
using namespace std;

int main()
{
    int siz,i,j,k,WSize,sum;

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

    for(i=0; i<(siz-WSize+1); i++)
    {
        sum = 0;
        for(j=0;j<WSize;j++)
        {
            sum = sum + a[i+j];
        }
        cout<<"Window No "<<i+1<<
               ",Sum= "<<sum<<endl;
    }
    return 0;
}
