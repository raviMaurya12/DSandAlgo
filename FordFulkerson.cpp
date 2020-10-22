#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> matrix;
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back

struct PathInfo {
    bool exists;
    vector<pii> path;
};

struct Edge {
    int src,dest,weight;
};

class Graph {
    int n;
    matrix adj;

public: 
    Graph(int n) {
        this->n = n;
        this->adj.resize(n+1, vi(n+1,0));
    }

    void addEdge(int u,int v, int weight) {
        adj[u][v] = weight;
    }

    int getNodeCount() const{
        return n;
    }

    matrix getAdjacencyMatrix() const{
        return adj;
    }

};

void updateHelperFulkerson(vector<pii> path, matrix &adj, matrix &residual, matrix &flow,int &maxFlow) {

    static int iter = 0;
    iter++;

    int deltaFlow = INT_MAX;

    int pathLength = path.size();
    for(int i=0;i<pathLength;i++)
        deltaFlow = min(deltaFlow, residual[path[i].first][path[i].second]);

    cout<<"Iter "<<iter<<"-> +"<<deltaFlow<<endl;

    maxFlow += deltaFlow;

    for(int i=0;i<pathLength;i++) {
        int u = path[i].first;
        int v = path[i].second;

        residual[u][v] -= deltaFlow;
        residual[v][u] += deltaFlow;

        if(adj[u][v])
            flow[u][v] += deltaFlow;
        else
            flow[v][u] -= deltaFlow;

    }

    return;
}


PathInfo getAugmentedPath(int s, int t,const matrix &residual){
    int n = residual.size()-1;
    vector<bool> visited(n+1,0);
    vi parent(n+1,-1);

    //bfs
    queue<int> q;
    q.push(s);
    while(!q.empty()) {

        int x = q.front();
        visited[x] = true;
        q.pop();

        for(int i=1;i<=n;i++)
            if(!visited[i] && residual[x][i])
                q.push(i),parent[i] = x;
    }

    PathInfo augmentedPath;

    // path to sink does not exist
    if(parent[t]==-1){
        augmentedPath.exists = false;
        return augmentedPath;
    }

    // form path
    vector<pii> path;
    int cur = t;
    while(cur!=s){
        int par = parent[cur];
        path.pb({par,cur});
        cur = par;
    }
    reverse(path.begin(),path.end());

    augmentedPath.path = path;
    augmentedPath.exists = true;

    return augmentedPath;
}

int fordFulkerson(Graph g,int s,int t,bool debug = false) {
    
    int maxFlow = 0;
    matrix adj = g.getAdjacencyMatrix();
    matrix residual = adj;
    int n = adj.size();
    matrix flow(n+1,vi(n+1,0));

    while(true) {

        PathInfo augmentedPath = getAugmentedPath(s, t, residual);
        if(!augmentedPath.exists)
            break;
        updateHelperFulkerson(augmentedPath.path, adj,residual, flow, maxFlow);
    }

    return maxFlow;
}

Graph initGraph(int V, int E,vector<Edge> edges){
    Graph g(V);

    for(int i=0;i<E;i++){
        int u = edges[i].src,
            v = edges[i].dest,
            weight = edges[i].weight;

        g.addEdge(u,v,weight);
    }

    return g;
}

int main(){

    int V,E;
    vector<Edge> edges;
    cout<<"Nodes: ";
    cin>>V;
    cout<<"Edges: ";
    cin>>E;
    cout<<"1-indexed edges : \n";
    for(int i=0;i<E;i++){
        Edge e;
        cin>>e.src>>e.dest>>e.weight;
        edges.pb(e);
    }

    Graph g = initGraph(V,E,edges);

    int s,t;
    cout<<"Source : ";
    cin>>s;
    cout<<"Sink : ";
    cin>>t;

    cout << fordFulkerson(g,s,t);

}

/* 
Random example (expected answer 23)
6
8
1 2 11
1 3 12
3 2 1
2 4 12
3 5 11
5 4 7
4 6 19
5 6 4
1
6
*/
