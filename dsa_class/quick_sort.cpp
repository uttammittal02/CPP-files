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

vector <int> arr;

int partition(int l, int r, int pivot){
    int i = l - 1;
    int j = l;
    while(j < r){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i+1], arr[r]);
    return i + 1;
}

void quick_sort(int l, int r){
    int pivot = arr[r];
    int mid = partition(l, r, pivot);
    if(l < mid - 1)
        quick_sort(l, mid - 1);
    if(mid + 1 < r)
        quick_sort(mid + 1, r);
    

}

int32_t main()
{
	int n; cin >> n;
    arr = vector <int>(n);
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    quick_sort(0, n - 1);
    for(int i = 0; i < n; i ++){
        cout << arr[i] << ' ';
    }
	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
