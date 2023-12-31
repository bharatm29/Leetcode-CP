#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
    private:
        vector<int> parent, size, rank;
    public:
        DisjointSet(const int sz){
            size.resize(sz + 1, 1);
            rank.resize(sz + 1);

            parent.resize(sz + 1);
            for(int i = 0; i <= sz; i++){
                parent[i] = i;
            }
        }

        int findUltParent(const int u){
            if(u == parent[u]){
                return u;
            }

            return parent[u] = findUltParent(parent[u]);
        }

        void unionBySize(const int u, const int v){
            const int ult_u = findUltParent(u);
            const int ult_v = findUltParent(v);

            if(ult_u == ult_v){
                return;
            }

            if(size[ult_u] > size[ult_v]){
                size[ult_u] += size[ult_v];
                parent[ult_v] = ult_u;
            }
            else{
                size[ult_v] += size[ult_u];
                parent[ult_u] = ult_v;
            }
        }

        void unionByRank(const int u, const int v){
            const int ult_u = findUltParent(u);
            const int ult_v = findUltParent(v);

            if(ult_u == ult_v){
                return;
            }

            if(rank[ult_u] > rank[ult_v]){
                parent[ult_v] = ult_u;
            }
            else if(rank[ult_v] > rank[ult_u]){
                parent[ult_u] = parent[ult_v];
            }
            else{
                rank[ult_v]++;
                parent[ult_u] = ult_v;
            }
        }
};

int main(){
    DisjointSet ds(5);
    ds.unionBySize(2, 3);
    ds.unionBySize(2, 1);
    ds.unionBySize(5, 4);
    if(ds.findUltParent(5) != ds.findUltParent(2)){
        cout<<"Not connected"<<endl;
    }
    return 0;
}
