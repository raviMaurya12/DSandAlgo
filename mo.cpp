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
#define set0(x) memset(x,0,sizeof(x))
#define set1(x) memset(x,1,sizeof(x))
#define getarr(arr,n) int arr[n];rep(i,0,n)cin>>a[i]
#define getvec(vec,n) vi vec;int x;rep(i,0,n){cin>>x;vec.pb(x);}
#define sort_uniq(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define uniq(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define dg(x) cout<<#x<<':'<<x<<endl;
#define dg2(x,y) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<endl;
#define dg3(x,y,z) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<endl;
#define dg4(x,y,z,zz) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<' '<<#zz<<':'<<zz<<endl;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
template<typename T> T gcd(T a,T b){if(a==0) return b; return gcd(b%a,a);}
int isPowerof2(int x) { return (x && !(x & x-1)); }

int block;
int n;
int q;

struct Query{
	int l,r,index,result;
};

bool cmp(Query q1,Query q2){
	if((q1.l/block)!=(q2.l/block)){
		return ((q1.l/block)<(q2.l/block));
	}else{
		return (q1.r < q2.r);
	}
}

bool cmpi(Query q1,Query q2){
	return (q1.index < q2.index);
}

int f[(int)(1e6+1)];

int32_t main(){
	boost;
	cin>>n;
	int a[n];
	rep(i,0,n)cin>>a[i];
	cin>>q;
	Query query[q];
	rep(i,0,q){
		int x,y;
		cin>>x>>y;
		x--;y--;
		query[i].l=x;
		query[i].r=y;
		query[i].index=i;
		query[i].result=0;
	}
	block=ceil(sqrt(n));
	sort(query,query+q,cmp);
	int curL=query[0].l;
	int curR=query[0].l;
	int ans=0;
	rep(i,0,q){
		int L=query[i].l;
		int R=query[i].r;
		while(curL<L){
			f[a[curL]]--;
			if(f[a[curL]]==0)ans--;
			curL++;
		}
		while(curL>L){
			f[a[curL-1]]++;
			if(f[a[curL-1]]==1)ans++;
			curL--;
		}
		while(curR<=R){
			f[a[curR]]++;
			if(f[a[curR]]==1)ans++;
			curR++;
		}
		while(curR>R+1){
			f[a[curR-1]]--;
			if(f[a[curR-1]]==0)ans--;
			curR--;
		}
		query[i].result=ans;
	}
	sort(query,query+q,cmpi);
	rep(i,0,q){
		cout<<query[i].result<<endl;
	}
	return 0;
}