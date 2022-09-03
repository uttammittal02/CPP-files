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

#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define MOD (int)1000000007
#define endl '\n'
#define sp ' '
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered map<int, int>
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	while (t--)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);
#define find_ele(ele, set) set.find(ele) != set.end()
#define loop(var, initial, final) for (int var = initial; var < final; var++)
#define rloop(var, init, end) for (int var = init; var >= end; var--)
#define ff first
#define ss second
#define iter(itr, start, end) for (itr = start; itr != end; itr++)
#define yesno(var) cout << (var ? "YES" : "NO") << endl;
#define vpii vector<pii>
typedef long long ll;

using namespace std;


int32_t main()
{
	int physical_address_space, logical_address_space, page_size;
    cout << "Enter the physical address space, logical address space and page size: ";
    cin >> physical_address_space >> logical_address_space >> page_size;
    int page_number = logical_address_space / page_size;
    int frame_number = physical_address_space / page_size;
    int arr[page_number];
    loop(i, 0, page_number)
    {
        arr[i] = 0;
    }
    cout << "Now enter the page number and the frame number: \n";
    while (true){
        int page_number_to_be_accessed, frame_number_to_be_accessed;
        cin >> page_number_to_be_accessed >> frame_number_to_be_accessed;
        if (page_number_to_be_accessed == -1 && frame_number_to_be_accessed == -1)
            break;
        if (page_number_to_be_accessed > page_number || frame_number_to_be_accessed > frame_number)
            cout << "ERROR" << endl;
        else{
            if (arr[page_number_to_be_accessed] == 0){
                arr[page_number_to_be_accessed] = frame_number_to_be_accessed;
                cout << "Page fault" << endl;
            }
            else if (arr[page_number_to_be_accessed] == frame_number_to_be_accessed){
                cout << "Frame accessed from cache" << endl;
            }
            else{
                cout << "Page already allocated" << endl;
            }
        }
        cout << "Page Table : \n";
        cout << "Frame\tPage\n";
        loop(i, 0, page_number)
        {
            if (arr[i])
            cout << arr[i] << "\t" << i << endl;
        }
        cout << endl;
    }


	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
// 1 3 9
// 2 6 10
// 5 7 11