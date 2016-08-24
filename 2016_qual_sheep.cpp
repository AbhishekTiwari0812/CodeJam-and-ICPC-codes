#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lli;



int *A;
int count;
int size=10;


bool check(lli a){
	int temp;
	while(a>0){
		temp=a%10;
		//cout<<"a="<<a<<endl;
		if(A[temp]==0){
			count++;
			A[temp]=1;
		}
		a/=10;
	}
	return (count>=10);
}

lli init(lli n){
	count=0;
	for(int i=0;i<size;i++){
		A[i]=0;
	}
	lli i=1;
	lli original=n;
	while(true){
        //cout<<"n="<<n<<endl;
		if(check(n)){
			//cout<<"==========="<<endl;
			return n;

		}
		else{
            i+=1;
            n=original*i;
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	A=new int[10];
	ifstream in;
	in.open("in.txt");
	ofstream out;
	out.open("out.txt");
	int t;
	in>>t;
	lli n;
	for(int i=1;i<=t;i++){
		in>>n;
		out<<"Case #"<<i<<": ";
		if(n!=0)
			out<<init(n)<<endl;
		else out<<"INSOMNIA"<<endl;
	}
	return 0;
}
