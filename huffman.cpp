#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int val;
    char alp;
     Node* left=NULL;
     Node* right=NULL; 
};

vector<Node*> createNode(vector<ll> arr,vector<char> str){
    vector<Node*> nodearr;
    for(int i=0;i<arr.size();i++){
        Node *temp=new Node();
        temp->val=arr[i];
        temp->alp=str[i];       
        nodearr.push_back(temp);       
    }
    return nodearr;
}

Node* mergenode(Node *a,Node *b){
    Node* c=new Node();
    c->val=a->val+b->val;
    c->alp='0';
    if(a->val<=b->val){
        c->left= a;
        c->right=b;
    }
    else{
        c->left= b;
        c->right=a;
    }
    return c;
}
bool cmp(Node* a,Node* b){
    return a->val>b->val;
}

void buildtree(vector<Node*> &strarr){
    while(strarr.size()!=1){
        pop_heap(strarr.begin(),strarr.end(),cmp);
        Node* a=strarr[strarr.size()-1];
        strarr.pop_back();
        pop_heap(strarr.begin(),strarr.end(),cmp);
        Node* b=strarr[strarr.size()-1];
        strarr.pop_back();
        Node* c=mergenode(a,b);
        strarr.push_back(c);
        push_heap(strarr.begin(),strarr.end(),cmp);

    }
}
void traverse(struct Node* node,string &str,vector<pair<char,string>> &ans)
{
    if (node->left==NULL && node->right==NULL){
        ans.push_back({node->alp,str});
        str.pop_back();
        return;
    }
    str.push_back('0');
    traverse(node->left,str,ans);
    str.push_back('1');
    traverse(node->right,str,ans);
    
    str.pop_back();
}
int main(){
    ll n;
    cout<<"Enter number of inputs:";
    cin>>n;
    
    vector<ll> arr(n);
    vector<char> str(n);
    cout<<"Enter charater and frequency"<<endl;
    for(int i=0;i<n;i++) cin>>str[i]>>arr[i];
    
    vector<Node*> strarr=createNode(arr,str);
    
    make_heap(strarr.begin(),strarr.end(),cmp);
    buildtree(strarr);
    vector<pair<char,string>> ans;
    string s;
    traverse(strarr[0],s,ans);
    
    cout<<"Huffman Code"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
return 0;
}