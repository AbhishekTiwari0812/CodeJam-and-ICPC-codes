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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pii> vii;

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

ifstream in;
ofstream out;
int n;	//number of cards
ll a[14][13];	//card i level j power
int k[15];	//max level cap of each card.
ll m; //coins
ll c[14][13];  //cost card i from j to j+1:c[i][j]
int l[15]; //current level of the card
vector<pair<ll,ll> > vpll;
map<pair<ll,int>, ll> hash_table;

ll knapsack(ll coins,int index){
	if(coins == 0)
		return 0;
	else if(coins < 0 || index >= vpll.size() )
		return LONG_MIN;
	else{
		pair<ll,int> temp;
		if(hash_table.find(temp) != hash_table.end())
			return hash_table[temp];
		ll a = knapsack(coins - vpll[index].first , index+1) + vpll[index].second;
		ll b = knapsack(coins,index+1);
		hash_table[temp] = a>b?a:b;
		return a>b?a:b;
	}
}

void solve(){
	f(i,0,n)
		f(j,l[i],k[i]+1)
			vpll.push_back(make_pair(c[i][j],a[i][j+1]));
	ll ans=knapsack(0,0,0,0);
					//coins, index of card, level of card, count of cards
	out<<ans;
}

int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	f(i0,0,test){
		hash_table.clear();
		vpll.clear();
		out<<"Case #"<<i0+1<<": ";
		in>>m>>n;
		f(i,0,n){
			in>>k[i]>>l[i];
			f(j,0,k[i])
				in>>a[i][j];
			f(j,0,k[i]-1)
				in>>c[i][j];
		}
		solve();
		out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}
