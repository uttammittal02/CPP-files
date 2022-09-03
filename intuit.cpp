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

int main(){
    int n; cin >> n;
    map <pair<string, string>, int> m1;
    for (int i = 0; i < n; i ++){
        string a, b; cin >> a >> b;
        m1[make_pair(a, b)] ++;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i ++){
        string a, b; cin >> a >> b;
        if (m1[make_pair(a, b)] != 0)
            m1[make_pair(a, b)] --;
    }
    map <pair<string, string>, int> :: iterator itr;
    int ans = 0;
    for (itr = m1.begin(); itr != m1.end(); itr ++){
        ans += itr->second;
    }
    cout << ans << endl;
    return 0;
}
