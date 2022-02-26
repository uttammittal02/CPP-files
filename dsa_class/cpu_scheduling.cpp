#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n; cin >> n;
    vector <vector <int> > tasks;
    vector<int> time(n);
    vector<int> arrival(n);
    vector<int> cost(n);

    for (int i = 0; i < n; i ++)
        cin >> arrival[i];
    for (int i = 0; i < n; i ++)
        cin >> time[i];
    for (int i = 0; i < n; i ++)
        cin >> cost[i];
    vector <vector <int> > tasks(n);
    for (int i = 0; i < n; i ++){
        tasks[i].push_back(arrival[i]);
        tasks[i].push_back(time[i]);
        tasks[i].push_back(cost[i]);
        tasks[i].push_back(i + 1);
    }
    set <vector <int> > prior_queue;
    

    return 0;
}