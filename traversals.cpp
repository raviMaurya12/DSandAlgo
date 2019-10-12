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


void inorder1(TreeNode *root){
	if(root==NULL)return ;
	inorder1(root->left);
	cout<<root->val<<" ";
	inorder1(root->right);
}

void inorder2(TreeNode *root){
	stack<pair<TreeNode*,int> > st;
	st.push(mp(root,0));
	while(!st.empty()){
		auto cur=st.top();
		if(cur.f){
			if(cur.s==0){
				st.pop();
				st.push(mp(cur.f,1));
				st.push(mp(cur.f->left,0));
			}else if(cur.s==1){
				cout<<cur.f->val<<" ";
				st.pop();
				st.push(mp(cur.f,2));
				st.push(mp(cur.f->right,0));
			}else if(cur.s==2){
				st.pop();
			}
		}else{
			st.pop();
		}
	}
}

void preorder1(TreeNode *root){
	if(!root)return ;
	cout<<root->val<<" ";
	preorder1(root->left);
	preorder1(root->right);
}

void preorder2(TreeNode *root){
	stack<pair<TreeNode*,int> > st;
	st.push(mp(root,0));
	while(!st.empty()){
		auto cur=st.top();
		if(cur.f){
			if(cur.s==0){
				cout<<cur.f->val<<" ";
				st.pop();
				st.push(mp(cur.f,1));
				st.push(mp(cur.f->left,0));
			}else if(cur.s==1){
				st.pop();
				st.push(mp(cur.f,2));
				st.push(mp(cur.f->right,0));
			}else if(cur.s==2){
				st.pop();
			}
		}else{
			st.pop();
		}
	}
}

void postorder1(TreeNode *root){
	if(!root)return;
	postorder1(root->left);
	postorder1(root->right);
	cout<<root->val<<" ";
}

void postorder2(TreeNode *root){
	stack<pair<TreeNode*,int> > st;
	st.push(mp(root,0));
	while(!st.empty()){
		auto cur=st.top();
		if(cur.f){
			if(cur.s==0){
				st.pop();
				st.push(mp(cur.f,1));
				st.push(mp(cur.f->left,0));
			}else if(cur.s==1){
				st.pop();
				st.push(mp(cur.f,2));
				st.push(mp(cur.f->right,1));
			}else if(cur.s==2){
				cout<<cur.f->val<<" ";
				st.pop();
			}
		}else{
			st.pop();
		}
	}
}

map<int,vi> mpp;
void voutil(TreeNode *root,int w){
	if(!root)return ;
	mpp[w].pb(root->val);
	voutil(root->left,w-1);
	voutil(root->right,w+1);
}

void verticalorder(TreeNode *root){
	osit;
	voutil(root,0);
	tci(mpp,itr){
		vi v=mpp[itr->first];
		pv(v);
		cout<<endl;
	}
}

void loutil(TreeNode *root,int w){
	if(!root)return ;
	loutil(root->left,w+1);
	mpp[w].pb(root->val);
	loutil(root->right,w+1);
}

void levelorder1(TreeNode *root){
	osit;
	loutil(root,0);
	int flag=0;
	tci(mpp,itr){
		vi v=mpp[itr->first];
		if(flag)reverse(all(v)); //for spiral level order or zigzag traversal
		pv(v);
		flag=flag^1;
		cout<<endl;
	}
}

void levelorder2(TreeNode *root){
	vector<TreeNode*> v,tv;
	v.pb(root);
	int flag=0;
	while(v.size()!=0){
		if(flag)reverse(all(v));  //for spiral level order or zigzag traversal
		for(auto el:v){
			cout<<el->val<<" ";
		}
		if(flag)reverse(all(v));  //flip again to get original
		for(auto el:v){
			if(el->left)tv.pb(el->left);
			if(el->right)tv.pb(el->right);
		}
		cout<<endl;
		v.clear();
		v=tv;
		tv.clear();
		flag=1^flag;
	}
}

int32_t main(){
	boost;
	// Example tree 1
	TreeNode *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(10);
	root->right->right=createNode(6);
	root->left->left->left=createNode(7);
	root->right->right->right=createNode(8);
	root->left->left->left->right=createNode(9);
	levelorder1(root);
	cout<<endl<<endl;
	levelorder2(root);

	/*
	//Example tree 2 
	TreeNode *root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->left->right = createNode(5); 
    root->right->left = createNode(6); 
    root->right->right = createNode(7); 
    root->right->left->right = createNode(8); 
    root->right->right->right = createNode(9); 
    verticalorder(root);
    */
	return 0;
}