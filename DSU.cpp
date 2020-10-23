#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> dsu(1000,0);

void init_dsu() {
    for(int i=0; i<dsu.size(); ++i)
        dsu[i] = i;
}

// Finding the root of a tree by traversing up the tree.
ll root(ll x){
   while(x!=dsu[x]){
       x = dsu[x];
   }
   return x;
}

// This is to take the union of 2 dsu trees.
void wunion(ll a, ll b){
    ll roota = root(a);
    ll rootb = root(b);

    // checking if the trees are already merged. 
    // if yes then merging again may create a cycle.
    if(roota == rootb)
        return;
    
    dsu[roota] = dsu[rootb];
}

int main(){
    init_dsu();
    // now dsu operations can be performed as required.
}