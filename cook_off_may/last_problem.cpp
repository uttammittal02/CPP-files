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

int32_t main(){
    test_cases_loop{
        int x1, y1, x2, y2;
        cin>>y1>>x1>>y2>>x2;
        int ans = 0;
        int init = x1 + y1 - 1;
        init = (init * (init - 1) / 2) + y1; 
        while (y1 < y2){
            ans += init;
            // cout<<init<<" "<<"loop1"<<endl;
            init += (y1 + x1);
            y1++;
        }
        while (x1 <= x2){
            // cout<<init<<" "<<"loop2"<<endl;
            ans += init;
            init += (x1 + y1 -1);
            x1++;
        }
        cout<<ans<<endl;
    }
    return 0;
}