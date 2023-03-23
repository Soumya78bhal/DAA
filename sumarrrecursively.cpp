#include<bits/stdc++.h>
using namespace std;
#define ll long long

void summation(int arr[],int n,int sum){
    if(n<0){
        cout<<"Sum of elements:"<<sum<<endl;
        return;
    }
    sum+=arr[n];
    summation(arr,n-1,sum);

}
int main(){
    int arr[5]={1,8,3,6,2};
    summation(arr,4,0);
return 0;
}