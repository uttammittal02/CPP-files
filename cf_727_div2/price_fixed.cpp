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
    int n;
    cin>>n;
    vi arr(n), brr(n);
    vector <pii > pairs;
    int total = 0;
    loop(i, 0, n){
        pii pair;
        cin>>arr[i]>>brr[i];
        total += arr[i];
        pairs.pb(make_pair(brr[i], arr[i]));
    }
    sort(all(pairs));
    int sum = total;
    int left = 0;
    int ans;
    while (left <= total){
        int mid = (left + total) / 2;
        int current_items_purchased = sum - mid; int discounted_items_purchased = 0;
        // cout<<"while loop"<<endl;
        // int curr = 0;
        for (pii u : pairs){
            // cout<<"for loop"<<endl;
            if (u.first <= current_items_purchased){
                int items_now_purchased = min(mid - discounted_items_purchased, u.second);
                discounted_items_purchased += items_now_purchased;
                // curr += items_now_purchased;
                current_items_purchased += items_now_purchased;
                // cout<<"curr "<<current_items_purchased<<endl;
            }
        }
        if (current_items_purchased == sum){
            // cout<<"if statement"<<endl;
            ans = mid;
            left = mid+1;
        }
        else{
            total = mid - 1;
        }
    }
    cout<<(2*sum-ans)<<endl;
    return 0;
}