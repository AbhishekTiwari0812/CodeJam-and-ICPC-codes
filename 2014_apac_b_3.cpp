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
	int n;
	vi a;
	vi b;
	f(i0,0,test){
		out<<"Case #"<<i0+1<<": ";
		a.clear();
		b.clear();
		in>>n;
		int k;
		in>>k;
		int temp;
		f(i,0,n){
			in>>temp;
			a.push_back(temp);
		}
		while(true){
			f(i,0,a.size()-2){
				if(a[i]!=-12)
				if(a[i]==a[i+1]-k && a[i+1]==a[i+2]-k){
					a[i]=-12;
					a[i+1]=-12;
					a[i+2]=-12;
				}
			}
			f(i,0,a.size())
				if(a[i]!=-12)
					b.push_back(a[i]);
			if(b.size()==a.size())
{				break;
			}
			else{a=b;b.clear();}

		}

		out<<a.size();
		out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}
