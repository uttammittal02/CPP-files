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
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Function to find gcd of array of
// numbers
int findGCD(vi arr, int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

int32_t main(){
    test_cases_loop{
        int n;
        cin>>n;
        vi arr(n);
        // unordered_set<int> s;
        bool bor = true;
        cin>>arr[0];
        // int ans = arr[0];
        int ans_ = arr[0];
        bool var = false;
        if (arr[0] < 0) {bor = false;}
        if (arr[0] == 0) var =true;
        // s.insert(arr[0]);
        loop(i, 1, n){
            int temp;
            cin>>temp;
            if ((temp < 0)) {bor = false;}
            arr[i] = temp;
            // s.insert(temp);
            if (temp == 0) var = true;
            ans_ = max(arr[i], ans_);
        }
        int ans = findGCD(arr, n);
        if (!bor) {cout<<"NO"<<endl; continue;}
        vi brr;
        if (var){int i = 0;
        while (i <= ans_){
            brr.pb(i);
            i+=ans;
        }}
        else {int i = ans;
        while ( i <= ans_){
            brr.pb(i);
            i+=ans;}
            }
        
        // cout<<"ans= "<<ans<<endl;
        // loop(i, 0, arr.size() - 1){
        //     loop(j, i+1, arr.size()){
        //         int t = abs(arr[i] - arr[j]);
        //         if (s.find(t) == s.end()){
        //             s.insert(t);
        //             arr.pb(t);
        //         }
        //         if (arr.size()>300) {bor = false; break;}
        //     }
        //     if (!bor) {break;}
        // }
        if (brr.size()>300) {cout<<"NO"<<endl; continue;}
        cout<<"YES\n"<<brr.size()<<endl;
        // sort(arr.begin(), brr.end());
        loop(i, 0, brr.size()){cout<<brr[i]<<space;}
        cout<<endl;
    }
    return 0;
}