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
#include <tuple>
#include <functional>

using namespace std;

void solve(){
    string a, b; cin >> a >> b; 

    vector<vector<int> > f(26);

    for(int i = 0; i < a.size(); i++){
        f[a[i] - 'a'].push_back(i);
    }
    long long ans = 0; 
    int lst = -1;

    for(int i = 0; i < b.size(); i++){
        char p = b[i];
        if(f[p - 'a'].size() == 0){
            cout << -1 << endl; return;
        }
        int id = upper_bound(f[p - 'a'].begin(), f[p - 'a'].end(), lst) - f[p - 'a'].begin();

        if(id == f[p - 'a'].size()){
            ans += a.size();

            lst = f[p - 'a'][0];
        }
        else{
            lst = f[p - 'a'][id];
        }
    }
    cout << ans + lst + 1 << endl;
}

int main(){
    solve();
    return 0;
}
