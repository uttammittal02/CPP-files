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
#define makepair(p, a, b)                           p.ff = a, p.ss = b
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// #define pbds(T) tree<T, null_type,less<T >, rb_tree_tag,tree_order_statistics_node_update>


vector<int> divisors(int n)
{
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
void precision_print(float n, int p)
{
    cout<<fixed<<setprecision(p)<<n<<endl;
    return;
}

int gcd(int a, int b)
{
    if (a < b) return gcd(b,a);
    if (b == 0) return a;
    return gcd(b, a%b);
}


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int winner(char a, char b)
{
    if (a==b) return 0;
    // if (b == 'R') return winner(b, a);
    if (a == 'R'){
        if (b == 'S') return 1;
        return 2;
    }
    if (a == 'S'){
        if (b == 'P') return 1;
        return 2;
    }
    if (b == 'R') return 1;
    return 2;
}

int32_t main()
{
    FIO
    // test_cases_loop{
	    int n; cin>>n;
        string a, b; cin >> a >> b;
        int m = sz(a), k = sz(b);
        int ans_1 = 0, ans_2 = 0, temp_1(0), temp_2(0);
        int lcm = m * k / gcd(m, k);
        loop(i, 0, lcm){
            char player_1 = a[i%m];
            char player_2 = b[i%k];
            if (winner(player_1, player_2) == 1)    ans_2 ++;
            else if (winner(player_1, player_2) == 2)   ans_1 ++;
            if ((i + 1) == (n%lcm)){
                temp_2 = ans_2;
                temp_1 = ans_1;
            }
            // cout << player_1 << space << player_2 << endl;
            
        }
        // cout << ans_1 << space << ans_2 << endl;
        ans_2 *= (n/lcm);
        ans_2 += temp_2;
        ans_1 *= (n/lcm);
        ans_1 += temp_1;
        cout << ans_1 << space << ans_2 << endl;
    // }
    return 0;
}

// RSRSRSR |||
// SPRSPRS ||
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//


