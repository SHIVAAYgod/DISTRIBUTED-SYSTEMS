#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int dest, vector<vector<int>>& adj, vector<int> vis, vector<int>& ans)
{
    if(src == dest) return true;
    if(vis[src] == 1) return false;
    vis[src] = 1;
    for(auto i: adj[src])
    {
        ans.push_back(i);
        if(dfs(i, dest, adj, vis, ans)) return true;
        ans.pop_back();
    }
    return false;
}

int main()
{
    int n = 17;
    vector<vector<int>> adj(n);
    adj[0] = {1, 8, 12};
    adj[1] = {0, 2, 3, 4};
    adj[2] = {1, 5, 6};
    adj[3] = {1, 7};
    adj[4] = {1};
    adj[5] = {2};
    adj[6] = {2};
    adj[7] = {3};
    adj[8] = {0, 11, 9};
    adj[9] = {8, 10};
    adj[10] = {9, 11};
    adj[11] = {8, 10};
    adj[12] = {0, 13, 14, 15, 16};
    adj[13] = {12};
    adj[14] = {12};
    adj[15] = {12};
    adj[16] = {12};
    vector<vector<int>> m(n, vector<int>(n, 0));
    cout<<"-----------ADJACENCY LIST----------\n";
    for(int i = 0; i < n; i++)
    {
        cout<<i<<"--->";
        for(int j = 0; j < adj[i].size(); j++)
        {
            m[i][adj[i][j]] = 1;
            m[adj[i][j]][i] = 1;
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n----------ADJACENCY MATRIX------------\n";
    cout<<"   ";
    for(int i = 0; i < n; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<i<<"  ";
        // for(auto j: i) cout<<j<<" ";
        for(int j = 0; j < n; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    cout<<"\n----------DEGREES OF EACH NODES----------\n";
    for(int i = 0; i < n; i++)
    {
        cout<<"Degree of "<<i<<": "<<adj[i].size()<<endl;
    }
    vector<int> ans;
    cout<<endl<<endl;
    vector<int> vis(n, 0);
    int src, dest;
    cout<<"\nEnter the source node: ";
    cin>>src;
    cout<<"Enter the destination node: ";
    cin>>dest;
    ans.push_back(src);
    if(dfs(src, dest, adj, vis, ans))
    {
        cout<<"The path from "<<src<<" to "<<dest<<" is: ";
        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"The given graph is not connected\n";
    }
    
    
    

    return 0;
}
