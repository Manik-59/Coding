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
ll n,m,k,c;
ll parent [1001];
void build_graph(vector<pair<ll,ll>>v)
{
	graph.assign(n+1,vector<ll>());
	for(ll i=0;i<v.size();i++)
	{
		graph[v[i].first].pb(v[i].second);
		graph[v[i].second].pb(v[i].first);
	}
	for(ll i=0;i<=n;i++)
		sort(graph[i].begin(),graph[i].end());
}
void bfs(ll par,ll child)
{
	bool visited[1001];
	fill_n(visited,1001,false);
	queue<ll>q;
	q.push(par);
	visited[par]=true;
	while(!q.empty())
	{
		ll i=q.front();
		q.pop();
		visited[i]=true;
		for(ll j=0;j<graph[i].size();j++)
		{
			if(visited[graph[i][j]]==false)
			{

				parent[graph[i][j]]=i;
				q.push(graph[i][j]);
				if(graph[i][j]==child)
					return;
				

			}
		}
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
    	cin>>n>>m>>k>>c;
    	vector<pair<ll,ll>>v;
    	for(ll i=0;i<m;i++)
    	{
    		ll a,b;
    		cin>>a>>b;
    		v.pb({a,b});
    	}
    	build_graph(v);
    	ll x,y;
    	cin>>x>>y;
    	bfs(x,y);
    	cout<<"manik"<<endl;
    	vector<ll>v1;
    	v1.pb(y);
    	ll d=y;
    	while(d!=x)
    	{
    		d=parent[d];
    		v1.pb(d);
    	}
    	// v.pb(x);
    	cout<<v1.size()<<endl;
    	for(ll i=v1.size()-1;i>=0;i--)
    		cout<<v1[i]<<" ";

    }
    return 0;
}