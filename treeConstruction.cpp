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

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* createNode(int data){
	TreeNode *root=new TreeNode;
	root->val=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}

void preorder(TreeNode *root){
	if(!root)return ;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode *root){
	if(root==NULL)return ;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void postorder(TreeNode *root){
	if(!root)return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}

int search(int item,vi v){
	rep(i,0,v.size()){
		if(v[i]==item){
			return i;
		}
	}
	return -1;
}

TreeNode* fromInPreorder(vi in,vi pre){
	if(in.size()!=pre.size()){
		cout<<"Sizes Unequal!"<<endl;
		exit(0);
	}
	if(pre.size()==0)return NULL;
	TreeNode *root=createNode(pre[0]);
	if(pre.size()==1)return root;
	int index=search(pre[0],in);
	if(index==-1){
		cout<<"Element not found!"<<endl;
		exit(0);
	}
	vi newinleft(in.begin(),in.begin()+index);
	vi newinright(in.begin()+index+1,in.end());
	vi newpreleft(pre.begin()+1,pre.begin()+index+1);
	vi newpreright(pre.begin()+index+1,pre.end());
	root->left=fromInPreorder(newinleft,newpreleft);
	root->right=fromInPreorder(newinright,newpreright);
	return root;
}

stack<int> ans;
void withoutConst(vi in,vi pre){
	if(in.size()!=pre.size()){
		cout<<"Sizes Unequal!"<<endl;
		exit(0);
	}
	if(pre.size()==0)return ;
	ans.push(pre[0]);
	if(pre.size()==1)return ;
	int index=search(pre[0],in);
	if(index==-1){
		cout<<"Element not found!"<<endl;
		exit(0);
	}
	vi newinleft(in.begin(),in.begin()+index);
	vi newinright(in.begin()+index+1,in.end());
	vi newpreleft(pre.begin()+1,pre.begin()+index+1);
	vi newpreright(pre.begin()+index+1,pre.end());
	withoutConst(newinright,newpreright);
	withoutConst(newinleft,newpreleft);
	return ;
}

int32_t main(){
	boost;
	vi in={4,10,12,15,18,22,24,25,31,35,44,50,66,70,90};
	vi pre={25,15,10,4,12,22,18,24,50,35,31,44,70,66,90};
	//TreeNode *newroot=fromInPreorder(in,pre);

	// inorder(root);
	// cout<<endl;
	//inorder(newroot);
	// cout<<endl<<endl;
	// preorder(root);
	//cout<<endl;
	//preorder(newroot);
	// cout<<endl<<endl;
	// postorder(root);
	//cout<<endl;
	//postorder(newroot);

	//Post order from Inorder and Preorder,Without tree construction.
	withoutConst(in,pre);
	while(!ans.empty()){
		auto el=ans.top();
		ans.pop();
		cout<<el<<" ";
	}

	return 0;
}