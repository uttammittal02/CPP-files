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

using namespace std;

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
    
	int n, l, k; cin >> n >> l >> k;
    
	vi d(n + 1), s(n);
	loop(i, 0, n){
		cin >> d[i];
	}
    d[n] = l;
    set <pii > remove;
    vi prev(n);
    int time = 0;
    int cnt = 0;
    loop(i, 0, n){
        cin >> s[i];
        if (i) 
            prev[i] = min(prev[i-1], s[i]);
        else
            prev[i] = s[i];
        if (i and i < n){
            if (s[i] >= prev[i - 1]){
                cnt ++;
                remove.insert(make_pair(-cnt, ((s[i] - prev[i-1]) * (d[i+1] - d[i])))); 
            }// cout << i << space << (s[i] - s[i-1]) * (d[i+1] - d[i]) << endl;
            else cnt = 0;
        }
        if (i < n) time += (s[i] * (d[i+1] - d[i]));
    }
    set <pii > :: reverse_iterator itr;
    cnt = 0;
    cout << time << endl;
    for (itr = remove.rbegin(); itr != remove.rend(); itr ++){
        int x = (*itr).ss, y =(*itr).ff;
        if (x <= 0 or cnt >= k) break;
        cout << x << space << y << endl;
        time -= x;
        cnt ++;
    }
    cout << time << endl;
    
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//


