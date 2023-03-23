#include<bits/stdc++.h>
using namespace std;
#define ll long long
int matrixchmult(vector<ll> arr){
    int n=arr.size();
    vector<vector<ll>> mat(n,vector<ll> (n));
    for(ll len=2;len<n;len++){
        for(ll row=0,col=len;row<n-len;row++,col++){
            mat[row][col]=INT_MAX;
            for(ll k=row+1;k<col;k++){
                mat[row][col]=min(mat[row][col],mat[row][k]+mat[k][col]+arr[row]*arr[k]*arr[col]);
            }
        }
    }
 return mat[0][n-1];
}
int main(){
    vector<ll> arr={10,100,20,5,80};
    int ans=matrixchmult(arr);
    cout<<ans<<endl;
return 0;
}