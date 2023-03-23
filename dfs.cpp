#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> graph,int initial){
    stack<int> stack;
    vector<bool> visited(graph.size());

    stack.push(initial);
    visited[initial]=true;
    
    while(!stack.empty()){
        int curr=stack.top();
        stack.pop();
        cout<<curr<<" ";

        for(int i=0;i<graph[curr].size();i++){
            if(!visited[graph[curr][i]]){
                visited[graph[curr][i]]=true;
                stack.push(graph[curr][i]);
            }
        }
    }

}

int main(){
    ll n;
    cout<<"Enter number of nodes:";
    cin>>n;

    vector<vector<int>> graph(n+1);

    ll k;
    cout<<"Enter number of edges:";
    cin>>k;
    cout<<"Enter edges"<<endl;
    for(int i=0;i<k;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int init;
    cout<<"Enter initial node:";
    cin>>init;
    dfs(graph,init);

return 0;
}