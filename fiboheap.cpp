#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int INF = 1000000000;

struct VertexDist {
	int node;
	int dist;

	VertexDist(int node, int dist): node(node), dist(dist) {}

	bool operator< (const VertexDist &other) const {
		return dist < other.dist;
	}
	bool operator> (const VertexDist &other) const {
		return dist > other.dist;
	}
};

template<typename T>
struct Node {
	T val;
	bool mark;
	int degree;
	Node<T> *left, *right, *child, *parent;

	Node(): left(nullptr), right(nullptr), child(nullptr), parent(nullptr), mark(false), degree(0) {}
	Node(T x): left(nullptr), right(nullptr), child(nullptr), parent(nullptr), val(x), mark(false), degree(0) {}
};

template<typename T>
class FiboHeap {

	Node<T> *_min;
	Node<T> *head;

	int num_nodes;

	void cut_tree(Node<T>*);
	Node<T> *join_fibo_trees(Node<T>*, Node<T>*);
public:

	FiboHeap(): head(nullptr), _min(nullptr), num_nodes(0) {}
	FiboHeap(Node<T>* head, Node<T>* _min, int num_nodes): head(head), _min(_min), num_nodes(num_nodes) {}

	Node<T>* insert(T);
	T min();
	void fibo_union(FiboHeap<T> &);
	T extract_min();
	void traverse();
	void consolidate_root_list();
	void decrease_key(Node<T>*, T newVal);
};

template<typename T>
Node<T>* FiboHeap<T>::join_fibo_trees(Node<T>* tree1, Node<T>* tree2) {

	if(tree1->val > tree2->val) {
		swap(tree1, tree2);
	}

	tree1->parent = nullptr;
	tree2->parent = nullptr;

	if(tree1->degree == 0) {
		tree1->child = tree2;
		tree2->parent = tree1;

		tree2->left = tree2;
		tree2->right = tree2;
	}
	else {

		Node<T>* child_head = tree1->child;
		Node<T>* child_end = child_head->left;

		tree1->child = tree2;
		tree2->parent = tree1;

		child_head->left = tree2;
		child_end->right = tree2;

		tree2->right = child_head;
		tree2->left = child_end;
	}

	tree1->degree ++;

	return tree1;
}

template<typename T>
void FiboHeap<T>::consolidate_root_list() {

	// +1 to handle precision issues.
	int max_degree = log2(num_nodes)/log2((1+sqrt(5))/2.0) + 1;
	vector<Node<T>*> node_list(max_degree + 1, nullptr);

	Node<T>* el_root = head;
	do {
		Node<T>* next_node = el_root->right;
		
		while(node_list[el_root->degree] != nullptr) {
			Node<T>* prev_node = node_list[el_root->degree];
			node_list[el_root->degree] = nullptr;

			el_root = join_fibo_trees(el_root, prev_node);
		}
		node_list[el_root->degree] = el_root;

		el_root = next_node;

	} while(el_root != head);

	// Join the roots in doubly linked list
	head = nullptr;
	_min = nullptr;
	for(int degree = 0;degree <= max_degree;degree++) {
		if(node_list[degree] != nullptr) {

			Node<T>* node = node_list[degree];

			if(head == nullptr) {
				head = node;
				head->left = head;
				head->right = head;
			}
			else {
				Node<T>* end = head->left;

				node->parent = nullptr;

				end->right = node;
				node->left = end;

				node->right = head;
				head->left = node;
			}

			// Update min pointer
			if(_min == nullptr || node->val < _min->val) {
				_min = node;
			}
		}
	}
}


template<typename T>
Node<T>* FiboHeap<T>::insert(T val) {
	Node<T>* x = new Node<T>(val);
	if (head == nullptr) {
		head = x;
		x->left = x;
		x->right = x;
		_min = x;
	} else {
		Node<T>* end = head->left;

		head->left = x;
		end->right = x;

		x->left = end;
		x->right = head;

		if(val < _min->val)
			_min = x; 
	}
	num_nodes++;

	return x;
}


template<typename T>
T FiboHeap<T>::min() {
	return _min->val;
}

template<typename T>
void FiboHeap<T>::traverse() {
	Node<T>* node = head;
	if (node == nullptr) {
		cout << "Empty List!" << endl;
		return;
	}
	do {
		cout << node->val << " ";
		node = node->right;
	} while (node != head);

	cout << endl;
}

template<typename T>
void FiboHeap<T>::fibo_union(FiboHeap<T> &heap2) {

	Node<T>* head2 = heap2.head;

	if(head == nullptr) {
		head = heap2.head;
		_min = heap2._min;
	}
	else if(heap2.head != nullptr) {
		head->left->right = head2;
		head2->left->right = head;

		head->left = head2->left;
		head2->left = head->left;

		if(heap2._min->val < _min->val) {
			_min = heap2._min;
		}
	}

	num_nodes += heap2.num_nodes;

	heap2.head = nullptr;
	heap2._min = nullptr;
	heap2.num_nodes = 0;
}

template<typename T>
T FiboHeap<T>::extract_min() {

	T mn_val = _min->val;
	if(_min->left == _min) {
		head = nullptr;
	}
	else {
		_min->right->left = _min->left;
		_min->left->right = _min->right;

		head = _min->right;
	}

	Node<T>* child_head = _min->child;
	Node<T>* child_min = _min->child;

	delete _min;

	_min = head;
	num_nodes--;

	if(child_head != nullptr) {
		Node<T>* cur = child_head;
		do {
			cur->parent = nullptr;
			cur = cur->right;
		} while(cur != child_head);
	}

	// Join root lists
	// num_nodes does not matter in child_heap
	FiboHeap<T> child_heap(child_head, child_min, 0);
	fibo_union(child_heap);

	if(num_nodes != 0) {
		consolidate_root_list();
	}

	return mn_val;
}

template<typename T>
void FiboHeap<T>::cut_tree(Node<T>* node){
	Node<T>* parent = node->parent;

	node->mark = false;

	if(parent == nullptr) return;

	if(node->right == node) {
		parent->child = nullptr;
	}
	else {
		parent->child = node->right;

		node->left->right = node->right;
		node->right->left = node->left;
	}

	node->parent = nullptr;

	if (node->val < _min->val)
		_min = node;

	node->right = head->right;
	head->right->left = node;
	head->right = node;
	node->left = head;

	if (parent->mark)
		cut_tree(parent);
	else 
		parent->mark = true;

	
	parent->degree--;
}

template<typename T>
void FiboHeap<T>::decrease_key(Node<T>* node, T newVal) {
	node->val = newVal;

	Node<T>* parent = node->parent;
	if(parent != nullptr && parent->val > node->val) {
		cut_tree(node);
	}
}

signed main() {

	int n, m;
	cin >> n >> m;

	FiboHeap<VertexDist> f;
	vector<Node<VertexDist>*> nodeMap(n+1);
	unordered_map<Node<VertexDist>*, int> invMap;

	vector<pair<int,int> > neighbors[n+1];
	for(int i=0;i<m;i++) {
		int a, b, c;
		cin>>a>>b>>c;
		a++; b++;
		neighbors[a].push_back({b,c});
		neighbors[b].push_back({a,c});
	}


	int src, dest;
	cin>>src>>dest;
	nodeMap[src] = f.insert(VertexDist(src, 0));
	invMap[nodeMap[src]] = src;

	for(int i=1;i<=n;i++) {
		if(i!=src) {
			nodeMap[i] = f.insert(VertexDist(i, INF));
			invMap[nodeMap[i]] = i;
		}
	}

	vector<bool> vis(n+1, false);
	vector<int> dist(n+1, INF);
	vector<int> parent(n+1, -1);
	dist[src] = 0;

	for(int i=0;i<n-1;i++) {
		
		int u = f.extract_min().node;
		vis[u] = true;

		for(auto &x: neighbors[u]) {
			int v = x.first;
			int w = x.second;

			if(!vis[v]) {
				if(dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					f.decrease_key(nodeMap[v], VertexDist(v, dist[v]));
					parent[v] = u;
				}
			}

		}
	}

	for(int i=1;i<=n;i++) cout<<i<<" -- "<<dist[i]<<endl;

	vector<int> path;
	int cur = dest;
	while(parent[cur]!=-1) {
		path.push_back(cur);
		cur = parent[cur];
	}
	reverse(path.begin(), path.end());
	for(auto x: path) {
		cout<<x<<" ";
	}
}
