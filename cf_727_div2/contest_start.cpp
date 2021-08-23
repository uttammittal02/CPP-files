#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
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
#include <functional>

#define And &&
#define oOr ||
#define endl '\n'
#define sp " "
#define int long long
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD 1000000007;
#define pii pair<int, int>
#define usi unordered_set<int>
#define osi set<int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

int32_t main(){
    test{
        int n, x, t;
        cin>>n>>x>>t;
        int a = t/x;
        int ans = a*(n-a);
        ans = ans > 0? ans : 0;
        a = min(a, n);
        ans += ((a-1)*a)/2; 
        // if (a < n - 1 And t%x == 0) ans += a;
        cout<<ans<<endl;
    }
    return 0;
}