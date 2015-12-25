#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    int value;
    vector< struct node *> nbd;

}node;

typedef struct point_pair{
    int start_point;
    int end_point;
    vector<node *> path_points;
}point_pair;

node **G;

int main(){
    int test;
    cin>>test;
    int n;
    int a,b;
    int m;
    point_pair *A;
    for(int i=0;i<test;i++){
        cin>>n;
        G=new node*[n];
        for(int j=0;j<n;j++){
            G[i]=new node;
            G[i]->value=j+1;
        }
        for(int j=0;j<n-1;j++){
            cin>>a>>b;
            a-=1;
            b-=1;
            G[a]->nbd.push_back(G[b]);
            G[b]->nbd.push_back(G[a]);
        }
        cin>>m;
        A=new point_pair[m];
        for(int j=0;j<m;j++){
            cin>>a>>b;
            a-=1;
            b-=1;
            A[j].start_point=a;
            A[j].end_point=b;
        }
        //find k disjoints paths
    }

    return 0;
}
