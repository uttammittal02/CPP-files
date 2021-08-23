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
#define And &&
#define Or ||
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;

vi factors(int n){
    int k = pow(n, 0.5);
    k++;
    set<int> ans;
    loop(i, 1, k){
        if (n%i == 0) {
            ans.insert(i);
            ans.insert(2*i);
            // ans.insert(n/i);
            // ans.insert(2*n/i);
        }
    }
    vi v(ans.begin(), ans.end());
    return v;
}

int32_t main(){
    int t;
    cin>>t;
    loop(j, 1, t+1){
        int g;
        cin>>g;
        int cnt = 0;
        vi factor = factors(g);
        loop(i, 0, factor.size()){
            if ((2*g)% (factor[i]) != 0) continue;
            if ((2*g/(factor[i]) - (factor[i]) + 1) % 2 == 0 And (2*g/(factor[i]) - (factor[i]) + 1) / 2 >= 1) {
                cnt++;
                // cout<<(2*g/(factor[i]) - (factor[i]) + 1) / 2<<" "<<factor[i]<<endl;
            }
        }
        cout<<"Case #"<<j<<": "<<cnt<<endl;
    }
    return 0;
}
