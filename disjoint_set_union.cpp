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

#define YES                                         cout<<"YES"<<endl;
#define Yes                                         cout<<"Yes"<<endl;
#define NO                                          cout<<"NO"<<endl;
#define No                                          cout<<"No"<<endl;
#define infinity                                    999999999999999999
#define float                                       long double
#define sz(v)                                       ((int)(v).size())
#define all(v)                                      (v).begin(),(v).end()
#define MOD                                         (int)1000000007
#define endl                                        '\n'
#define space                                       " "
#define int                                         long long
#define pii                                         pair<int, int>
#define vi                                          vector<int>
#define pb(n)                                       push_back(n)
#define mii                                         map<int, int>
#define umii                                        unordered map<int, int>
#define test_cases_loop                             int t; cin >> t; while(t--)
#define FIO                                         ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final)                   for(int var=initial; var < final; var++)
#define rloop(var, init, end)                       for (int var = init; var >= end; var--)
#define ff                                          first
#define ss                                          second
#define makepair(p, a, b)                           p.ff = a, p.ss = b
using namespace std;

vi parent(100000); // stores immediate parent initially and root node after time
vi rank_(100000); // basically stores the depth of the tree from that node to its subtree
int n;
//Disjoint set union is a data structure to basically answer the queries of whether 2 numbers belong to same or different components in O(1).
void makeSet(){
    loop(i, 1, n+1){
        parent[i] = i;
    }
}

int find_par(int node){
    /*
    This function has time complexity of O(4a) where a = 4 for n = 10**(600) i.e. a constant time complexity. 
    */
    if (parent[node] == node) return node;

    return parent[node] = find_par(parent[node]); 
}

void union_(int u, int v){
     /*
    This function has time complexity of O(4a) where a = 4 for n = 10**(600) i.e. a constant time complexity. 
    */
    u = find_par(u);
    v = find_par(v);
    if (u == v) return;
    if (rank_[u] > rank_[v]){
        parent[v] = u;
    }
    else if (rank_[v] > rank_[u]) parent[u] = v;
    else {
        parent[v] = u;
        rank_[u]++;
    }
}

int32_t main(){
    FIO
    test_cases_loop{
        cin>>n;
        int r; cin>>r;//no of union operations
        // parent.resize(n);
        // rank_.resize(n, 0);
        makeSet();
        loop(i, 0, r){
            int u, v;
            cin>>u>>v;
            union_(u, v);
        }
        //To check the prescence of the two numbers in same or different components.
        int q; cin>>q; // no of queries
        loop(i, 0, q){
            int u, v;
            cin>>u>>v;
            if (find_par(u) != find_par(v)) cout<<"2\n";
            else cout<<"1\n";
        }
    }
    return 0;
}


