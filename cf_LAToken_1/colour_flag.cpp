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
#define Or ||
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
        int n, m;
        cin>>n>>m;
        vector<string> matrix;
        loop(i, 0, n){
            string s;
            cin>>s;
            matrix.pb(s);
        }
        bool  white(0), red(0);
        pii coord;
        loop(i, 0, n){
            loop(j, 0, m){
                if (matrix[i][j] == 'R') {coord.first = i, coord.second = j, red = true; break;}
                else if (matrix[i][j] == 'W') {coord.first = i, coord.second = j, white = true; break;}
            }
            if (red Or white) break;
        }
        if (red) {if(!((coord.first%2) ^ (coord.second%2))) white = true, red = false;}
        else if (white) {if(!((coord.first%2) ^ (coord.second%2))) {white = false, red = true;}}
        bool var =true;
        loop(i, 0, n){
            loop(j, 0, m){
                char ans;
                // bool var = true;
                if (((i%2)^(j%2))) {if (white) ans = 'W'; else ans ='R';}
                else {if (white) ans = 'R'; else ans = 'W';}
                if (matrix[i][j] == '.') matrix[i][j] = ans; 
                else if (matrix[i][j] == 'R') {if (ans != 'R') {var = false; break;}}
                else {if (ans != 'W') {var = false; break;}}
            }
            if (!var) break;
        }
        if (!var) {cout<<"NO"<<endl; continue;}
        cout<<"YES"<<endl;
        loop(i, 0, n){
            loop(j, 0, m){
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
