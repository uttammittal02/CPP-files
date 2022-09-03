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
    vector <char> blocks;
    for (int i = 0; i < n; i ++){
        char a; cin >> a;
        blocks.push_back(a);
    }
    char c; cin >> c;
    vector <int> pos;
    for(int i = 0; i < n; i ++){
        if (blocks[i] == c){
            pos.push_back(i);
        }
    }
    int ans = 0;
    int ptr = pos[0] + 1;
    for (int i = 1; i < pos.size(); i ++){
        ans += pos[i] - ptr;
        ptr ++;
    }
    int temp = ans;
    for (int i = 1; i < pos.size(); i ++){
        // cout << ans << endl;
        temp += (pos[i] - pos[i - 1] - 1) * (i);
        temp -= (pos[i] - pos[i - 1] - 1) * (pos.size() - i);
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}