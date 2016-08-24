#include <bits/stdc++.h>
#define f(i,a,b) for( int i = a; i < b; ++i )
#define fr(i,a,b) for( int i = a; i >= b; --i )
using namespace std;
typedef double ld;
ofstream out;
ld Pw( ld a, int n ){
	if(n==0)
		return 1.00000000000;
	ld b = Pw( a, n/2 );
	if(n&1)
		return b*b*a;
	else
		return b*b;
}


ld EPS = 0.00000000001;
ld x[102];
int m;

ld eval(ld xx){
	ld ans= -1.00000000000*Pw(1+xx,m)*x[0];
	f(i,1,m+1)
		ans += Pw(1+xx,m-i)*x[i];
	return ans>0.0;
}

ld solve(ld l, ld r){
	ld mid = (l+r)/2.00000000000;
	if(r-l < EPS)
		return mid;
    bool flag = eval(l);
    bool grtr = eval(mid);    //greater than zero then true
    if(flag^grtr)
	   	return solve(l,mid);
    else return solve(mid,r);
}

int main(){
	ifstream in;
	in.open("in.txt");
	out.open("out.txt");
	int t;
	in>>t;
	f(iter,1,t+1){
		out<<"Case #"<<iter<<": ";
		in>>m;
		f(i,0,m+1)
			in>>x[i];
		out << setprecision(1)3;
		out<<(solve(-1.00000000,1.000000000));
		out<<'\n';
	}
	return 0;
}
