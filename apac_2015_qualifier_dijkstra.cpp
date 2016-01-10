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

int Table[4][4]={{1,'i','j','k'},{'i',-1,'k',-'j'},{'j',-'k',-1,'i'},{'k','j',-'i',-1}};
int mul(int value,int p){
        //cout<<"multiplying:"<<value<<","<<p<<endl;
		int i;
		int j;
		int sign1=p>0?1:-1;
		p=p*sign1;
		int sign2=value>0?1:-1;
		value=value*sign2;
		if(value==1)
			i=0;
		else if(value == 'i')
			i=1;
		else if(value == 'j')
			i=2;
		else if(value == 'k')
			i=3;
		if(p==1)
			j=0;
		else if(p == 'i')
			j=1;
		else if(p == 'j')
			j=2;
		else if(p == 'k')
			j=3;
     //   cout<<"i:"<<i<<" j:"<<j<<" "<<Table[i][j]<<endl;
		return sign1*sign2*Table[i][j];
}
int mPow(int a,int x){
    //    cout<<"a:"<<a<<" x:"<<x<<endl;
		if(x==0){
			return 1;
		}
		int b=mPow(a,x/2);
        b=mul(b,b);
		if(x%2==1)
			b=mul(a,b);
	//	cout<<"returning b:"<<b<<endl;
		return b;
}

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	long long int test;
	in>>test;
	long long int l,x;
	char s;
	cout<<mPow('i',7)<<endl;
	for(long long int i0=0;i0<test;i0++){
        cout<<"case:"<<i0+1<<endl;
		in>>l>>x;
        //cout<<"l:"<<l<< " "<<x<<endl;
        int temp=1;
		for(long long int i=0;i<l;i++){
            in>>s;
			temp=mul(temp,s);
		}
        cout<<temp<<endl;
		int a;
		cout<<"x:"<<x<<endl;
		x=x%4;
        if(x==0)
            temp=1;
        else if(x==1);
        else if(x==2)temp=mul(temp,temp);
        else if(x==3){
            temp=mul(temp,temp);
            temp=mul(temp,temp);
        }
        int something=1;
        for(int i=0;i<6898;i++){
            something=mul(something,'k');
        }
        cout<<"something:"<<something<<endl;
		if(temp==-1)
		out<<"Case #"<<i0+1<<": YES"<<endl;
		else out<<"Case #"<<i0+1<<": NO"<<endl;
	}

	in.close();
	out.close();
	return 0;
}
