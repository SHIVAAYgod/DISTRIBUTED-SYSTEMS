#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define nline "\n"
const int INF = 1e9 + 7;
void dijsktra(int s,int d,vector<pair<int,int>> g[],vector<int> &dist,vector<int> &parent)
{
    set<pair<int,int>> st;
    dist[s] = 0;
    st.insert({0,s});
    while(st.size() > 0)
    {
        auto curr = *st.begin();
        st.erase(st.begin());
        auto par = curr.second;
        auto w = curr.first;
        if(dist[par] != w)
            continue;
        for(auto &val:g[par])
        {
            int child = val.first;
            int weight = val.second;
            if(dist[child] > dist[par] + weight)
            {
                parent[child] = par;
                dist[child] = dist[par] + weight;
                st.insert({dist[child],child});
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    int m;
    cin>>m;
    vector<pair<int,int>> g[n + 1];
    cout<<"Enter the edges: "<<nline;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cout<<"Randomely Generated source: ";
    int s = 1 + (rand() % n);
    cout<<s<<nline;
    cout<<"Randomely Generated destinition: ";
    int d = 1 + (rand() % n);
    cout<<d<<nline;
    vector<int> dist(n+1,INF);
    vector<int> par(n+1,-1);
    dijsktra(s,d,g,dist,par);
    cout<<"Distance between source and destinition is : ";
    cout<<dist[d]<<nline;
    cout<<"The path is: ";
    vector<int> path;
    int j = d;
    while(j != -1)
    {
        path.push_back(j);
        j = par[j];
    }
    reverse(path.begin(),path.end());
    for(auto &val:path)
        cout<<val<<" ";
    cout<<nline;
    return 0;
}
