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

int min_cost(int n, int m, int d, vector<int> &cost, vector<int> &coord){
    vector <vector<pair<int, int> > > dp(n, vector<pair<int, int> >(m));
    // dp[i][j].first represents the minimum cost to reach the (i + 1)th board leaving j boards
    // dp[i][j].second represents cost per km incurred in moving from ith board to (i + 1)th board


    dp[0][0] = make_pair(cost[0] * (coord[1] - coord[0]), cost[0]);
    dp[1][1] = make_pair(cost[0] * (coord[2] - coord[0]), cost[0]);
    for (int i = 1; i < n; i ++){
        dp[i][0].first = dp[i - 1][0].first + cost[i] * (coord[i + 1] - coord[i]);
        dp[i][0].second = cost[i];
    }
    for(int i = 2; i < n; i ++){
        for (int j = 1; j <= m; j ++){
            dp[i][j] = (dp[i - 1][j - 1].first + (coord[i + 1] - coord[i]) * dp[i - 1][j - 1].second < dp[i - 1][j].first + cost[i] * (coord[i + 1] - coord[i])) ? make_pair(dp[i - 1][j - 1].first + (coord[i + 1] - coord[i]) * dp[i - 1][j - 1].second, dp[i - 1][j - 1].second) : make_pair(dp[i - 1][j].first + cost[i] * (coord[i + 1] - coord[i]), cost[i]);
            
        }
    }
    return dp[n - 1][m].first;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        int n, m, d;
        cin >> n >> d >> m;
        vector<int> costs(n), coord(n);
        for (int i = 0; i < n; i ++){
            cin >> coord[i];
        }
        for (int i = 0; i < n; i ++){
            cin >> costs[i];
        }
        if (n == 1){
            cout << costs[0] * d << endl;
            continue;
        }
        coord.push_back(d);
        cout << min_cost(n, m, d, costs, coord) << endl;
    }
    return 0;
}