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

vi sieve(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++){
        if (prime[p] == true){
            for (int i=p*p; i<=n; i += p)prime[i] = false;
        }
    }
    vi v;
    for (int p=2; p<=n; p++)
       if (prime[p]) v.pb(p);
    return v;
}

vi divisors(int n){
    vi v;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i) v.pb(i);
            else v.pb(i),v.pb(n/i);
        }
    }
    return v;
}

int largestprimefactor(int n){
    int maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n >>= 1;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
    }
    if (n > 2) maxPrime = n;
  	return maxPrime;
}

int multiplicity(int x,int f){
	int res=0;
	while(x%f==0){
		res++;
		x/=f;
	}
	return res;
}

vi primefactors(int n){
	vi pf;
    int maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        pf.pb(2);
        n >>= 1;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            pf.pb(i);
            n = n / i;
        }
    }
    if (n > 2) maxPrime = n,pf.pb(n);
  	return pf;
}

vi don[1000001];
void divisorsofall(int n){
	for(int i=n;i>=1;--i)
		for(int j=i;j<=n;j+=i)don[j].push_back(i);
}

int32_t main(){
	boost;osit;
	int n;
	cin>>n;
	vi v=sieve(n);
     pv(v);
	return 0;
}
