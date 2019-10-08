#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair
#define tci(v,i) for(auto i=v.begin();i!=v.end();i++)
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define revrep(i,n) for(long long i=n-1;i>=0;i--)
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define osit ostream_iterator<int> output (cout," ")
#define pv(x) copy(all(x),output)
#define pa(a) rep(i,0,sizeof(a)/sizeof(a[0]))cout<<a[i]<<" "
#define endl '\n'
#define f first
#define s second
#define PI 3.141592653589793
#define test int t;cin>>t; while(t--)
#define set0(x) memset(x,0,sizeof(x))
#define set1(x) memset(x,1,sizeof(x))
#define getarr(arr,n) int arr[n];rep(i,0,n)cin>>a[i]
#define getvec(vec,n) vi vec;int x;rep(i,0,n){cin>>x;vec.pb(x);}
#define dg(x) cout<<#x<<':'<<x<<endl;
#define dg2(x,y) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<endl;
#define dg3(x,y,z) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<endl;
#define dg4(x,y,z,zz) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<' '<<#zz<<':'<<zz<<endl;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
template<typename T> T gcd(T a,T b){if(a==0) return b; return gcd(b%a,a);}
vi b_v;void bin(unsigned int n) { if (n > 1) bin(n>>1); b_v.pb(n & 1); }
int isPowerof2(int x) { return (x && !(x & x-1)); }

int n=8; // number of vertices
vi adj[8],adj2[8]; // adjacency list of graph
int visited[8];
int st[8];
int ft[8];
int t=1;
stack<int> stk;


void dfs(int v) {
	//cout<<v<<" ";
    visited[v] = 1;
    st[v]=t;
    t++;
    for (int u : adj[v]) {
        if (visited[u]==0)dfs(u);
    }
    visited[v]=2;
    ft[v]=t;
    t++;
    stk.push(v);
}

int32_t main(){
	boost;osit;
	set0(visited);
	rep(i,1,8){
		int n;
		cin>>n;
		rep(j,0,n){
			int x;
			cin>>x;
			adj[i].pb(x);
		}
	}
	rep(i,1,8){
		if(visited[i]==0)dfs(i);
	}
	rep(i,1,8){
		dg2(st[i],ft[i]);
	}
	return 0;
}

