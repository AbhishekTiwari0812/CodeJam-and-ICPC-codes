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

struct party{
	int index;
	int count;
};

bool cmp(party p1,party p2){
	return p1.count < p2.count;
}

party P[26];		//parties.
int n;			//size
void solve(){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=P[i].count;
	party temp;
	int last=n-1;
	while(sum > 0){
		sort(P,P+n,cmp);
		temp=P[last];
		int new_sum=sum-1;
		if(P[last-1].count > (int)ceil(new_sum/2) ){
			out <<(char) ('A'+P[last].index) << (char)('A'+P[last-1].index)<<" ";
			sum-=2;
			P[last-1].count-=1;
		}
		else{
			out << (char)('A'+P[last].index) <<" ";
			sum-=1;
		}
		P[last].count-=1;
	}
	out<<endl;
}
int main(){
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("output.txt");
	int test;
	in>>test;
	for(int i0=0;i0<test;i0++){
		out<<"Case #"<<(i0+1)<<": ";
		in>>n;
		int temp;
		for(int i=0;i<n;i++){
			in>>temp;
			P[i].index=i;
			P[i].count=temp;
		}
		solve();
	}
	in.close();
	out.close();
	return 0;
}
