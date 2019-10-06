// #include <iostream>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define nt _int128
#define mod 1000000007
vector<vector<ll>>graph;
ll n,m;
bool visited[10001];
void build_graph(vector<pair<ll,ll>>v)
{
    graph.assign(n+1,vector<ll>());
    for(ll i=0;i<v.size();i++)
    {
        graph[v[i].first].pb(v[i].second);
        graph[v[i].second].pb(v[i].first);
    }
}
ll bfs(ll parent)
{
    ll count=0;
    bool visited[10000];
    fill_n(visited,10001,false);
    queue<pair<ll,ll>>q;
    q.push({parent,0});
    pair<ll,ll>p=q.front();
    ll node=p.first,no=p.second;
    if(n==node)
        return no;
    while(!q.empty())
    {
        pair<ll,ll>p=q.front();
        node=p.first,no=p.second;
        q.pop();
        visited[node]=true;
        for(ll i=0;i<graph[node].size();i++)
        {
            if(n==graph[node][i])
                return no+1;
            if(visited[graph[node][i]]==false)
            {
                q.push({graph[node][i],no+1});
            }
        }
        no++;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    // t  = 1;
    while(t--)
    {
        cin>>n>>m;
        fill_n(visited,10001,false);
        vector<pair<ll,ll>>v;
        for(ll i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            v.pb({a,b});
        }
        build_graph(v);
        ll count1=0;
        count1=bfs(1);
        cout<<count1<<endl;
        graph.clear();
    }
    return 0;
}