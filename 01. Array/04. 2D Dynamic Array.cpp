
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row,column,i,j,k,m= INT_MIN;

    cout<<"Enter the size of row and column: ";
    cin>>row>>column;
    vector<vector<int>>a;

    cout<<"Enter the elements: "<<endl;
    for(i=0;i<row;i++)
    {
        vector<int>v;
        for(j=0;j<column;j++)
         {
            cin >> k;
            v.push_back(k);
        }
        a.push_back(v);
    }

    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(a[i][j]>m)
                m= a[i][j];
        }
    }

    cout<<"Max= "<<m;
    return 0;
}
