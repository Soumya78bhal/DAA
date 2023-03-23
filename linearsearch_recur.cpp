#include<bits/stdc++.h>
using namespace std;
#define ll long long

void linearsearch(int arr[],int n,int key){
    if(n<0){
        cout<<"Element not found"<<endl;
        return;
    }
    if(arr[n]==key){
        cout<<"Element found at index "<<n<<endl;
        return;
    }
    linearsearch(arr,n-1,key);

}
int main(){
    int arr[5]={1,8,3,6,2};
    linearsearch(arr,4,6);
return 0;
}