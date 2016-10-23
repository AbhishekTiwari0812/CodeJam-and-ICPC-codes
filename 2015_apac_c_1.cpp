#include <bits/stdc++.h>
#define f(i,a,b) for( int i = ( a ), __ = ( b ); i < __; ++i )
#define fr(i,b,a) for( int i = ( b ), __ = ( a ); i >= __; --i )
#define pb push_back
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
string h[300];
int n;

int count_mines(int i,int j){
	int count=0;
	f(x,i-1,i+2)
	f(y,j-1,j+2)
	if(x >= 0 && x < n && y>=0 && y < n){
		if(h[x][y]=='*')
			count++;
	}
	return count;
}
void dfs_visit(int i,int j){
	int old=h[i][j];
	h[i][j]=127;
	if(old!=0)
        return;
	f(x,i-1,i+2)
		f(y,j-1,j+2)
			if(x >= 0 && x < n && y>=0 && y < n)
					if(h[x][y]!=127 && h[x][y] != '*')
						dfs_visit(x,y);
}

void dfs(){
	int component=0;
	f(i,0,n)
		f(j,0,n)
			if(h[i][j]==0){
				dfs_visit(i,j);
				component++;
			}

	f(i,0,n)
		f(j,0,n)
			if(h[i][j]!=127 && h[i][j]!='*')
                    component++;
	out<<component;

}

void solve(){
	f(i,0,n){
		f(j,0,n){
			if(h[i][j]=='.'){
				h[i][j]=count_mines(i,j);
				cout<<(int)h[i][j];
			}
			else cout<<(char)h[i][j];
		}
		cout<<endl;
	}
	dfs();
}

int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	f(i0,0,test){
		out<<"Case #"<<i0+1<<": ";
		in>>n;
		f(i,0,n)
			in>>h[i];
		solve();
		out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}
