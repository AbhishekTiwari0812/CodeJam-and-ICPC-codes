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

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ifstream in;
ofstream out;
ll b,m;
struct p1{
	int x;
	int y;
	int z;
	p1(int x,int y,int z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
struct p2{
	int x;
	int y;
	p2(int x,int y){
		this->x = x;
		this->y = y;
	}
};

class cmp1{
public:
	bool operator()(const p1 & a, const p1 &b)const{
		long x1=a.x * 10000 + a.y * 100 + a.z;
		long x2=b.x * 10000 + b.y * 100 + b.z;
		return x1 < x2;
	}
};

class cmp2{
public:
	bool operator()(const p2 &a,const p2 &b)const{
		long x1 = a.x * 100 + a.y;
		long x2 = b.x * 100 + b.y;
		return x1 < x2;
	}
};

void pm(map<p2,int,cmp2> m){
	cout<<"==============="<<endl;
	for(map<p2,int,cmp2>::iterator it=m.begin();it!=m.end();it++){
		cout<<"("<<(it->first.x)<<","<<(it->first.y)<<")"<<"="<<(it->second)<<endl;
	}
}

void solve(int j,int p,int s,int k){
	set<p1,cmp1> s1;

	map<p2,int,cmp2> m2;

	map<p2,int,cmp2>::iterator it1;
	map<p2,int,cmp2>::iterator it2;
	map<p2,int,cmp2>::iterator it3;

	p1 temp1(0,0,0);

	p2 temp2(0,0);
	p2 temp3(0,0);
	p2 temp4(0,0);

	int count=0;
	for( int x = 1; x <= j; x++ ) {
		for( int y = 1; y <= p ; y++ ) {
			for( int z = 1; z <= s; z++ ) {
				//cout<<"for ("<<x<<","<<y<<","<<z<<"):";
				//pm(m2);
				temp1.x=x;
				temp1.y=y;
				temp1.z=z;

				temp2.x = x;
				temp2.y = y;
				it1 = m2.find( temp2 );
				if( it1 != m2.end() ) {
					if( it1->second == k )
						continue;
				}
				temp3.x = x;
				temp3.y = z;
				it2 = m2.find( temp3 );
				if(it2!=m2.end()){
					if(it2->second == k)
						continue;
				}
				temp4.x=y;
				temp4.y=z;
				it3=m2.find(temp4);
				if(it3!=m2.end()){
					if(it3->second == k)
						continue;
				}


				s1.insert(temp1);

				if(it1==m2.end())
					m2[temp2]=1;
				else
					it1->second++;

				if(it2==m2.end())
					m2[temp3]=1;
				else
					it2->second++;

				if(it3==m2.end())
					m2[temp4]=1;
				else
					it3->second++;

				count++;
			}
		}
	}
	out<<count<<endl;
	for(set<p1,cmp1>::iterator it=s1.begin();it!=s1.end();it++){
		out<<(it->x)<<" "<<(it->y)<<" "<<(it->z)<<endl;
	}

}
int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	for(int i0=0;i0<test;i0++){
        out<<"Case #"<<(i0+1)<<": ";
		int j,p,s,k;
		in>>j>>p>>s>>k;
		solve(j,p,s,k);
	}

	in.close();
	out.close();
	return 0;
}
