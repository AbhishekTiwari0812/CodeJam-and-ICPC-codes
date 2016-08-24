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
#define f(i,a,b) for( int i = ( a ), __ = ( b ); i < __; ++i )
#define fr(i,b,a) for( int i = ( b ), __ = ( a ); i >= __; --i )
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef map<int,int> mii;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<ll,ll> mll;
typedef map<ll,string> mls;
typedef map<string,ll> msl;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sll;
typedef set<ld> sld;
typedef pair<int,int> ii;

ifstream in;
ofstream out;

bool cmp(node *a,node *b){
	return a->id < b->id;
}

struct node{
	string id;
	map<node *,int,cmp> nbd;
	int id;
	bool pending;
};

map<string,node *> g;
map<string, node *>::iterator it1;
map<string, node *>::iterator it2;

int BFS(string start,string end){
	it1 = g.find(start);
	if(it1 == g.end())
		return INT_MAX;
	it2 = g.find(end);
	if( it2 == g.end() )
		return INT_MAX;
	queue<node *> q;
	q.push(it1->second);
	while(!q.empty()){
		node *current = q.front();
		for(map<node *,int,cmp>::){
			if()
		}
	}

}
int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	string line;
	string node1_id;
	string node2_id;
	ss nodes_present;
	int cost;
	f(i0,0,test){
		out<<"Case #"<<i0+1<<": ";
		int n;
		in>>n;
		f(i,0,n){
			getline(in,line);
			cout<<line<<endl;
			node1_id="";
			char c=line[0];
			int j=0;
			while(c!='+'){
				node1_id+=c;
				c=line[++j];
			}
			c=line[++j];
			node2_id="";
			while(c!='='){
				node2_id+=c;
				c=line[++j];
			}

			cost=0;
			++j;
			while(j<line.length()){
				cost=cost*10+line[j]-'0';
				++j;
			}
			cout<<"Node 1:"<<node1_id<<" node 2:"<<node2_id<<" cost:"<<cost<<endl;
			
			node *node1;
			node *node2;
			if(g.find(node1_id)==g.end()){
				node1 = new node;
				node1->pending=true;
				node1->id = node1_id;
				g[node1_id]=node1;
			}
			else node1=g[node1_id];
			if(nodes_present.find(node2_id)==nodes_present.end()){
				node2 = new node;
				node2->id = node2_id;
				node2->pending=true;
				g[node2_id]=node2;
			}
			else node2=g[node2_id];
			node1[node2]=cost;
			node2[node1]=cost;
		}

		int q;
		in>>q;
		f(i,0,q){
			getline(in,line);
			cout<<"Line:"<<line<<endl;
			node1_id="";
			char c=line[0];
			int j=0;
			while(c!='+'){
				node1_id+=c;
				c=line[++j];
			}
			j++;
			while(j < line.length()){
				node2_id+=line[j++];
			}
			cout<<BFS(node1_id,node2_id);
		}
		out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}
