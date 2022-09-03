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

const int inf = 1e9;
class union_find
{
    vector<int> par, rank;

public:
    union_find(int n)
    {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
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
int distance(pair<int, int> &a, pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int kruskal(vector<pair<int, int> > &houses)
{
    int n = houses.size();
    union_find dsu(n);
    int MST_cost = 0;
    for (int i = 0; i < n; i++)
    {
        int u = i, v = -1, min_cost = inf;
        for (int j = 0; j < n; j++)
        {
            if (dsu.same(i, j))
                continue;
            int cost_to_connect = distance(houses[i], houses[j]);
            if (cost_to_connect < min_cost)
                v = j, min_cost = cost_to_connect;
        }

        if (v != -1)
        {
            dsu.unite(u, v);
            MST_cost += min_cost;
        }
    }
    return MST_cost;
}
int main()
{
    int m;
    cin >> m;
    vector<pair<int, int> > houses(m);
    for (int i = 0; i < m; ++i)
        cin >> houses[i].first >> houses[i].second;
    int MST_cost = kruskal(houses);
    cout << MST_cost << "\n";
    return 0;
}