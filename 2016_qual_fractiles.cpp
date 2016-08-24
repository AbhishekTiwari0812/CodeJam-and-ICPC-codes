#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lli;
int l;



int main(){
	ios_base::sync_with_stdio(false);
	ifstream in;
	in.open("in.txt");
	ofstream out;
	out.open("out.txt");
	int t;
	in>>t;
	for(int i=1;i<=t;i++){
		out<<"Case #"<<i<<": ";
		lli k,c,s;
		in>>k>>c>>s;
		if(c==1){
			if(s<k)
				out<<"IMPOSSIBLE"<<endl;
			else{
				for(int j=1;j<=s;j++)
					out<<i<<" ";
				out<<endl;
			}
		}
		else{
			if(s<k-1)
				out<<"IMPOSSIBLE"<<endl;
			else{
				for(int j=2;j<=s+1;j++)
					out<<i<<" ";
				out<<endl;
			}	
		}
	}
	return 0;
}
