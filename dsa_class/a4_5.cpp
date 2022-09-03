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

int graph[18][18][2];
long long dp[1 << 18][18][2];
long long minCost(int n, int m, int mask, int prev, int col)
{
    if (mask == ((1 << n) - 1))
    {
        return 0;
    }
    if (dp[mask][prev][col == 1] != 0)
    {
        return dp[mask][prev][col == 1];
    }
    long long ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (graph[prev][i][j] && !(mask & (1 << i)) && (j != col))
            {
                long long z = graph[prev][i][j] + minCost(n, m, mask | (1 << i), i, j);
                ans = min(z, ans);
            }
        }
    }
    return dp[mask][prev][col == 1] = ans;
}

int getCost(int n, int m)
{
    long long ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, minCost(n, m, 1 << i, i, 2));
    }
    if (ans != 1e9)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}
int main()
{
    // Input Given in Question
    int n = 3, m = 4;
    vector<pair<pair<int, int>, pair<int, char> > > vp = {{{1, 2}, {2, 'B'}},
                                                          {{1, 2}, {3, 'W'}},
                                                          {{2, 3}, {4, 'W'}},
                                                          {{2, 3}, {5, 'B'}}};
    for (int i = 0; i < m; i++)
    {
        int u = vp[i].first.first - 1;
        int v = vp[i].first.second - 1;
        int cost = vp[i].second.first;

        char color = vp[i].second.second;
        graph[u][v][color == 'W'] = cost;
        graph[v][u][color == 'W'] = cost;
    }
    cout << getCost(n, m) << '\n';
    return 0;
}