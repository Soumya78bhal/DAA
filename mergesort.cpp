#include<bits/stdc++.h>
using namespace std;
#define ll long long

void merge(int arr[],int p,int q,int r);
void mergesort(int arr[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void merge(int arr[],int p,int q,int r){
    
    int l1=p,r1=q+1;
    vector<int> temp;

    while(l1<=q && r1<=r){
        if(arr[l1]<arr[r1]) temp.push_back(arr[l1++]);
        else temp.push_back(arr[r1++]);
    }

    while(l1<=q)temp.push_back(arr[l1++]);
    while(r1<=r)temp.push_back(arr[r1++]);
   
    ll k=0;
    for(int i=p;i<=r;i++){
        arr[i]=temp[k++];
    }

}

int main(){
    
    int arr[10]={2,5,1,5,6,2,6,8,9,3};
    mergesort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}