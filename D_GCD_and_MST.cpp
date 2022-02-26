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
// #define makepair(p, a, b)                           p.ff = a, p.ss = b
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

template<typename T>
T _gcd(T a, T b){
	T temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%b ==0) return b;
	return _gcd(b, a%b);
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

struct DSU{
        // const int N = 1e5 + 5;
        int N;

        vi parent, Rank;

        DSU(int n){
                parent = vi(n + 1);
                Rank = vi(n + 1);
                N = n;
        }
        

        void makeSet(){
                for(int i = 1; i <= N; i++){
                        parent[i] = i;
                }
        }

        int findParent(int u){
                if(parent[u] == u){
                        return u;
                }
                return parent[u] = findParent(parent[u]);       // path compression
        }

        void Union(int u, int v){
                u = findParent(u);
                v = findParent(v);

                if(Rank[u] > Rank[v])
                        parent[v] = u;
                        
                else if(Rank[v] > Rank[u])
                        parent[u] = v;
                
                else{
                        parent[v] = u;
                        Rank[u]++;
                }
        }
};

int32_t main(){
    FIO
    test_cases_loop{
	    int n; cin >> n;
        int k; cin >> k;
		vi arr(n);
        set <pii > pq;
        pq.insert(make_pair(k, -1));
        loop(i, 0, n){
            cin >> arr[i];
            pq.insert(make_pair(arr[i], i));
        }
        int ans = 0;
        DSU dsu(n);
        dsu.makeSet();
        int cnt = 0;
        while (cnt < n-1){
            pii p = *pq.begin();
            pq.erase(p);
            int val = p.ff, idx = p.ss;
            if (idx == -1){
                loop(i, 0, n-1){
                    if (cnt == n - 1) 
                        break;
                    if (dsu.findParent(i + 1) != dsu.findParent(i+2)){
                        dsu.Union(i+1, i+2); cnt ++; ans += val;
                    }
                }
            }
            else{
                
                loop(j, idx+1, n){
                    if (cnt == n - 1) 
                        break;
                    if (val == _gcd(val, arr[j]) and dsu.findParent(idx + 1) != dsu.findParent(j+1)){
                        
                        dsu.Union(idx + 1, j + 1);
                        cnt ++;
                        ans += val;
                        
                    }
                    else
                        break;
                }
                rloop(j, idx - 1, 0){
                    if (cnt == n - 1) 
                        break;
                    if (val == _gcd(val, arr[j]) and dsu.findParent(idx + 1) != dsu.findParent(j+1)){
                        
                        dsu.Union(idx + 1, j + 1);
                        cnt ++;
                        ans += val;
                        
                    }
                    else
                        break;
                }
            }
            
        }
        cout << ans << endl;
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//


