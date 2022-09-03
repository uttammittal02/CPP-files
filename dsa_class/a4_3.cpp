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
#include <functional>
using namespace std;

class union_find
{
    vector<int> par, rank;
    public:
        union_find(int n)
        {
            par.resize(n);
            rank.resize(n);
            for (int i = 0; i < n; ++i){
                par[i] = i;
                rank[i] = 1;
            }
        }
    int get(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = get(par[x]);
    }
    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        else
        {
            if (rank[y] > rank[x])
                swap(x, y);
            par[y] = x;
            rank[x] += rank[y];
            rank[y] = 0;
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
};

void print(vector<int> &a)
{
    for (int i = 0; i < a.size(); i ++)
        cout << a[i] << " ";
    cout << "\n";
}

void connect_all(int n, vector<pair<int, int> > &connections) {
    union_find dsu(n);
    int m = connections.size();
    vector<pair<int, int> > disconnect, connect; 
    for (int i = 0; i < m; ++i){
        int u = connections[i].first;
        int v = connections[i].second;
        bool connection_made = dsu.unite(u, v);
// Already connected in some way so we can remove this wire
        if (not connection_made)
            disconnect.push_back(make_pair(u, v));
    }
    for (int i = 0; i < n; i++){
        if (not dsu.same(0, i)) // not connected
            connect.push_back(make_pair(0, i));
    }
    int num_of_disconnections = disconnect.size();
    int num_of_connections = connect.size();
    if (num_of_connections <= num_of_disconnections) {
        cout << num_of_connections << "\n";
        for (int i = 0; i < num_of_connections; i++) {
            cout << "Disconnect:\t" << disconnect[i].first << " and " << disconnect[i].second << "\n";
            cout << "Connect :\t" << connect[i].first << " and " << connect[i].second << '\n';
            cout << endl;
        }
    }
    else
    {
        cout << "-1\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > connections;

    while (m--) {
        int u, v;
        cin >> u >> v;
        connections.push_back(make_pair(u, v));
    }
    connect_all(n, connections);
    return 0;
}
