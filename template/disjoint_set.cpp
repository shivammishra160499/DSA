#include<bits/stdc++.h>
using namespace std;

class disjoint_set {
    vector<int> size, parent;

public:
    disjoint_set(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int get_par(int v) {
        if (parent[v] == v)
            return v;
        parent[v] = get_par(parent[v]);
        return parent[v];
    }

    int is_same_group(int x, int y) {
        return get_par(x) == get_par(y);
    }

    void make_union(int u, int v) {
        int par_u = get_par(u);
        int par_v = get_par(v);
        
        if (par_u == par_v)
            return;

        if (size[par_u] < size[par_v]) {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        } else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }

    int get_size(int x) {
        return size[x];
    }
};

 
 
int main()
{    disjoint_set ds(4);
     ds.make_union(1,0);
     ds.make_union(1,2);
     
     cout<<ds.get_par(2)<<endl;
     //cout<<ds.get_par(0)<<endl;
     cout<<ds.is_same_group(2,0)<<endl;
     
	return 0;
}