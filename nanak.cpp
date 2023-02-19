#include <stack>
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
#include <climits>
#include <functional>
using namespace std;
 
#define ff              first
#define ss              second
#define sz(v)           ((int)(v).size())
#define all(v)          (v).begin(),(v).end()
#define endl            '\n'
#define pii             pair<int, int>
#define vi              vector<int>
#define w(t)            int t; cin >> t; while(t--)
#define int             long long
#define FIO             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
 
 
 
 
int32_t main(){
    FIO
    int n, q; cin >> n >> q;
    int sum=0;
    vector<pii> arr(n, make_pair(0, -1));
    for(int i=0; i<n; i++){
        cin >> arr[i].ff;
        sum += arr[i].ff;
    }
    
    pii globalUpdate = make_pair(-2, 0);
    for(int i=0; i<q; i++){
        int qi; cin >> qi;
        if(qi==1){
            int idx, x; cin >> idx >> x;
            idx--;
            if(globalUpdate.ff > arr[idx].ff) 
            sum -= arr[idx].ff;
            arr[idx].ff = x;
            arr[idx].ss = i;
            sum += arr[idx].ff;
            cout << sum << endl;
        }
 
        else{
            int x; cin >> x;
            globalUpdate.ff = i;
            globalUpdate.ss = x;
            sum = n*x;
            cout << sum << endl;
        }
    }
    return 0;
}
 