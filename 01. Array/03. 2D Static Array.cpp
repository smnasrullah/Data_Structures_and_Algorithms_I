#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row,column,i,j;
    cin>>row>>column;
    int a[row][column];
    int b[row-2][column-2];

    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cin>>k;
            a[i][j]=k;
        }
    }
    for(i=0;i<row-2;i++)
    {
        for(j=0;j<column-2;j++)
        {
            b[i][j] = a[i][j]+a[i][j+1]+a[i][j+2]+
                                a[i+1][j+1]+
                      a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
        }
    }

    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
