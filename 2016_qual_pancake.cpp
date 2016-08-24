#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lli;
int l;

void swap(char &a,char &b){
	char temp=a;
	a=b;
	b=temp;
}
lli count(string s){
	//cout<<s<<endl;
	int index;
	if(s[0]=='+'){
		index=0;
		while(index < l){
			if(s[index]=='+'){
				s[index]='-';
				index++;
			}
			else break;
		}
		if(index==l)
			return 0;
		else
		return 1+count(s);
	}
	else{
		index=l-1;
		while(index >=0){
			if(s[index]=='+')
				index--;
            else break;
		}
		if(index==-1)
			return 0;
		for(int i=0;i<=index;i++){
			if(s[i]=='-')
				s[i]='+';
			else s[i]='-';
		}
		for(int i=0;i<=(index/2);i++){
			swap(s[i],s[index-i]);
		}
		return 1+count(s);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	ifstream in;
	in.open("in.txt");
	ofstream out;
	out.open("out.txt");
	int t;
	in>>t;
	string s;
	for(int i=1;i<=t;i++){
		out<<"Case #"<<i<<": ";
		in>>s;
		l=s.length();
		out<<count(s)<<endl;
	}
	return 0;
}
