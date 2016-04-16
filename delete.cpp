#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lli;
int l;

bool check_prime(int n){
	if(n==2)
		return true;
	for(int i=2;i<=ceil(sqrt(n));i++)
		if(n%i==0)
			return false;
	return true;
}

int main(){
	ofstream out;
	int count=0;
	out.open("p.txt");
	for(int i=2;i<1025;i++){
		if(check_prime(i)){
			out<<i<<",";
			count++;
		}
	}
	cout<<count<<endl;
}
