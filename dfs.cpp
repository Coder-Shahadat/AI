#include<bits/stdc++.h>
using namespace std;

const int Max = 1e5;
bool visited[Max] = {false};
void dfs(int v,vector<int>g[]){
    visited[v] = true; 
    cout << "-->" << v;
    for(auto child:g[v]){
        if(!visited[child])
            dfs(child,g);
    }
}

int main(){
    int node, edges;
    cin >> node >> edges; 
    vector<int> g[node];
    for (int i = 0; i < edges;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << "start";
    dfs(0,g);
}
