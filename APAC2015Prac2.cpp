#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define PI 3.14159265

using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;
typedef long double ld;


int main(){
	ifstream in;
	FILE *out;
	in.open("input.txt");
	out=fopen("output.txt","w");
	int test;
	in>>test;
	ld v,r;
	ld g=9.8000;
	ld theta;
	for(int i0=0;i0<test;i0++){
		in>>v>>r;
		theta=(180.0/PI)*(1.0/2.0)*asin((r*g)/(v*v));
		fprintf(out,"Case #%d: %.8LG\n",i0+1,theta);
	}
	in.close();
	fclose(out);
	return 0;
}
