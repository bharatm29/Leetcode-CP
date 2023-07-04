#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
    private:
        vector<int> rank, size, parent;
    public:
        DisjointSet(int sz){
            rank.resize(sz + 1, 0);
            parent.resize(sz + 1);
            for(int i = 0; i <= sz; i++){
                parent[i] = i;
            }
            size.resize(sz + 1, 1);
        }

        int findUltParent(int u){
            if(parent[u] == u){
                return u;
            }

            return parent[u] = findUltParent(parent[u]);
        }

        void unionByRank(int u, int v){
            int ulpt_u = findUltParent(u);
            int ulpt_v = findUltParent(v);
            if(ulpt_v == ulpt_u) return;

            if(rank[ulpt_u] > rank[ulpt_v]){
                parent[ulpt_v] = ulpt_u;
            }
            else if(rank[ulpt_v] > rank[ulpt_u]){
                parent[ulpt_u] = ulpt_v;
            }
            else{
                parent[ulpt_u] = ulpt_v;
                rank[ulpt_v]++;
            }
        }

        void unionBySize(int u, int v){
            int ulpt_u = findUltParent(u);
            int ulpt_v = findUltParent(v);

            if(ulpt_v == ulpt_u) return;

            if(size[ulpt_u] > size[ulpt_v]){
                parent[ulpt_v] = ulpt_u;
                size[ulpt_u] += size[ulpt_v];
            }
            else{
                parent[ulpt_u] = ulpt_v;
                size[ulpt_v] += size[ulpt_u];
            }
        }
};

int main(){

    DisjointSet ds(5);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    int u, v;
    cin>>u>>v;
    if(ds.findUltParent(u) == ds.findUltParent(v)){
        cout<<"Connected"<<endl;
    }
    else{
        cout<<"Not Connected"<<endl;
    }
    return 0;
}
