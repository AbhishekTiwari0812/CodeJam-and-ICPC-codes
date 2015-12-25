#include <iostream>
using namespace std;
typedef struct node{
    vector<struct node*>nbd;
    bool visited;
}node;
node **G;

void dfs_visit(node *c){
    c->visited=true;
    for(int i=0;i<c->nbd.size();i++)
        if(c->nbd[i]->visited!=true)
            dfs_visit(c->nbd[i]);

}

int DFS(int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(G[i]->visited!=true){
            dfs_visit(G[i]);
            count++;
        }
    }
    return count;
}

int main(){
 int test;
 cin>>test;
 for(int some=0;some<test;some++){
    int n;
    cin>>n;
    G=new node*[n];
    for(int i=0;i<n;i++){
        G[i]=new node;
        G[i]->visited=false;
    }
    int edges;
    cin>>edges;
    int a,b;
    for(int i=0;i<edges;i++){
        cin>>a>>b;
        G[a]->nbd.push_back(G[b]);
        G[b]->nbd.push_back(G[a]);

    }
    cout<<DFS(n)<<endl;

 }


}
