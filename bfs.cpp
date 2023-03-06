#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5;
bool visited[Max];
vector<int> dist(Max);
void bfs(int src, vector<int> g[])
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        bool flag = false;
        for (auto child : g[cur])
        {
            if (!visited[child])
            {
                cout << cur << "-->" << child << "-->";
                q.push(child);
                dist[child] = dist[cur] + 1;
                visited[child] = true;
                flag = true;
            }
        }
        if (flag)
            cout << " || ";
    }
}

int main()
{
    int node, edges;
    cin >> node >> edges;
    vector<int> g[node + 1];
    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1, g);
    cout << "distance = "<<dist[node] << endl;
}
