#include<bits/stdc++.h>
using namespace std;
#define ll long long
int partition(vector<ll> &arr ,int p,int r){
    int i=p-1;
    int x=arr[r];
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            i++;
            
            swap(arr[i],arr[j]);          
        }
    }
    swap(arr[i+1],arr[r]);
    return (i+1);
}
void quicksort(vector<ll> &arr,int p,int r){
    if(p<r){
        int q=partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}
int main(){
    vector<ll> arr={2 ,5 ,3 ,6,7};
    quicksort(arr,0,4);
    for(ll i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}