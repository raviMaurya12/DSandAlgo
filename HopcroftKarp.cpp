#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> matrix;
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define NIL 0
#define INF 1000000


class BipartiteGraph {
    int n;
    vi A,B;
    vi pairU;
    vi pairV;
    vi dist;
    matrix adj;

public: 
    BipartiteGraph(int n, vi A, vi B) {
        this->n = n;
        this->A = A;
        this->B = B;
        this->adj.resize(n+1, vi(n+1,0));
        this->pairU.resize(n+1,0);
        this->pairV.resize(n+1,0);
        this->dist.resize(n+1,0);
    }

    void addEdge(int u,int v) {
        adj[u][v] = 1;
    }

    vi getFirstSet() const {
        return A;
    }

    int getNodes() const {
        return n;
    }

    matrix getAdjMatrix() const {
        return adj;
    }

    bool bfs();

    bool dfs(int u);

    void printMatching();

    int hopkroftKarp();

};

BipartiteGraph initBipartiteGraph(int V, int E, vi &A, vi &B, vector<pii> &edges) {

    // Total Nodes, Node List of both parts
    BipartiteGraph g(V,A,B); 
    
    for(int i=0;i<E;i++) {
        int u = edges[i].first, 
            v = edges[i].second;
        g.addEdge(u,v);
    }

    return g;
}

bool BipartiteGraph::bfs() {
  
    queue <int> q;
    for(int i=0;i<A.size();i++) {
        if(!pairU[A[i]]) {
            dist[A[i]] = 0;
            q.push(A[i]);
        }
        else dist[A[i]] = INF;
    }
    dist[NIL] = INF;

    while(!q.empty()) {
        int u = q.front(); 
        q.pop();
        if(dist[u] < dist[pairU[u]]) {
            for(int v=1;v<=n;v++) {
                if(adj[u][v]) {
                    if(dist[pairV[v]] = INF) {
                        dist[pairV[v]] = dist[u] + 1;
                    }
                    q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool BipartiteGraph::dfs(int u) {
   
    if(u != NIL) {
        for(int v=1;v<=n;v++) {
            if(adj[u][v]) {
                if(dist[pairV[v]] == dist[u]+1) {
                    if(dfs(pairV[v])) {
                        pairV[v] = u;
                        pairU[u] = v;
                        return true;
                    }
                }
            }
        } 
        dist[u] = INF;
        return false;  
    }
    return true;
}

void BipartiteGraph::printMatching(){
    
    cout << "The Matchings are  : \n";
    for(int u=1;u<=n;u++){
        if(pairU[u]){
            cout << u << " -- " << pairU[u] << endl;
        }
    }

}

int BipartiteGraph::hopkroftKarp() { 
    
    int finalMatching = 0;
    // Perform BFS to find if a path exists
    while(bfs()) {
        // Fetch A
        for(int i=0; i<A.size(); i++) {
            if(!pairU[A[i]]) {
                if(dfs(A[i])) finalMatching++;
            }
        }
    }

    return finalMatching;
}

int main() {

    int V,E;
    vector<pii> edges;
    vi A,B;
    int nodesA,nodesB;
    
    // cout<<"Number of nodes: ";
    cin>>V;
    // cout<<"Number of edges: ";
    cin>>E;

    // Nodes in 1st set
    // cout<<"Number of nodes in Set 1 : ";
    cin>>nodesA;
    // cout<<"Nodes of Set 1 : ";
    for(int i=0;i<nodesA;i++) {
        int v;
        cin>>v;
        A.pb(v);
    }

    // Nodes in 2nd set
    // cout<<"Number of nodes in Set 2 : ";
    cin>>nodesB;
    // cout<<"Nodes of Set 2 : ";
    for(int i=0;i<nodesB;i++) {
        int v;
        cin>>v;
        B.pb(v);
    }

    // Edges
    // cout<<"1-indexed edges (from set 1 to set 2) : \n";
    for(int i=0;i<E;i++) {
        pii e;
        cin>>e.first>>e.second;
        edges.pb(e);
    }

    BipartiteGraph g = initBipartiteGraph(V, E, A, B, edges);
    
    cout << "Maximum Matching : " << g.hopkroftKarp() << endl;
    g.printMatching();

}

/*

Sample Input

12
8
6 1 2 3 4 5 6
6 7 8 9 10 11 12
1 8
1 9
2 7
2 10
3 9
4 9
4 10
6 12
*/
