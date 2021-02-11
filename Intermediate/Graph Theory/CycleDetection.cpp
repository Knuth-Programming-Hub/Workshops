#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e2 + 10;

int n, m;
vector<int> graph[MAXN];
int color[MAXN];

void detect_cycle(int node, int par){
    color[node] = 1;

    for(auto u : graph[node]){
        if(u != par){
            if(color[u] == 1){
                cout<< "Cycle detected!" << endl;
                exit(0);
            }
            detect_cycle(u, node);
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

    detect_cycle(1, -1);

    cout<< "No cycle detected!" << endl;
}