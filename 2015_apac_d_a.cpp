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

int dp[1001][1001];
int s[1001][1001];
int n;

int cal(int i,int j){
	int x;
	int y;
	int ans=0;
	int temp;
	x=i-1;
	y=j;
	if(x>=0 && x < n && y >=0 && y < n){
		if(s[x][y] == s[i][j]+1){
			if(dp[x][y]==-1){
				dp[x][y]=cal(x,y);
			}
			if(dp[x][y]+1 > ans)
				ans = dp[x][y]+1;
		}
	}

	x=i+1;
	y=j;

	if(x>=0 && x < n && y >=0 && y < n){
		if(s[x][y] == s[i][j]+1){
			if(dp[x][y]==-1){
				dp[x][y]=cal(x,y);
			}
			if(dp[x][y]+1 > ans)
				ans = dp[x][y]+1;
		}
	}
	x=i;
	y=j-1;
	if(x>=0 && x < n && y >=0 && y < n){
		if(s[x][y] == s[i][j]+1){
			if(dp[x][y]==-1){
				dp[x][y]=cal(x,y);
			}
			if(dp[x][y]+1 > ans)
				ans = dp[x][y]+1;
		}
	}
	x=i;
	y=j+1;
	if(x>=0 && x < n && y >=0 && y < n){
		if(s[x][y] == s[i][j]+1){
			if(dp[x][y]==-1){
				dp[x][y]=cal(x,y);
			}
			if(dp[x][y]+1 > ans)
				ans = dp[x][y]+1;
		}
	}
	return ans;
}

void solve(){
	f(i,0,n){
		f(j,0,n){
			if(dp[i][j]==-1){
				dp[i][j]=cal(i,j);
			}
		}
	}
	int max=INT_MIN;
	int num;
	f(i,0,n){
		f(j,0,n){
		    //cout<<dp[i][j]<<' ';
			if(dp[i][j] > max){
				num = s[i][j];
				max = dp[i][j];
			}
			else if(dp[i][j] == max){
                if(num > s[i][j])
                    num=s[i][j];
			}
		}
		//cout<<endl;
	}
	out<<num<<' '<<(max+1);
}

void init(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			dp[i][j]=-1;
	}
}


int main(){
	in.open("in.in");
	out.open("out.txt");
	int test;
	in>>test;
	f(i0,0,test){
		out<<"Case #"<<i0+1<<": ";
		in>>n;
		f(i,0,n)
		f(j,0,n)
			in>>s[i][j];
		init();
		solve();
		out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}
