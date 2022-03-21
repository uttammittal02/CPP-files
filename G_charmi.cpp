// ਹਰਅਸੀਸ ਸਿੰਘ
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
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(T)                            int T; cin >> T; while(T--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

int32_t main(){
    FIO
    w(T){
        int n, m;
        cin >> n >> m;
        int s, t; cin >> s >> t;

        vector<vector<int> > g(n + 1);

        l(i, 1, m + 1){
            int u, v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        vector<vector<int> > dp(n + 1, vi(2));

        vector<int> path(n + 1, -1);

        // number of ways of reaching a node from s 

        // dp[i][0] number of ways of reaching i from s with shortest path
        // dp[i][1] number of ways of reaching i from s with shortest path plus 1
        dp[s][0] = 1;

        queue<pii > q;

        path[s] = 0;

        q.push(make_pair(s, 0));

        // int cnt = 1, height = infinity, lvl = 0;

        while(!q.empty()){

            // assert(lvl < height + 1);
            // if (lvl > height + 1){
            //     break;
            // }

            int u = q.front().ff;
            int snakelen = q.front().ss;
            q.pop();
            // cnt --;

            // if (!cnt){
            //     cnt = q.size();
            //     // lvl ++;
            // }

            for(int i = 0; i < g[u].size(); i++){
                int v = g[u][i];

                // if (v == par)
                //     continue;
                
                if(path[v] == -1){
                    path[v] = snakelen + 1;

                    assert(path[u] != -1 and snakelen == path[u]);

                    dp[v][0] += dp[u][0];
                    // dp[v][1] += dp[u][1];
                }
                else{
                    int d = snakelen + 1;

                    if(d == path[v]){
                        dp[v][0] += dp[u][0];
                        // dp[v][1] += dp[u][1];

                    }

                    else if(d == path[v] + 1){
                        
                        // if(snakelen == path[u])
                        //     dp[v][1] ++;

                        // else 
                        //     dp[v][1] ++;

                    }
                    else continue;

                    dp[v][0] %= MOD; dp[v][1] %= MOD;

                }
                
                q.push(make_pair(v, snakelen + 1));
            }
        }
        // cout << dp[t][0] << endl;
        // cout << dp[t][1] << endl;
        // t = 5;
        cout << (dp[t][0] + dp[t][1]) % MOD << endl;
    }
}

/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/