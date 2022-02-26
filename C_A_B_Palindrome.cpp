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
#define sp	                                       	' '
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
#define iter(itr, start, end)						for (itr = start; itr != end; itr ++)
#define yesno(var)									cout << (var? "YES" : "NO") << endl;
#define vpii										vector <pii >

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
	    int a, b; cin >> a >> b;
		string s; cin >> s;
        int n = a + b;
        int x = count(all(s), '0'), y = count(all(s), '1');
        a -= x, b -= y;
        bool var = true;
		loop(i, 0, n/2){
            // cout << s << endl;
            // cout << a << sp << b << endl;
            if (s[i] != '?' and s[n - i - 1] != '?'){
                if (s[i] != s[n - i - 1]){
                    // cout << "error\n";
                    var = false; break;
                }
            }
            else if (s[i] == '?' and s[n - i - 1] =='?'){
                if (a >= b and a > 1) {
                    s[i] = s[n - i - 1] = '0';
                    a -= 2;
                }
                else if (b > 1){
                    s[i] = s[n - i - 1] = '1';
                    b -= 2;
                }
                else{
                    // cout << "vanish\n";
                    var = false; break;
                }
            }
            else {
                if (s[i] == '?'){
                    s[i] = s[n - i - 1];
                    a -= (s[n - i - 1] == '0'? 1: 0);
                    b -= (s[n - i - 1] == '0'? 0: 1);
                    if (a < 0 or b < 0){
                        // cout << "<1\n";
                        var = false; break;
                    }
                }
                else {
                    s[n - i - 1] = s[i];
                    a -= (s[i] == '0'? 1: 0);
                    b -= (s[i] == '0'? 0: 1);
                    if (a < 0 or b < 0){
            //             cout << s << endl;
            // cout << a << sp << b << endl;
                        // cout << "<0\n";
                        var = false; break;
                    }
                }
            }
        }
        if (n % 2){
            // cout << a << sp << b << endl;
            if (s[n / 2] == '?'){
                if ((a == 1 and b == 1) or (a != 1 and b != 1)) var = false;
                else {
                    s[n/2] = (a ? '0' : '1');
                    a -= (s[n/2] == '0'? 1 : 0);
                    b -= (s[n/2] == '0'? 0 : 1);
                }
            }
        }
        if (a != 0 or b != 0) var = false;
        cout << (var? s : "-1") << endl;
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//


