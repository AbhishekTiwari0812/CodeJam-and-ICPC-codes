#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	int t;
	in>>t;
	string s;
	char ans[50000];

	for(int iter=1;iter<=t;iter++){
		out<<"Case #"<<iter<<": ";
		int n;
		in>>s;
		int start=2000;
		int end =2000;
		ans[start]=s[0];
		for(int i=1;i<s.length();i++){
			if(s[i]  >= ans[start]){
				start--;
				ans[start]=s[i];
			}
			else {
				end++;
				ans[end]=s[i];
			}
		}
		for(int i=start;i<=end;i++)
			out<<ans[i];
		out<<endl;
	}
}
