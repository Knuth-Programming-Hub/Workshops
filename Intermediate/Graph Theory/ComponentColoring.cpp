#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e2 + 10;

int n, m, col = 1;
vector<int> graph[MAXN];
int color[MAXN];

void dfs(int node){
    color[node] = col;

    for(auto u : graph[node]){
        if(color[u] == 0){
            dfs(u);
        }
    }
}

int main(){
    cin>> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(color, 0, sizeof color);

    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs(i);
            col++;
        }
    }

    for(int i = 1; i <= n; i++)
        cout<< i << ' ' << color[i] << endl;
}