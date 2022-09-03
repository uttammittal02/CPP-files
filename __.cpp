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

using namespace std;
struct DSU{
        // const int N = 1e5 + 5;
        int N;

        vector<int> parent, Rank;

        DSU(int n){
                parent = vector<int>(n + 1);
                Rank = vector<int>(n + 1);
                N = n;
                makeSet();
        }
        

        void makeSet(){
                for(int i = 0; i <= N; i++){
                        parent[i] = i;
                }
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
void solve(){
    int n; cin >> n; 

    vector<vector<int> > g; 

    set<pair<int, pair<int, int> > > s; // cost, id1, id2

    for(int i = 0; i < n; i++){
        int x, y, z; cin >> x >> y >> z; 
        vector<int> t; t.push_back(x), t.push_back(y), t.push_back(z);
        g.push_back(t);
    }

    vector<vector<int> > X, Y, Z; 

    for(int i = 0; i < n; i++){
        vector<int> t; t.push_back(g[i][0]); t.push_back(i);

        X.push_back(t);
    }
    for(int i = 0; i < n; i++){
        vector<int> t; t.push_back(g[i][1]); t.push_back(i); 

        Y.push_back(t);
    }
    for(int i = 0; i < n; i++){
        vector<int> t; t.push_back(g[i][2]), t.push_back(i); 
        
        Z.push_back(t);
    }
    // cout << "OK" << endl; cout.flush();
    sort(X.begin(), X.end());

    sort(Y.begin(), Y.end());

    sort(Z.begin(), Z.end());

    vector<vector<vector<int> > > DS; DS.push_back(X), DS.push_back(Y), DS.push_back(Z);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            pair<int, pair<int, int> > t; 

            t.first = DS[j][i][0] - DS[j][i - 1][0];

            t.second = make_pair(DS[j][i][1], DS[j][i - 1][1]);

            s.insert(t);
        }
    }
    DSU dsu(100005);

    set<pair<int, pair<int, int> > > :: iterator it = s.begin();
    int ans = 0;
    
    while(it != s.end()){
        pair<int, pair<int, int> > t = *it; 

        if(dsu.findParent(t.second.first) != dsu.findParent(t.second.second)){
            // cout << t.first << ' ' << t.second.first << ' ' << t.second.second << endl;
            dsu.Union(t.second.first, t.second.second);

            ans += t.first; 
        }
        it++;
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}