#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;
typedef long long int lli;
typedef struct node{
	string value;
	map<string,struct node*> neighbours;
}node;
node *root;
map<string,node *>::iterator helper;
vector<string> split_string(string v){
	string temp="";
	vector<string> t;
	for(int i=1;i<v.size();i++){
		if(v[i]!='/')
			temp.push_back(v[i]);
		else {
			t.push_back(temp);
			temp="";
		}
	}
	t.push_back(temp);
	return t;
}
node *check_existance(node *root,string neig){
	if((helper=root->neighbours.find(neig))==root->neighbours.end())
		return NULL;
	else return helper->second;
}
void create_child(node *root,vector<string> new_dirs,int index){
	for(int i=index;i<new_dirs.size();i++){
		node *A=new node;
		A->value=new_dirs[i];
		root->neighbours[A->value]=A;
		root=A;
	}
}
lli insert_nodes(string new_dir){
	node *current=root;	
	node *current1;
	vector<string> path=split_string(new_dir);
	for(int i=0;i<path.size();i++){
		if((current1=check_existance(current,path[i]))==NULL){
			create_child(current,path,i);
			return path.size()-i;
		}
		else current=current1;
	}
	return 0;
}
int main(){
	root =new node;
	root->value="/";
	int t,n,m;
	string temp;
	ifstream in;
	ofstream out;
	in.open("A-large-practice.in");
	out.open("output.out");
	long long int count;
	in>>t;
	for(int i=0;i<t;i++){
		root->neighbours.clear();
		in>>n>>m;
		for(int k=0;k<n;k++){
			in>>temp;
			count=insert_nodes(temp);
		}
		count=0;
		for(int k=0;k<m;k++){
			in>>temp;
			count+=insert_nodes(temp);
		}
		out<<"case #"<<(i+1)<<": "<<count<<endl;
	}
}