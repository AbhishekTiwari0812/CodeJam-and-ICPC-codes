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
	int x;
	int y;
	bool visited;
	lli value;
	char segment;
	vector<struct node *>nbd;
};
int h,w;
node ***G;
node *get_min_neighbour(int x,int y){
	vector<node *> v;
	if(y-1>=0)//north
		v.push_back(G[y-1][x]);
	if(x-1>=0 )//west
		v.push_back(G[y][x-1]);
	if(x+1 < w){//east{
		v.push_back(G[y][x+1]);
	}
	if(y+1 < h)//south
		v.push_back(G[y+1][x]);
	lli min=100000000000000;
	int index;
	for(int i=0;i<v.size();i++){
		if(v[i]->value < min){
			index=i;
			min=v[i]->value;
		}
	}
	if(G[y][x]->value > min)
		return v[index];
	else return G[y][x];

}
node *find_min_neighbouring(node *current){
	int x,y;
	node *north;
	node *answer;
	answer=get_min_neighbour(current->x,current->y); //j,i
	answer->nbd.push_back(current);
	return answer;
}

void dfs_visit(node *current,char c){
	current->visited=true;
	current->segment=c;
	for(int i=0;i<current->nbd.size();i++){
		if(!current->nbd[i]->visited){
			dfs_visit(current->nbd[i],c);
		}
	}
}
void DFS(){
	char c='a';
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			if(!G[i][j]->visited){
				dfs_visit(G[i][j],c);
				c++;
			}
		}
}
int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	int temp;
	for(int i0=0;i0<test;i0++){
		in>>h>>w;
		G=new node**[h];
		for(int i=0;i<h;i++){
			G[i]=new node*[w];
			for(int j=0;j<w;j++){
				in>>temp;
				G[i][j]=new node;
				G[i][j]->x=j;
				G[i][j]->y=i;
				G[i][j]->value=temp;
				G[i][j]->visited=false;
			}

		}
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				G[i][j]->nbd.push_back(find_min_neighbouring(G[i][j]));
			}
		DFS();
		out<<"Case #"<<i0+1<<":"<<endl;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				out<<G[i][j]->segment<<" ";
			}
			out<<endl;
		}
	}

	in.close();
	out.close();
	return 0;
}
