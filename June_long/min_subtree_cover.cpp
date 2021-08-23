#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#define And &&
#define Or ||
#define endl '\n'
#define sp " "
#define int long long
#define int_max INT64_MAX
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD 1000000007;
#define pii pair<int, int>
#define usi unordered_set<int>
#define osi set<int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

class Graph
{
public:
    // map<int, bool> visited;
    map<int, vector<int> > adj;
    vi depths;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    int DFS(int v,int sum, int parent);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

int Graph::DFS(int v, int sum, int parent)
{
                // cout<<v<<endl;
    if(adj[v].size()==1 && v!=1) {sum++; depths.pb(sum); return sum;}
    sum++;
    // Mark the current node as visited and
    // print it
    
    // cout << v << " ";
    // vi list_of_sums(0);

    // Recur for all the vertices adjacent
    // to this vertex
    int max_ = 0;
    for (int i=0; i<adj[v].size(); i++)
        {
            // cout << "print node number " << v << endl;
            if (adj[v][i]!=parent){
                max_ = max(max_, DFS(adj[v][i], sum, v));
            }
        }
    // sort(list_of_sums.begin(), list_of_sums.end());
    // for(int i=list_of_sums.size()-1; i>=0; i--)
    // {
    //     // cout << "current sum = " << curr_sum << endl;
    //     curr_sum+=(list_of_sums.size()-i)*(list_of_sums[i]);
    // }
    // visited[v] = true;
    return max_;
}


int32_t main(){
    test{
        int n, k;
        cin>>n>>k;
        Graph tree;
        tree.depths.resize(0);
        tree.adj.clear();
        loop(i, 0, n-1){
            int u, v;
            cin>>u>>v;
            tree.addEdge(u, v);
            tree.addEdge(v, u);
            // cout<<u<<sp<<v<<endl;
        }
        if (k==1) {cout<<1<<endl; continue;}
        // cout<<tree.adj[1].size()<<endl;
        // cout<<endl;
        vi depths_1;
        loop(i, 0, tree.adj[1].size()){
            depths_1.pb(tree.DFS(tree.adj[1][i], 0, 1));
        }
        sort(all(depths_1));
        int i = sz(depths_1);
        int ans = depths_1[i-1];
        i-=2;
        int cnt = 0;
        while (ans < k And i>=0){
            ans += depths_1[i];
            i--;
            cnt++;
        }
        // cout<<i<<sp<<depths_1[i+1]<<endl;
        if ((cnt==1) || (cnt == 0)) cnt = 2;
        cout<<cnt<<endl;
    }
}
