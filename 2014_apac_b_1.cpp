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
#define MOD (int)(1e9+7)
ifstream in;
ofstream out;
ll dp[103][103];

ll fx( ll n,ll m ){
	f(i,0,n+1)
		dp[i][0] = 0;
	f(j,0,m+1)
		dp[0][j] = 0;
	dp[0][0]=1;
	f(i,1,n+1)
		f(j,1,m+1)
			dp[i][j] = ( j * ( dp[i-1][j] + dp[i-1][j-1] ) ) % MOD;
	return dp[n][m];
}

int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	ll m,n;
	f(i0,0,test){
		out<<"Case #"<<i0+1<<": ";
		in>>m>>n;
		out<<(fx(n,m));
		out<<'\n';
	}
	in.close();
	out.close();
	return 0;
}
