#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <set>
#include <cmath>
using namespace std;
typedef long long int lli;


long int visit;

typedef struct node{
	int x;
	int y;
	int visited;
	int value;
	struct node *neighbours;
}node;
node ***G;
int R,C;



vector<node *> getNeighbours(node *current){
	vector<node *>output;
	if(current->x>0)
		if(G[current->x-1][current->y]->value==1)
			output.push_back(G[current->x-1][current->y]);
	
	if(current->y >0)
		if(G[current->x][current->y-1]->value==1)
			output.push_back(G[current->x][current->y-1]);
	if(current->x<R-1)
		if(G[current->x+1][current->y]->value==1)
			output.push_back(G[current->x+1][current->y]);
	if(current->y<C-1)
		if(G[current->x][current->y+1]->value==1)
			output.push_back(G[current->x][current->y+1]);
	return output;
}




void dfs_visit(node *root){
	////cout<<"Point::"<<root->x<<" "<<root->y<<endl;
	vector<node *> v=getNeighbours(root);
	for(int i=0;i<v.size();i++){
		if(G[v[i]->x][v[i]->y]->visited!=visit){
			G[v[i]->x][v[i]->y]->visited=visit;
			dfs_visit(G[v[i]->x][v[i]->y]);
		}
	}
}
int components;
void DFS(){
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			if(G[i][j]->value==1 && G[i][j]->visited != visit){
				components+=1;
			//	//cout<<"DFS Point::"<<G[i][j]->x<<" "<<G[i][j]->y<<endl;
				G[i][j]->visited=visit;
				dfs_visit(G[i][j]);
			}
		}
	
}



int main(){
	ifstream in;
	ofstream out;
	in.open("A-large.in");
	out.open("output.out");
	int test;
	int x,y;
	char type;
	in>>test;
	char some_char;
	int queries;
	int z;
	for(int some=0;some<test;some++){
		visit=1;
		out<<"Case #"<<(some+1)<<":"<<endl;
		in>>R>>C;
		G=new node**[R];
		for(int i=0;i<R;i++){
			G[i]=new node*[C];
			for(int j=0;j<C;j++){
				G[i][j]=new node;
				G[i][j]->visited=-1;
				in>>some_char;
				some_char=some_char-'0';
				G[i][j]->x=i;
				G[i][j]->y=j;
				G[i][j]->value=(int)some_char;				
			}
		}
		components=0;
		vector<node *> helper;
		in>>queries;
		DFS();
		for(int i=0;i<queries;i++){
			in>>type;
			if(type=='Q'){
				out<<components<<endl;
			}
			
			else if(type=='M'){
				in>>x>>y>>z;
				if(G[x][y]->value==z)
					continue;
				helper= getNeighbours(G[x][y]);
				if(helper.size()==0){
					if(z==1 && G[x][y]->value!=1){
						components+=1;
						G[x][y]->value=1;
					}				
					else if(z==0 && G[x][y]->value!=0){
						components-=1;
						G[x][y]->value=0;
					}
				}
				else if(helper.size()==1){
					G[x][y]->value=z;
				}
				else if(helper.size()>1){
					if(G[x][y]->value!=z){
						G[x][y]->value=z;
						visit+=1;
						components=0;
						DFS();
					}
					else continue;
				}
			}		
		}











	}
	in.close();
	out.close();
	return 0;
}