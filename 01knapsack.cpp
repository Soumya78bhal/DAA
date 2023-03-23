#include<bits/stdc++.h>
using namespace std;
#define ll long long

void knapSack(vector<int> wt,vector<int> val,int W){
    int n=wt.size();
    vector<vector<int>> mat(n+1,vector<int> (W+1));
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0)mat[i][j]=0;
            
            else if(wt[i-1]<=j){
                mat[i][j]=max(mat[i-1][j],(val[i-1]+mat[i-1][j-wt[i-1]]));  
            }
            
            else mat[i][j]=mat[i-1][j];
        }
    }
   
    cout<< mat[n][W]<<endl;
}


int main(){
    int n,W;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int> wt(n),val(n);
    cout<<"Enter weights:";
    for(auto &i: wt)cin>>i;
    cout<<"Enter value:";
    for(auto &i:val)cin>>i;
    cout<<"Enter maximum capacity:";
    cin>>W;
    knapSack(wt,val,W);
return 0;
}