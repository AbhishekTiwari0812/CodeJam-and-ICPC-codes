#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#define CONSTANT 100000
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	int ** customers;
	int *size;
	int *answer;
	for(int i0=0;i0<test;i0++){
		int N,M,T,a,b;
		in>>N>>M;
		cout<<endl<<endl<<endl;
		size=new int[M];
		customers=new int*[M];
		answer=new int[N];
		for(int i=0;i<M;i++){
			in>>T;
			size[i]=T;
			customers[i]=new int[T];
			for(int j=0;j<T;j++){
				in>>a>>b;
				a-=1;
				customers[i][j]=a+CONSTANT*b;
			}
		}
		for(int i=0;i<M;i++){
			for(int j=0;j<size[i];j++)
				cout<<customers[i][j]<<" ";
			cout<<endl;
		}
		for(int i=0;i<N;i++)
			answer[i]=0;
		for(int i=0;i<M;i++){
			if(size[i]==1){
				if(customers[i][0] >= CONSTANT){
					answer[customers[i][0]-CONSTANT]=1;
				}
			}
			cout<<endl;
		}
		bool impossible=true;
		for(int i=0;i<M;i++){
			impossible=true;
			for(int j=0;j<size[i];j++){
				if(customers[i][j] >= CONSTANT){
					if(answer[customers[i][j]-CONSTANT]==1){
						impossible=false;
						break;
					}
				}
				else{
					if(answer[customers[i][j]]==0){
						impossible=false;
						break;
					}	
				}
			
				
			}
			if(impossible==true)
				break;
		}
		
		if(impossible)
			out<<"Case #"<<i0+1<<": IMPOSSILBE"<<endl;
		else{
			out<<"Case #"<<i0+1<<":";
			for(int i=0;i<N;i++)
				out<< " "<<answer[i];
			out<<endl; 
		}






	}
	in.close();
	out.close();
	return 0;
}
