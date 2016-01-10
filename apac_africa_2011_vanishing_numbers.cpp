#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;
typedef long double ld;

struct num{
	ld value;
	lli level;
};

bool comp(num *a,num *b){
	if(a->level==b->level)
		return a->value < b->value;
	else return a->level < b->level;
}

lli find_level(ld &left,ld &right,ld &num){
    ld one=left+((right-left)/3.0);
    ld two=right-((right-left)/3.0);
    lli a;
    if( num >= one && num <= two)
        return 1;
    else if(num > left && num < one)
        a=find_level(left,one,num);
    else a=find_level(two,right,num);
    return 1+a;

}

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	int n;
	ld left=0.0l;
	ld right=1.0l;
	num **N;
	for(int i0=0;i0<test;i0++){
		in>>n;
		N=new num*[n];
		ld temp;
		for(int i=0;i<n;i++){
			in>>temp;
			N[i]=new num;
			N[i]->value=temp;
			if(temp > 1 || temp < 0 ){
                cout<<"wrong input"<<endl;
                continue;
			}
			N[i]->level=find_level(left,right,temp);
			//cout<<"Num:"<<N[i]->value<<" Level:"<<N[i]->level<<endl;
		}

		sort(N,N+n,comp);
		out<<"Case #"<<i0+1<<":"<<endl;
		for(int i=0;i<n;i++)
			out<<setprecision(12)<<N[i]->value<<endl;

	}
	in.close();
	out.close();
	return 0;
}
