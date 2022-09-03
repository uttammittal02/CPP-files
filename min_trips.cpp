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

int getmin(vector<int> weights){
    map <int, int> freq;
    for (int i = 0; i < weights.size(); i ++){
        freq[weights[i]] ++;
    }
    int ans = 0;
    for (auto itr = freq.begin(); itr != freq.end(); itr++){
        if (itr -> second == 1){
            return -1;
        }
        ans += (itr->second) / 3 + (bool)((itr->second) % 3);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    map <int, int> freq;
    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        freq[x] ++;
    }
    int ans = 0;
    for (auto itr = freq.begin(); itr != freq.end(); itr++){
        if (itr -> second == 1){
            cout << "-1\n";
            return 0;
        }
        ans += (itr->second) / 3 + (bool)((itr->second) % 3);
    }
    cout << ans << endl;
    return 0;
}