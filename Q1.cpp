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
#define infinity 8999999999999999999
#define debug(a) cout << "debug " <<a << endl;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;


int32_t main(){
    test_cases_loop{
        int s1, s2, s3, s4;
        cin>>s1>>s2>>s3>>s4;
        if (max(s1, s2) > max(s3, s4)) swap(s1, s3), swap(s2, s4);
        if ((max(s1, s2) > min(s3, s4))) {cout<<"YES"<<endl;}
        else cout<<"NO"<<endl;
    }
    return 0;
}
