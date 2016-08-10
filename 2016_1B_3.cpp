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

int n;
int main(){
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	for(int i0=0;i0<test;i0++){
		set<string >A;
		set<string >B;
		set<string >C;
		A.clear();
		B.clear();
		C.clear();
		string s1,s2,s3;
		long count=0;
		in>>n;
		string *a=new string[n];
		string *b=new string[n];
		for(int i=0;i<n;i++){
			in>>s1>>s2;
			A.insert(s1);
			a[i]=s1;
			b[i]=s2;
			B.insert(s2);
			C.insert(s1+" "+s2);
		}
		for(int i=0;i<n;i++){
			if(A.find(a[i])!=A.end() && B.find(b[i])!=B.end() && C.find(a[i]+" "+b[i])==C.end())
				count++;
		}
		out<<"Case #"<<i0+1<<": "<<count<<endl;
	}

	in.close();
	out.close();
	return 0;
}
