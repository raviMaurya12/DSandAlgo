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

void update(int a[],int blocks[],int n,int B,int index,int val){
	index--;       //0 based indexing
	blocks[index/B]=blocks[index/B]-a[index]+val;
	a[index]=val;
}

int get(int a[],int blocks[],int n,int B,int l,int r){
	l--;
	r--;   //0 based indexing 
	int res=0;

	//Same block case 
	if(l/B==r/B){
		for(int i=l;i<=r;i++){
			res+=a[i];
		}
		return res;
	}

	///Different block 

	//left block
	for(int i=l;i<(l/B+1)*B;i++){
		res+=a[i];
	}

	//middle block
	for(int i=(l/B+1);i<r/B;i++){
		res+=blocks[i];
	}

	//right block
	for(int i=(r/B)*B;i<=r;i++){
		res+=a[i];
	}
	return res;
}

int32_t main(){
	boost;
	int n;
	cin>>n;
	int a[n];
	rep(i,0,n){
		cin>>a[i];
	}

	//Preprocessing 
	int B=sqrt(n);
	int blocks[B+1];
	set0(blocks);
	rep(i,0,n){
		blocks[i/B]+=a[i];
	}

	//Query Processing 
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="update"){
			int index,val;
			cin>>index>>val;   //1 based index
			update(a,blocks,n,B,index,val);
		}else{
			int l,r;
			cin>>l>>r;     		//1 based l and r 
			int ans=get(a,blocks,n,B,l,r);
			cout<<ans<<endl;
		}
	}
	return 0;
}