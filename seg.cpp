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
using namespace std;

typedef long long ll;
typedef long double ld;

#define p(a,b) pair<a,b>
#define pll pair<ll,ll>
#define v(a) vector<a>
#define vll vector<ll>
#define s(a) set<a>
#define ms(a) multiset<a>
#define m(a,b) map<a,b>
#define mm(a,b) multimap<a,b>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define tests(t) ll t; cin >> t; while(t--)
#define loop(i, a, b, inc) for (ll i = a; i <= b; i+=inc)
#define loopinv(i, a, b, dec) for (ll i = a; i >= b; i-=dec)
#define iteratorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define iteratorloopinv(v, i) for(auto i = v.rbegin();i!=v.rend();i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define val(x) (*(x))
#define space cout<<" ";
#define newline cout<< "\n";

#define cinv(v,n) v.resize(n,0);loop(i,0,n-1,1){cin>>v[i];}
#define cin2d(v,n,m,dataType) v.resize(n,vector<dataType> (m,0));loop(i,0,n-1,1){loop(j,0,m-1,1){cin>>v[i][j];}}
#define pyes(CONDITION) cout << (CONDITION ? "YES" : "NO") << "\n";

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "("; _print(p.first); cerr << ","; _print(p.second); cerr << ")";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <vector <T>> v){cerr << " => \n[\n"; for (vector<T> i : v) {cerr<<"  ";_print(i); cerr << endl;} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(multiset <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.first); cerr << "--> "; _print(i.second);cerr<< "),";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<< "(";_print(i.first); cerr << "--> "; _print(i.second);cerr<< "),";} cerr << "]";}

struct SegmentTree
{
    int leafNodes;
    int stSize;
    int leafStartingInd;
    int levels;
    vector<pair<map<int,int>, pair<int,int>>> tree;
    void buildTree()
    {
        int x = levels - 1;
        while (x > 0)
        {
            int n = pow(2, x - 1);
            int sti = n;
            for (int i = 0; i < n; i++)
            {
                int ind = sti + i;
                for(auto v: tree[ind*2].first)
                    tree[ind].first[v.first]+=v.second;
                for(auto v: tree[ind*2 + 1].first)
                    tree[ind].first[v.first]+=v.second;
                tree[ind].second = {tree[ind*2].second.first, tree[ind*2+1].second.second};
            }
            x--;
        }
    }
    void update(int ind, int x)
    {
        int i = leafStartingInd + ind;
        int value = tree[i].first.begin()->first;
        int newValue = x;
        while (i != 0)
        {
            tree[i].first[value]--;
            if(tree[i].first[value] == 0)
                tree[i].first.erase(value);
            tree[i].first[newValue]++;
            i = i / 2;
        }
    }
    int getRangeCount(int level, int l, int r)
    {
        if(r < l)
            return 0;

        pair<int,int> range = tree[level].second;
        if(range.first == l && range.second == r){
            int count = 0;
            for(auto v:tree[level].first){
                if(v.second%2 == 1)
                    count++;
            }
            return count;
        }
        return getRangeCount(level*2, l, tree[level*2].second.second) + getRangeCount(level*2 + 1, tree[level*2 + 1].second.first, r);
    }
    SegmentTree(vector<ll> &A)
    {
        int x = A.size();
        if (x == 1)
            levels = 1;
        else
            levels = log2(x - 1) + 2;

        leafNodes = pow(2, levels - 1);
        stSize = 2 * leafNodes;
        leafStartingInd = leafNodes;

        map<int,int> mp;
        tree.resize(stSize, {mp,{-1,-1}});
        for (int i = 0; i < x; i++){
            tree[leafStartingInd + i].first[A[i]]++;
            tree[leafStartingInd + i].second = {i,i};
        }

        buildTree();
    }
};


struct solution{
    ll n,q;
    v(ll) arr;
    solution(){
        cin>>n;
        cinv(arr,n);
        SegmentTree st(arr);
        cin>>q;
        for(int i = 0;i<q;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a == 1)
                st.update(b-1, c);
            else
                cout<<st.getRangeCount(1, b-1, c-1)<<endl;
        }
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Debug.txt", "w", stderr);
    #endif
    FASTIO;
    tests(t){
        solution sol;
    }
    return 0;
}
// myprettyprint.hpp