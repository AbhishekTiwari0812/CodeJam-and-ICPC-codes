#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct node{
	int id;
	int visited;
	node *next;
};

node **G;
int HELPER;
int length(node *current){
	if(current->next->visited==HELPER)
		return 1;
	current->visited=HELPER;
	return 1+length(current->next);

}
int main(){
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	int t;
	in>>t;
	for(int iter=1;iter<=t;iter++){
		HELPER=0;
		out<<"Case #"<<iter<<": ";
		int n;
		in>>n;
		G=new node*[n];
		for(int i=0;i<n;i++){
		    G[i]=new node;
            G[i]->id=i+1;
			G[i]->visited=-1;
		}
		int temp;
		for(int i=0;i<n;i++){
			in>>temp;
			temp--;
			G[i]->next=G[temp];
		}
		int max=-1;
		for(int i=0;i<n;i++){
			if(G[i]->visited==-1){
				HELPER++;
				temp=length(G[i]);
				if(temp > max)
					max=temp;
			}
		}
		out<<max<<endl;
	}
}
