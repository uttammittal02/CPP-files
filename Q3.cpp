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
        string s;
        cin>>s;
        int n = s.size();
        // vi odd(), even(), ques();
        // unordered_set <int> ans_odd, ans_even, ans_ques;
        bool odd(false), even(false), ques(false);
        int ans(0), cnte(0), cnto(0), cntq(0);
        loop(i, 0, n){
            if (s[i] == '?') {odd= true; even = true; ques = true; cnte++; cnto++; cntq++;}
            else if (i%2 == 0) {
                if (s[i] == '1') even = true, odd = false, ques = false, cnte++;
                else odd = true, even = false, ques = false, cnto++;
            }
            else{
                if (s[i] == '0') even = true, odd = false, ques = false, cnte++;
                else odd = true, even = false, ques = false, cnto++;
            }
            if (!even) {
                // if (cnte == 1) ans+=1; 
                ans+= cnte*(cnte+1)/2, cnte = 0;}
            if (!odd) {
                // if (cnto == 1) ans+=1; 
                ans+= cnto*(cnto+1)/2, cnto = 0;}
            if (!ques){ 
                // if (cntq == 1) ans-=1; 
                // cout<<"ques"<<endl;
                ans -= (cntq*(cntq+1)/2), cntq = 0;}
            if (i==n-1) ans+= cnte*(cnte+1)/2 + cnto*(cnto+1)/2 - cntq*(cntq+1)/2;
            // cout<<ans<<space<<even<<space<<odd<<space<<ques<<endl;
            // if (i>0) odd[i] += odd[i-1], even[i] += even[i-1], ques[i] += ques[i-1];
            // ans_odd.insert(odd[i]);
            // ans_even.insert(even[i]);
            // ans_ques.insert(ques[i]);
         }
         cout<<ans<<endl;
         
    }
    return 0;
}
