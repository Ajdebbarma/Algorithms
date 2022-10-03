#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lis(1001); // adjacency list
bool vis[1001];  // visited array


// adding edges 
void addEdge(int x, int y)
{

    lis[x].push_back(y);
    lis[y].push_back(x);
}


// dfs function

void dfs(int n)
{
    vis[n] = true;

    cout << n << " ";

    for(auto i : lis[n]) {

        if(!vis[i]){

            dfs(i);

        }
    }
}


int main()
{

    int n = 5;

    int e = 9;

    while (e--)
    {

        int x = rand() % n;
        int y = rand() % n;

        if(x == y || count(lis[x].begin(), lis[x].end() , y) || count(lis[y].begin(), lis[y].end() , x)) continue;

        addEdge(x, y);
    }

    cout << "Adjacency List: " << "\n";

    for(int i =0 ;i < n ; i++) {
        cout << i << ": ";
        for(int j = 0; j < lis[i].size() ; j++) {
            cout << lis[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Vertex Visited Order: ";
    dfs(0);
}


// Adjacency List: 
// 0: 4 2
// 1: 2
// 2: 1 4 0
// 3:
// 4: 0 2
// Vertex Visited Order: 0 4 2 1
