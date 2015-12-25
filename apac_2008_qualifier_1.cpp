//greedy approach...
//choose the one which comes latest in the query stream.
#include <iostream>
#include <fstream>
#include <vector>
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

vector<bool> get_all_zero(int size){
	vector<bool> v(size,false);
	return v;
}

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	int s,q;
	map<string,int> servers;
	string *queries;
	string server,query;
	vector<bool>mask;
	for(int i0=0;i0<test;i0++){
		in>>s;
		//cout<<"S"<<s<<endl;
		getline(in,server);
		for(int i=0;i<s;i++){
			getline(in,server);
			//cout<<server<<endl;
			servers[server]=i;
		}
		mask=get_all_zero(s);
		int switches=0;
		int count=0;
		in>>q;
		//cout<<"Q:"<<q<<endl;
		getline(in,query);
		for(int i=0;i<q;i++){
			getline(in,query);
			//cout<<"q:"<<query<<endl;
			if(servers.find(query)==servers.end()){
				//cout<<"Not a server"<<endl;
				continue;
			}
			else{
				if(mask[servers[query]]){
					//cout<<"Server. Already rejected"<<endl;
					continue;
				}
				else{
					//cout<<"Server.Rejecting server"<<endl;
					mask[servers[query]]=true;
					count++;
					if(count==s){
						//cout<<"All servers rejected, need a switch"<<endl;
						switches+=1;
						count=1;
						mask=get_all_zero(s);
						mask[servers[query]]=true;
					}
				}
			}
		}

		out<<"Case #"<<i0+1<<": "<<switches<<endl;
	}

	in.close();
	out.close();
	return 0;
}
