#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
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
	int size;
	lli *v1;
	lli *v2;
	for(int i0=0;i0<test;i0++){
		in>>size;
		v1=new lli[size];
		v2=new lli[size];
		for(int i=0;i<size;i++){
			in>>v1[i];
		}
		for(int i=0;i<size;i++){
			in>>v2[i];
		}
		sort(v1,v1+size);
		sort(v2,v2+size);
		long long int mul=0;
		for(int i=0;i<size;i++){
			mul+=v1[i]*v2[size-i-1];
		}
		out<<"Case #"<<i0+1<<": "<< mul<<endl;
	}

	in.close();
	out.close();
	return 0;
}
