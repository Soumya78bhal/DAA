#include<bits/stdc++.h>
using namespace std;
#define ll long long

void largest(int arr[],int n,int max){
    if(n<0){
        cout<<"Largest element:"<<max<<endl;
        return;
    }
    if(max<arr[n])max=arr[n];
    largest(arr,n-1,max);

}
int main(){
    int arr[5]={1,8,3,6,2};
    largest(arr,4,INT_MIN);
return 0;
}