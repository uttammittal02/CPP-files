#include <iostream>
#include <cmath>
#include <vector>
#define loop(j,n) for(int i = j; i < n; i++)
using namespace std;

vector <int> dp;

int mini_coins(int n, int v, vector<int> &coins, vector<int> &dp){
    loop(0, n){
        if (coins[i] > v) return dp[v];
        if (dp[v - coins[i]] == INT32_MAX) dp[v-coins[i]] = mini_coins(n, v-coins[i], coins, dp);
        dp[v] = min(dp[v], 1 + dp[v-coins[i]]);
    }
    return dp[v];
}

int main(){
	int n;
    float v;
    cin>>n>>v;
    v *= 100;
    v = int(v);
    vector <int> coins;
    loop(0, n){
        float temp;
        cin>>temp;
        coins.push_back(int(temp * 100));
    }
    loop(0, v+1){
        dp.push_back(INT32_MAX);
    }
    dp[0] = 0;
    int ans = mini_coins(n, v, coins, dp);
    cout<<int(ans)<<endl;
	return 0;
}
