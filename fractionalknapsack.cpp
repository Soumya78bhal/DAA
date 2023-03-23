#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<float,float> a,pair<float,float> b){
    return a.second>b.second;
}
void fracknapsack(vector<pair<float,float>> arr,float n){
    
    vector <pair<float,float>> ratio;
    for(int i=0;i<arr.size();i++){
        ratio.push_back({i,(arr[i].second/arr[i].first)});
    }

    sort(ratio.begin(),ratio.end(),cmp);
   
    int profit=0;
    for(int i=0;i<ratio.size();i++){
        int index=ratio[i].first;
        if(n>arr[index].first){
            profit+=arr[index].second;
            n-=arr[index].first;

            cout<<"Added object "<<index+1<<" fully, Weight:"<<arr[index].first<<endl;
            cout<<"Remaining capacity:"<<n<<endl;
        }
        else{
            float add=(n/arr[index].first);
            
            profit+=arr[index].second* add;
            cout<<"Added object "<<index+1<<" fractionally, Weight:"<<n<<endl;
            cout<<"Remaining capacity:"<<"0"<<endl;
            break;
        }
    }
    cout<<profit<<endl;
}

int main(){
    vector<pair<float,float>> arr={{10,60},{20,100},{30,120}};
    fracknapsack(arr,50);

return 0;
}