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

int fun(char a, int incr){
    int t = a - 'a';
    t += incr;
    t %= 26;
    return t;
}

int main(){
    string s; cin >> s;
    vector <int> a(26);
    for (int i = 0; i < 26; i ++){
        cin >> a[i];
    }
    vector <int> suff (s.size());
    int mx = s[0] - 'a';
    suff[0] = a[mx];
    for (int i = 1; i < (s.size()); i ++){
        mx = max(mx, s[i] - 'a');
        suff[i] = a[mx];
    }
    
    s.back() = 'a' + fun(s.back(), suff.back());
        // cout << suff.back() << endl;
    for (int i = (s.size()) - 2; i >= 0; i --){
        suff[i] += suff[i + 1];
        s[i] = 'a' + fun(s[i], suff[i]);
    }
    vi freq(26);
    for (int i = 0; i < s.size(); i ++){
        freq[s[i] - 'a'] ++;
    }
    // freq array is the frequency of each letter in the string
    return 0;
}
