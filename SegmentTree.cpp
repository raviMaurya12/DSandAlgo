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

int n;

void buildTree(int a[],int *tree,int l,int r,int index){
	if(l>r)return ;
	if(l==r){
		tree[index]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	buildTree(a,tree,l,mid,2*index);
	buildTree(a,tree,mid+1,r,2*index+1);
	tree[index]=tree[2*index]+tree[2*index+1];
}

int sum(int *tree,int index,int l,int r,int ql,int qr){
	if(r<ql || l>qr)return 0;
	if(l>=ql && r<=qr)return tree[index];
	int mid=(l+r)/2;
	int leftsum=sum(tree,2*index,l,mid,ql,qr);
	int rightsum=sum(tree,2*index+1,mid+1,r,ql,qr);
	return leftsum+rightsum;	
}

void update(int *tree,int index,int l,int r,int i,int val){
	if(i>r || i<l)return ;
	if(l==r){
		tree[index]=val;
		return;
	}
	int mid=(l+r)/2;
	update(tree,2*index,l,mid,i,val);
	update(tree,2*index+1,mid+1,r,i,val);
	tree[index]=tree[2*index]+tree[2*index+1];
}

void rangeUpdate(int *tree,int index,int l,int r,int ql,int qr,int inc){
	if(r<ql || l>qr)return;
	if(l==r){
		tree[index]+=inc;
		return;
	}
	int mid=(l+r)/2;
	rangeUpdate(tree,2*index,l,mid,ql,qr,inc);
	rangeUpdate(tree,2*index+1,mid+1,r,ql,qr,inc);
	tree[index]=tree[2*index]+tree[2*index+1];
}

int32_t main(){
	//boost;
	cin>>n;
	int a[n];
	rep(i,0,n)cin>>a[i];

	//Build Tree
	int *tree=new int[4*n+1];
	buildTree(a,tree,0,n-1,1);
	rep(i,1,4*n+1){
		cout<<tree[i]<<" ";
	}
	cout<<endl;

	//Query processing
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="sum"){
			//sum
			int l,r;
			cin>>l>>r;
			cout<<sum(tree,1,0,n-1,l,r)<<endl;
		}else{
			//update
			int i,val;
			cin>>i>>val;
			update(tree,1,0,n-1,i,val);
			rep(i,1,4*n+1){
				cout<<tree[i]<<" ";
			}
			cout<<endl;
		}
	}

	//Range update
	rangeUpdate(tree,1,0,n-1,2,3,1);
	rep(i,1,4*n+1){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	return 0;
}