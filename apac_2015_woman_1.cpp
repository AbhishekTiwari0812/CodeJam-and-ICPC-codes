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


int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	char c;
	string temp;
	int n;
	for(int i0=0;i0<test;i0++){
		in>>n;
		string answer="";
		for(int i=0;i<n;i++){
			temp="";
			for(int j=0;j<8;j++){
				in>>c;
				temp+=c;
			}
			int t=0;
			int k;
			int pow=1;
			for(int j=7;j>=0;j--){
				k=temp[j]=='O'?0:1;
				t+=pow*k;
				pow*=2;
			}
			answer+=(char)t;
		}

		out<<"Case #"<<i0+1<<": "<< answer<<endl;
    }


	in.close();
	out.close();
	return 0;
}
