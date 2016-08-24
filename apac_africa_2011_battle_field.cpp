#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;
typedef long double ld;

struct node{
	bool visited;
	vector<node *>nbd;
};

node **G;

int dfs_visit(node *current){
	current->visited=true;
	int count=current->nbd.size()%2;
	for(int i=0;i<current->nbd.size();i++){
		if(current->nbd[i]->visited!=true){
			count+=dfs_visit(current->nbd[i]);
		}
	}
	return count;
}

long long int DFS(int size){
	long long int EDGES_NEEDED=0;
	int components=0;
	int odd_degree_vertices;
	for(int i=0;i<size;i++){
		if(G[i]->nbd.size() > 0)
		if(G[i]->visited!=true){
			components++;
			odd_degree_vertices=dfs_visit(G[i]);
			if(odd_degree_vertices > 0)
				EDGES_NEEDED+=((odd_degree_vertices/2)-1);
		}
	}
    if(components ==1  && odd_degree_vertices == 0);
    else EDGES_NEEDED+=components;
	return EDGES_NEEDED;
}

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	int size;
	for(int i0=0;i0<test;i0++){
		in>>size;
		G=new node*[size];
		for(int i=0;i<size;i++){
			G[i]=new node;
			G[i]->visited=false;
		}
		int a,b;
		int edges;
		in>>edges;
		for(int i=0;i<edges;i++){
			in>>a>>b;
			G[a]->nbd.push_back(G[b]);
			G[b]->nbd.push_back(G[a]);
		}

		out<<"Case #"<<i0+1<<": "<<DFS(size)<<endl;
	}

	in.close();
	out.close();
	return 0;
}
