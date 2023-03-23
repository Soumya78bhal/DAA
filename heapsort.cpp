#include<bits/stdc++.h>
using namespace std;
#define ll long long

void heapify(vector<int> &arr,int n,int i){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;

    if(l<n && arr[l]>arr[largest])largest=l;
    if(r<n && arr[r]>arr[largest])largest=r;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(vector<int> &arr){
    int n=arr.size();
    for(int i=n/2;i>=0;i--)heapify(arr,n,i);

    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    vector<int> arr={2,3,1,8,5,3};
    heapsort(arr);

    for(auto &i:arr)cout<<i<<" ";
    cout<<endl;

return 0;
}