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
typedef unsigned int ui;

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	ui A[1000];
	ui B[1000];
	ui C[1000];
	ui D[1000];
	ui *P=new ui[(int)1e6];
	ui *Q=new ui[(int)1e6];
	for(int i0=0;i0<test;i0++){
		int n;
		ui Xor;
		in>>n;
		in>>Xor;
		for(int i=0;i<n;i++)
			in>>A[i];
		for(int i=0;i<n;i++)
			in>>B[i];
		for(int i=0;i<n;i++)
			in>>C[i];
		for(int i=0;i<n;i++)
			in>>D[i];
		int size=n*n;
		int k=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				P[k++]=A[i]^B[j];

		k=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				Q[k++]=C[i]^D[j]^Xor;

		sort(P,P+size);
		sort(Q,Q+size);

		lli count=0;
		int i=0,j=0;
		map<ui,int> m1;
		for(int i=0;i<size;i++){
			if(m1.find(P[i])!=m1.end())
				m1[P[i]]++;
			else
				m1[P[i]]=1;
		}

		for(int i=0;i<size;i++){
			if(m1.find(Q[i]) !=m1.end())
				count+=m1[Q[i]];
		}
		out<<"Case #"<<i0+1<<": "<<count<<endl;
		m1.clear();
	}
	in.close();
	out.close();
	return 0;
}
