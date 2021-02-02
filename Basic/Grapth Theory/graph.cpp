#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, 
    rb_tree_tag,
      tree_order_statistics_node_update>;

#define int           long long
#define pb            push_back
#define all(a)        (a).begin(),(a).end()
#define sz(x)         (int)x.size()
#define F             first
#define S             second
#define endl          "\n"
#define inf           (long long)1000000007
#define FOR(i, a, b)  for(int i=a; i<b; i++)
#define bigint        (long long) 1e18

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(aint(v), RNG);
// Use mt19937_64 for 64 bit random numbers. 

template <typename T>
T ceil(T a, T b){ return (a+b-1)/b; }

template<typename T>
T binpow(T a, T b, T m) {
  a %= m;
  T res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n; cin>>n;  // Number of Nodes
  int m; cin>>m;  // Number of Edges

  // Undirected Unweighted Graph Adjacency List: 
  
  vector<int> adj[n+1];

  for(int i=0;i<m;i++) {
    int a, b; cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);  // For a directed graph, remove this line.
  }
  
  // Undirected weighted Graph Adjacency List: 

  vector<pair<int, int>> adj2[n+1];

  for(int i=0;i<m;i++) {
    int a, b; cin>>a>>b;
    int w; cin>>w;
    adj2[a].push_back({b, w});
    adj2[b].push_back({a, w}); // For a directed graph, remove this line.
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);     
  int t=1;
  //cin>>t;
  FOR(i, 1, t+1){ 
    //cout<<"Case #"<<i<<": ";
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;

}
