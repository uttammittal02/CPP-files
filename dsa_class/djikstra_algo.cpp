#include <iostream>
#include <vector>
using namespace std;

int v;
const int N = 5000000;
int *d = new int[N];
vector <int> vis(N, 0);

vector<vector<pair <int, int> > > g;
int *par = new int[N];

int FindMin()
{
        int mini = INT32_MAX;
        int idx = -1;
        for(int i = 0; i < v; i++){
                if((!vis[i]) and d[i] < mini)
                        mini = d[i], idx = i;
        }
        return idx;
}

void Relax(pair<int, int> p, int node)
{
        par[p.first] = (d[p.first] > d[node] + p.second) ? node : par[p.first];
        d[p.first] = min(d[p.first], d[node] + p.second);
}

void Dijkstra(int s)
{
        for(int i = 0; i < v; i++){
                d[i] = INT32_MAX;
                vis[i] = 0;
                par[i] = -1;
        }

        d[s] = 0;

        while(true){
                int node = FindMin();

                if(node == -1)
                        break;
                
                vis[node] = 1;

                for(int p = 0; p < g[node].size(); p ++)
                        Relax(g[node][p], node);
                
        }
}

int main()
{
        cout << "Enter the numebr of edges and vertices of the graph respectively : ";
        int e; cin >> e >> v;
        for (int i = 0; i < v; i++) 
        {
                vector<pair<int, int> > a;
                g.push_back(a);
        }
        cout << "Enter the edges of the graph :-\n";
        for (int i = 0; i < e; i ++)
        {
                int u, t, w; cin >> u >> t >> w;
                pair <int, int> pair_1, pair_2; 
                
                g[u].push_back(make_pair(t, w));
                g[t].push_back(make_pair(u, w));
        }
        d[0] = 0;
        // vis[0] = 1;
        Dijkstra(0);
        
        cout << "Enter the nodes between which you want to find the shortest path: ";
        int s, end; cin >> s >> end;
        vector <int> path;
        par[s] = -1;
        while (par[end] != -1){
                path.push_back(end);
                end = par[end];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i ++)
                cout << path[i] << ' ';
        
        return 0;
}
