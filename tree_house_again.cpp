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
#define And &&
#define Or ||
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;


class Graph
{
public:
    // map <int, bool> visited;
    map<int, vector<int> > adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    int DFS(int v,int sum);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

int Graph::DFS(int v, int sum)
{
    if(adj[v].size()==0) {return 1;}
    int curr_sum = sum;
    // Mark the current node as visited and
    // print it
    
    // cout << v << " ";
    vi list_of_sums(0);

    // Recur for all the vertices adjacent
    // to this vertex
    
    for (int i=0; i<adj[v].size(); ++i)
        {
            cout << "print node number " << v << endl;
                // cout<<"adj[v][i]"<<adj[v][i]<<" "<<v<< " "<< visited[i]<<endl;
            // if (!visited[i]){
                list_of_sums.pb(DFS(adj[v][i], curr_sum));
            // }
        }
    sort(list_of_sums.begin(), list_of_sums.end());
    // cout<<curr_sum<<endl;
    // cout<<list_of_sums.size()<<endl;
    for(int i=list_of_sums.size()-1; i>=0; i--)
    {   
        // cout <<i << " "<<list_of_sums[i] << " " << "current sum = " << curr_sum << endl;
        curr_sum+=(list_of_sums.size()-i)*(list_of_sums[i]);
    }
    // visited[v] = true;
    curr_sum++;
    return curr_sum;
}

// Driver code
int32_t main()
{
    // Create a graph given in the above diagram
    
    int mod = 1e9 + 7;
    test_cases_loop
    {
        Graph g;
        int n, x;
        cin >> n>> x ;
        loop(i, 0, n-1)
        {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        // loop(i, 1, n+1){
        //     loop(j, 0, g.adj[i].size()){
        //     // cout<<g.adj[i][j]<<" ";}cout<<"\n";
        // }
        cout << ((g.DFS(1, 0)%mod)*x)%mod << endl;
    }
    
    return 0;
}

