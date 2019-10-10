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

void add(int val,int index,int ftree[],int n){
	index++;
	while(index<=n){
		ftree[index]+=val;
		index+=index&(-index);
	}
}

int getsum(int index,int ftree[],int n){
	index++;
	int sum=0;
	while(index>0){
		sum+=ftree[index];
		index-=index&(-index);
	}
	return sum;
}

int32_t main(){
	boost;
	int n;
	cin>>n;
	int a[n];
	rep(i,0,n){
		cin>>a[i];
	}
	int ftree[n+1];
	rep(i,1,n+1){
		ftree[i]=0;
	}
	rep(i,0,n){
		add(a[i],i,ftree,n);
	}
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="update"){
			int idx,val;
			cin>>idx>>val; //0 based index
			val=val-a[idx]; //this will be added(maybe positive or negative)
			add(val,idx,ftree,n);
		}else{
			int idx;
			cin>>idx;
			int res=getsum(idx,ftree,n);
			cout<<res<<endl;
		}
	}
	return 0;
}