#include<bits/stdc++.h>
using namespace std;
#define ll long long

int lcs(string a,string b){
    int m=a.size();
    int n=b.size();
    int mat[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                mat[i][j]=0;
                cout<<"|"<<mat[i][j]<<" ";
            }
            else if(a[i-1]==b[j-1]){
                mat[i][j]=mat[i-1][j-1]+1;
                cout<<"\\"<<mat[i][j]<<" ";
            }
            else{ 
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
                if(mat[i][j]==mat[i][j-1])cout<<"-"<<mat[i][j]<<" ";
                else cout<<"|"<<mat[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return mat[m][n];
}

int main(){
    cout<<lcs("DANGER","MANAGER");
return 0;
}