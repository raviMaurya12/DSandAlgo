#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define osit ostream_iterator<int> output (cout," ")
#define pv(x) copy(all(x),output);cout<<endl;
#define endl '\n'
#define f first
#define s second
#define INF 1000000000000000000
#define set0(x) memset(x,0,sizeof(x))
#define dg(x) cout<<#x<<':'<<x<<endl;
#define dg2(x,y) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<endl;
#define dg3(x,y,z) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<endl;
#define dg4(x,y,z,zz) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<' '<<#zz<<':'<<zz<<endl;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
template<typename T> T gcd(T a,T b){if(a==0) return b; return gcd(b%a,a);}
 
int32_t main()
{
	boost;osit;

	//v: no. of vertex 
	//e: no. of edges
	int v,e;
	cin>>v>>e;


	vector<vector<pii> > adj(v);
	for(int i=0;i<e;++i)
	{
		int from,to,weight;
		cin>>from>>to>>weight;

		//Directed Graph
		adj[from].pb(mp(to,weight));

		/*

		//Undirected Graph
		adj[from].pb(mp(to,weight));
		adj[to].pb(mp(from,weight));

		*/
	}

	//Min Heap using priority_queue stl
	priority_queue< pii, vector <pii> , greater<pii> > pq;
	
	//Distance from Source Vertex (1e18 for non reachable vertices)
	vector<int> dis(v,INF);

	int source_vertex;
	cin>>source_vertex;

	dis[source_vertex]=0;

	pq.push(mp(dis[source_vertex],source_vertex));

	while(!pq.empty())
	{
		int vertex=pq.top().s;
		pq.pop();

		for(auto x : adj[vertex])
		{
			int adj_vertex=x.f;
			int adj_vertex_weight=x.s;

			if(dis[adj_vertex]>dis[vertex]+adj_vertex_weight)
			{
				dis[adj_vertex]=dis[vertex]+adj_vertex_weight;
				pq.push(mp(dis[adj_vertex],adj_vertex));
			}
		}
	}

	//Printing Shortest Dis from Source Vertex
	for(int i=0;i<v;++i)
	{
		cout<<dis[i]<<" ";
	}

	return 0;
}
