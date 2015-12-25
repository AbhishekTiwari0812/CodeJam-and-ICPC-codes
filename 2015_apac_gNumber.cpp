#include <iostream>
#include <fstream>
#include <vector>
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

bool isPrime(lli a){
	return (primes.find(a)==primes.end());
}
bool is_gNumber(lli a){
	int k=0;
	while(a > 0){
		k+=a%10;
		a/=10;
	}
	return isPrime(k);
}

void remove_factor(lli & a,lli prime){
	while(a%prime==0)
		a/=prime;
}
int find_winner(lli a){
	int count=0;
	for (set<int>::iterator i = primes.begin(); (*i) <= sqrt(a)+1;i++)
			if(a%(*i))==0){
				count++;
			
			}
	return count;

}


int main(){
	ifstream in;
	ofstream out;
	set<lli> primes();
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	for(int i0=0;i0<test;i0++){



		cout<<"Case #"<<i0+1<<": "<< /*****VALUE HERE***/<<endl;		
	}	

	in.close();
	out.close();
	return 0;
}
