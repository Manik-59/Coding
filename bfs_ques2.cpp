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
ll n,m,k;
ll level[10001];
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
    fill_n(level,10001,-1);
    queue<pair<ll,ll>>q;
    q.push({parent,0});
    if(k==0)
        return 0;
    else
    {
        ll x=k-1,count1=0;
        while(!q.empty())
        {
            pair<ll,ll>p;
            p=q.front();
            q.pop();
            ll node=p.first,no=p.second;
            
                visited[node]=true;
                        for(ll i=0;i<graph[node].size();i++)
                        {
                            if(visited[graph[node][i]]==false )
                            {
                                if(level[graph[node][i]]==-1)
                                    {
                                        q.push({graph[node][i],no+1});
                                        level[graph[node][i]]=no+1;
                                        if(x==no)
                                            count1++;
                                    }
                            }
                        }
                        if(no==k)
                            return count1;
        }
        return 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t  = 1;
    while(t--)
    {
        cin>>n>>m;
        vector<pair<ll,ll>>v;
        for(ll i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            v.pb({a,b});
        }
        build_graph(v);
        ll q;
        cin>>q;
        for(ll i=0;i<q;i++)
        {
            ll node;
            cin>>node>>k;
            cout<<bfs(node)<<endl;
        }
    }
    return 0;
}