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

#define YES                                         cout<<"YES"<<endl;
#define Yes                                         cout<<"Yes"<<endl;
#define NO                                          cout<<"NO"<<endl;
#define No                                          cout<<"No"<<endl;
#define infinity                                    999999999999999999
#define float                                       long double
#define sz(v)                                       ((int)(v).size())
#define all(v)                                      (v).begin(),(v).end()
#define MOD                                         (int)1000000007
#define endl                                        '\n'
#define space                                       " "
#define int                                         long long
#define pii                                         pair<int, int>
#define vi                                          vector<int>
#define pb(n)                                       push_back(n)
#define mii                                         map<int, int>
#define umii                                        unordered map<int, int>
#define test_cases_loop                             int t; cin >> t; while(t--)
#define FIO                                         ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final)                   for(int var=initial; var < final; var++)
#define rloop(var, init, end)                       for (int var = init; var >= end; var--)
#define ff                                          first
#define ss                                          second

// void err(istream_iterator<string> it){};
// template <typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args)
// {
//     cout << a << " ";
//     err(++it, args...);
// };
// #define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";}; 
// #define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// #define pbds(T) tree<T, null_type,less<T >, rb_tree_tag,tree_order_statistics_node_update>


vector<int> divisors(int n){
	vector<int> ans;
	for(int i = 2;i<=sqrt(n);i++){
		if(n % i ==0){
			ans.pb(i);
			if(n/i != i) ans.pb(n/i);
		}
	}
	ans.pb(1);
	return ans;
}
void precision_print(float n, int p){
    cout<<fixed<<setprecision(p)<<n<<endl;
    return;
}

int ceil_(int n, int k){
	return (n - ((k-1)*n) / k);
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int32_t main(){
    FIO
    test_cases_loop{
	    int n; cin >> n;
        int m; cin >> m;
		
		vector <string> arr(n);
		loop(i, 0, n){
			cin >> arr[i];
		}
        bool var = true;
        vi ans(n);
        loop(i, 0, n){
            vector <pii > temp;
            loop(j, 0, n){
                if (i == j) continue;
                int x(-1), y(-1);
                loop(k, 0, m){
                    if (arr[i][k] != arr[j][k]){
                        if (x != -1){
                            if (y != -1){
            // cout << "false\n";
                                var = false; break;
                            }
                            y = k;
                        }
                        else
                            x = k;
                        
                    // cout << arr[i] << space << arr[j] << space << x << space << y << endl;
                    }
                }
                if (!var) break;
                temp.pb(make_pair(x, y));
            }
            if (!var) break;
            int x(0), y(0);
            loop(j, 0, n-1){
                // cout << arr[i] << space << temp.back().ff << space << temp.back().ss << endl;
                if (min(temp[j].ff, temp[j].ss) != -1){
                    x = temp[j].ff, y = temp[j].ss;
                    break;
                }
            }
            loop(j, 0, n-1){
                if (min(temp[j].ff, temp[j].ss) != -1){
                    if (temp[j].ff != x and temp[j].ss != x) x = -1;
                    if (temp[j].ff != y and temp[j].ss != y) y = -1;
                }
            }
            if (max(x, y) == -1){
                var = false; break;
                
            }
            ans[i] = max(x, y);
            if (min(x, y) != -1) ans[i] = m*(x+1) + y;
        }
        if (!var){
            cout << "-1\n"; continue;
        }
        vi vis(m);
        string s = arr[0];
        loop(i, 0, n){
            cout << ans[i] << endl;
            if (ans[i] >= m){
                int x = (ans[i] / m) - 1, y = ans[i] % m;
                if (vis[x] and vis[y]){
                    var = false; break;
                }
                if (vis[x]) ans[i] = y;
                else ans[i] = x;
            }
            cout << s << space << ans[i] << endl;
            vis[ans[i]] ++;
            loop(j, 0, m){
                if (j == ans[i]) continue;
                s[j] = arr[i][j];
            }
            
        }
        if (!var){
            cout << "-1\n"; continue;
        }
        cout << s << endl;

    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//


