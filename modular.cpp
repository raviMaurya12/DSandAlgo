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
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
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

int extgcd(int a, int b, int *x, int *y){ 
    if (a == 0){ 
        *x = 0;
		*y = 1; 
        return b; 
    } 
    int x1, y1; 
    int gcd = extgcd(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 

int modexp(int x,int y,int mod){
	x%=mod;
	int res=1;
	while(y>0){ 
        if(y & 1)res=(res*x)%mod; 
        y=y>>1;
        x=(x*x)%mod;   
    } 
    return res; 
}

int invmod(int a,int mod){
	int x,y;
	int g=extgcd(a,mod,&x,&y);
	if (g != 1) {
		cout << "Inverse doesn't exist\n"; 
		return -1;
	}else{ 
        int res = (x%mod + mod) % mod; 
        return res;
    } 
}

int moddiv(int a,int b,int mod){
	a%=mod;
	int inv=invmod(b,mod);
	if(inv==-1){
		cout<<"Modular Division not possible\n";
		return -1;
	}else{
		return (inv*a)%mod;
	}
}

int mulorder(int a,int mod){
	if(gcd(a,mod)!=1){
		cout<<"Multiplicative order do not exists\n";
		return -1;
	}else{
		int res=1;
		int k=1;
		while(k<mod){
			res=(res*a)%mod;
			if(res==1)return k;
			k++;
		}
		return -1;
	}
}

int modstring(string num, int mod){ 
	int res = 0;
	for (int i = 0; i < num.length(); i++) 
		res = (res*10 + (int)num[i] - '0') %mod; 
	return res; 
} 

int largemodmul(int a,int b,int mod){
	int res=0;
	a%=mod;
	while(b){
		if(b&1)res=(res+a)%mod;
		a=(2*a)%mod;
		b>>=1;
	}
	return res;
}

int popmod(int a,int b,int c,int mod){
	//mod must be prime
	int tmp=modexp(b,c,mod-1);
	return modexp(a,tmp,mod);
}

int32_t main(){
	boost;osit;
	int A = 3, B = 9, C = 4, M = 19; 
	cout << popmod(A, B, C, M); 
	return 0;
}












