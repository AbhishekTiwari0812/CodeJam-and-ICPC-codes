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
string MATCHER="welcome to code jam";
bool **LookUp;
lli **DP;
int size;
void count_chars(string s){
	char c;
	for(int i=0;i<MATCHER.length();i++){
		c=MATCHER[i];
		for(int j=0;j<s.length();j++)
			if(c==s[j])
				LookUp[i][j]=true;
	}
}

lli count_possible(int row,int column){
	lli answer=0;
	lli k;
	for(int i=column;i<size;i++){
		if(LookUp[row][i]){
                if(row+1==19)
                	answer+=1;
                else if(i+1==size);
                else{
                	if(DP[row+1][i+1]==-1){
                		k=count_possible(row+1,i+1);
                		DP[row+1][i+1]=k%10000;
                		answer=(answer+k)%10000;
                	}
                	else{
                		answer=(answer+DP[row+1][i+1])%10000;
                	}
                }
		}
    }
	return answer;
}
int main(){
	ifstream in;
	FILE *out;
	in.open("input.txt");
	out=fopen("output.txt","w");
	int test;
	in>>test;
	string s;
	getline(in,s);
	for(int i0=0;i0<test;i0++){
		getline(in,s);
		size=s.length();
    	LookUp=new bool*[19];
    	DP=new lli*[19];
    	for(int i=0;i<19;i++){
    		LookUp[i]=new bool[s.length()];
    		DP[i]=new lli[s.length()];
    		for(int j=0;j<s.length();j++){
    			LookUp[i][j]=false;
    			DP[i][j]=-1;
    		}
    	}
        count_chars(s);
		fprintf(out,"Case #%d: %04d\n",i0+1,count_possible(0,0));
    }
	in.close();
	fclose(out);
	return 0;
}
