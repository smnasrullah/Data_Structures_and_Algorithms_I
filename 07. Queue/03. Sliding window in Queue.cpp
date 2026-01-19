#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>arr={10,-2,-5,12,-11,22,15,18};
   int k=3;

   queue<int>q;
   for(int i=0; i<arr.size();i++){

 if(arr[i]<0){
        q.push(i);
    }

    int win_start=i-k+1;
    if(!q.empty()&&q.front()<win_start){
        q.pop();
    }
   

    if(i>=k-1){
        if(!q.empty()){
           cout<<arr[q.front()]<<" ";

        }
        
        else 
        cout<<"0 ";
    }




   }



    return 0;
}