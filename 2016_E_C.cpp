//incomplete 
//USE DP to solve
//double DP[n][1][1];

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

double p1,p2,p3;

/* 
 * input bit = bit1 
 * number given bit = bit2
*/
double find( int n , int b1 , int b2 ){
	if( n == 0)
		return 1;		//this probably won't work!
}

int main(){
	ifstream in;
	ofstream out;
	in.open( "input.txt" );
	out.open( "output.txt" );
	int test;
	in >> test;
	double * A = new double [64];
	for( int i0 = 0; i0 < test; i0++ ){
		int n,x,k;
		in >> n >> x >> k ;
		cin >> p1 >> p2 >> p3;
		a*=100.0;
		b*=100.0;
		c*=100.0;
		for( int i = 0; i < 32; i++ ){
			int bit1 = x & 1;
			x = ( x >> 1 );
			int bit2 = ( k & 1 );
			k = (k >> 1);
			A[i] = find ( n , bit1 , bit2 );

		}
		cout << "Case #" << ( i0 + 1 ) <<": " << << endl;
	}

	in.close();
	out.close();
	return 0;
}
