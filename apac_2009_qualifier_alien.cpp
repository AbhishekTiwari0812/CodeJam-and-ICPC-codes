//doesn't work for big input
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

vector<string> generate_possible(string current){
	vector<string> answer;
	int i=0;
	string temp;
    while(i<current.length()){
		string s1="";
		if(current[i]=='('){
			temp="";
			i+=1;
			while(current[i]!=')')
				temp+=current[i++];
			s1=temp;

		}
		else s1+=current[i];
		i++;
		answer.push_back(s1);
	}
	return answer;
}

struct mPattern{
	string pattern;
	set<string> s;
};
std::vector<string> current_pattern;
std::vector<string> all_strings;
int N,L,D;
void get_all_strings(int segment,string str){
	//cout<<"ehere";
	if(segment==L)
		all_strings.push_back(str);
	else
		for(int i=0;i<current_pattern[segment].length();i++)
			get_all_strings(segment+1,str+current_pattern[segment][i]);
}
void get_all_possible(vector<mPattern> &patterns){
    string a="";
	for(int i=0;i<patterns.size();i++){
		current_pattern=generate_possible(patterns[i].pattern);
		get_all_strings(0,"");
		for(int j=0;j<all_strings.size();j++)
			if(patterns[i].s.find(all_strings[j])==patterns[i].s.end())
				patterns[i].s.insert(all_strings[j]);
		all_strings.clear();
	}
}

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	test=1;
	vector<string> v;
	vector<mPattern> pattern;
	string s;
	map<string,int > m;
	for(int i0=0;i0<test;i0++){
		in>>L>>D>>N;
		for(int i=0;i<D;i++){
			in>>s;
			v.push_back(s);
		}
		for(int i=0;i<N;i++){
			in>>s;
			mPattern temp;
			temp.pattern=s;
			pattern.push_back(temp);
		}
		get_all_possible(pattern);
		for(int i=0;i<N;i++){
			int count=0;
			for(int j=0;j<D;j++){
				if(pattern[i].s.find( v[j])!=pattern[i].s.end())
					count++;
			}
			out<<"Case #"<<i+1<<": "<< count<<endl;
		}
		v.clear();
		pattern.clear();
		m.clear();
	}

	in.close();
	out.close();
	return 0;
}
