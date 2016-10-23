#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
vector<pair<ll,int> >facts;
ll n;
void cal_primes(ll n){
	int count;
	f(i,2,(int)sqrt(n)+1){
		count=0;
		while(n%i==0){
			n/=i;
			count++;
		}
		if(count)
			facts.pb(mp(i,count));
	}
	if(n!=1)
		facts.pb(mp(n,1));
}

bool isprime(int n) {
    if(n==2)return true;
	for(int i=2;i<=sqrt(n);i++) {
		if(n%i==0)return false;
	}
	return true;
}
ll Pow(ll a, ll b){
    if(b==0)
        return 1;
    else{
        ll p = Pow(a,b/2);
        if(b%2==1)
            return p*p*a;
        else return p*p;
    }
}

map<int,ll> m;
bool isg(int mask){
	ll temp_n=n;
	for(int i=0;i<facts.size();i++) {
		if((1<<i)&mask){
				temp_n/=(ll)Pow(facts[i].first,facts[i].second);
		}
	}

	int sum=0;
	while(temp_n>0){
		int r=temp_n%10;
		sum+=r;
		temp_n/=10;
	}
	if(temp_n==1)return true;
	return isprime(sum);
}
int memo[2049];
void init(){
	f(i,0,2049){
		memo[i]=-1;
	}
}
bool dp(int mask){
	if(mask==((1<<facts.size())-1))return false;
	if(memo[mask]!=-1)return memo[mask];
	if(isg(mask))return false;
	else{
		bool val=false;
		for(int i=0;i<facts.size();i++){
			if((1<<i)&mask){
                continue;
			}
			val|=!dp(mask|(1<<i));
			if(val)
				break;
		}
		memo[mask]=val;
		return val;
	}
}

int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	f(i0,0,test){
		init();
		out<<"Case #"<<i0+1<<": ";
		in>>n;
		cal_primes(n);
		if(dp(0))out<<"Laurence"<<endl;
		else out<<"Seymour"<<endl;
		facts.clear();
		//out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}
