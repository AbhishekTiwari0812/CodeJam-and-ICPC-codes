#include <algorithm>
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
	int A[2501];
	for(int iter=1;iter<=t;iter++){
		out<<"Case #"<<iter<<": ";
		int n;
		in>>n;
		for(int i=0;i<2501;i++){
			A[i]=0;
		}
		int temp;
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				in>>temp;
				A[temp]++;
			}
		}
		vector<int> ans;
		for(int i=0;i<2501;i++){
			if(A[i]!=0){
				if(A[i]&1)
					ans.push_back(i);
			}
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)
			out<<ans[i]<<" ";
		out<<endl;
	}
}
