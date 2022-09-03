#include <stack>
#include <iomanip>
#include <ios>
#include <iterator>
#include <inttypes.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <numeric>
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
#include <climits>
#include <tuple>
#include <functional>

using i64 = long long;

struct DSU{
        // const int N = 1e5 + 5;
        const int N;

        vector <int> parent, Rank;

        DSU(int n) : N(n), parent(n), Rank(n, 1) 
        {
            std::iota(parent.begin(), parent.end(), 0);
        }       

        int findParent(int u){
                if(parent[u] == u){
                        return u;
                }
                return parent[u] = findParent(parent[u]);       // path compression
        }

        void Union(int u, int v){
                u = findParent(u);
                v = findParent(v);

                if (u == v)
                    return;

                if(Rank[u] > Rank[v])
                        parent[v] = u;
                        
                else if(Rank[v] > Rank[u])
                        parent[u] = v;
                
                else{
                        parent[v] = u;
                        Rank[u]++;
                }
        }
};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> adj[n];

    DSU d(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;

        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);  
        d.Union(u, v);
    }

    std::multiset< std::pair<int, int> > w;
    for (int i = 0; i < n; i++)
        w.emplace(a[i], i);

    i64 ans = 0;
    while (w.size() > 1)
    {
        auto cur = w.begin();
        int weight1 = cur->first, u = cur->second;

        w.erase(w.begin());
        cur = w.begin();

        int weight2 = cur->first, v = cur->second;

        if (d.findParent(u) == d.findParent(v))
            continue;

        d.Union(u, v);
        ans += std::abs(weight1 - weight2);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();
}