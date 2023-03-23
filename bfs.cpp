#include<bits/stdc++.h>
using namespace std;
#define ll long long

void bfs(vector<vector<int>> graph,int initial){
    queue<int> q;
    vector<bool> visited(graph.size());

    q.push(initial);
    visited[initial]=true;
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";

        for(int i=0;i<graph[curr].size();i++){
            if(!visited[graph[curr][i]]){
                visited[graph[curr][i]]=true;
                q.push(graph[curr][i]);
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

    bfs(graph,1);

return 0;
}