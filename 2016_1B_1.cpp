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
int *A;
int *n;
ofstream out;
void pa(int *n){
	for(int i=0;i<10;i++)
		for(int j=1;j<=n[i];j++)
			out<<i;
	out<<endl;
}
void count(string s){
	for(int i=0;i<10;i++)
		n[i]=0;
	for(int i=0;i<26;i++)
		A[i]=0;
	for(int i=0;i<s.length();i++){
		A[s[i]-'A']++;
	}
	n[0]=A[25];

	//zero
	if(n[0]!=0){
        A[25]-=n[0];
        A[4]-=n[0];
        A[17]-=n[0];
        A[14]-=n[0];
	}
	//out<<0<<endl;
    //pa(n);
	//two
	n[2]=A['W'-'A'];
	if(n[2]!=0){
	A['W'-'A']-=n[2];
	A['T'-'A']-=n[2];
	A['O'-'A']-=n[2];
	}
	//out<<2<<endl;
	//pa(n);

	//four

	n[4]=A['U'-'A'];
	if(n[4]!=0){
        A['U'-'A']-=n[4];
        A['F'-'A']-=n[4];
        A['O'-'A']-=n[4];
        A['R'-'A']-=n[4];
	}
	//out<<4<<endl;
	//pa(n);
	//six
	n[6]=A['X'-'A'];
	if(n[6]!=0){
	A['X'-'A']-=n[6];
	A['S'-'A']-=n[6];
	A['I'-'A']-=n[6];
	}
	//out<<6<<endl;
	//pa(n);
	//eight
	n[8]=A['G'-'A'];
    if(n[8]!=0){
	A['G'-'A']-=n[8];
	A['E'-'A']-=n[8];
	A['I'-'A']-=n[8];
	A['H'-'A']-=n[8];
	A[19]-=n[8];
	}
    //out<<8<<endl;
	//pa(n);
	//seven

	n[7]=A[18];
	if(n[7]!=0){
	A[18]-=n[7];
	A[4]-=n[7];
	A[21]-=n[7];
	A[4]-=n[7];
	A[13]-=n[7];
	}
	//out<<7<<endl;
	//pa(n);
	//five
	n[5]=A[21];
	if(n[5]!=0){
	A[21]-=n[5];
	A[5]-=n[5];
	A[8]-=n[5];
	A[4]-=n[5];
	}
	//out<<5<<endl;
	//pa(n);
	//one

	n[1]=A[14];
	if(n[1]!=0){
	A[14]-=n[1];
	A[13]-=n[1];
	A[4]-=n[1];
	}
	//out<<1<<endl;
	//pa(n);
	//three
	n[3]=A[19];
	if(n[3]!=0){
	A[19]-=n[3];

	}
	//out<<3<<endl;
	//pa(n);
	n[9]=A[8];
	//out<<9<<endl;
	pa(n);
}
int main(){
	ifstream in;
	//ofstream out;
	in.open("in.txt");
	out.open("output.txt");
	int test;
	n=new int[10];
	A=new int[26];
	in>>test;
	for(int i0=0;i0<test;i0++){
		string s;
		in>>s;
		//out<<s;
		out<<"Case #"<<(i0+1)<<": ";
		count(s);

	}

	in.close();
	out.close();
	return 0;
}
