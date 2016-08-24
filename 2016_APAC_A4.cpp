//variant of Knapsack

#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;++i)
#define fr(i,a,b) for(int i=a;i>=b;--i)
typedef long long int lli;
using namespace std;

lli m;
int n;
lli k[15];		//max possible level
lli l[15];		//current level
lli a[15][15];	//powers
lli c[15][15];	//costs
lli ans;

 
int main(){
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	in.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	in>>t;
	f(iter,1,t+1){
		ans=0;
		out<<"Case #"<<iter<<": ";
		in>>>m>>n;
		f(i,0,n){
			in>>k[i]>>l[i];
			f(j,0,k[i])
				in>>a[i][j];
			in>>c[i][0];
			lli temp;
			f(j,1,k[i]-1){
				in>>temp
				c[i][j]=c[i][j-1]+temp;
			}
		}
		out<<solve(0,0);
		out<<'\n';
	}
	return 0;
}