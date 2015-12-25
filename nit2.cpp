#include <iostream>
#define MOD 1000000007
using namespace std;


typedef long long int lli;

lli **DP;

lli T(int x,int y){
	if(x==0 || y==0){
		DP[x][y]=1;
		return 1;
	}
	else {
		lli a,b,c;
		if(DP[x-1][y]!=-1)
			a=DP[x-1][y];
		else {
			a=T(x-1,y);
			DP[x-1][y]=a;
		}
 		if(DP[x][y-1]!=-1)
			b=DP[x][y-1];
		else {
			b=T(x,y-1);
			DP[x][y-1]=b;
		}
		if(DP[x-1][y-1]!=-1)
			c=DP[x-1][y-1];
		else {
			c=T(x-1,y-1);
			DP[x-1][y-1]=c;
		}
		return (a+b+c)%MOD;

	}

}



int main(){
	DP=new lli*[1005];
    for(int i=0;i<1005;i++){
    	DP[i]=new lli[1005];
    	for(int j=0;j<1005;j++)
    		DP[i][j]=-1;
    }
    int test;
    cin>>test;
    int a,b,c,d;
    int x,y;
    for(int some=0;some<test;some++){
    	cin>>a>>b>>c>>d;
    	x=c>a?c-a:a-c;
    	y=d>b?d-b:b-d;
    	cout<<T(x,y)<<endl;
    }
    return 0;
}
