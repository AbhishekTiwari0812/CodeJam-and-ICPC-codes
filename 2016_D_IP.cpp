#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	int t;
	in>>t;
	while(t--){
		int n;
		in>>n;
		string *A=new string[n];
		for(int i=0;i<n;i++)
			in>>A[i];
	}
}
