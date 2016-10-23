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


int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	f(i0,0,test){
		out<<"Case #"<<i0+1<<": ";
		
		out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}
