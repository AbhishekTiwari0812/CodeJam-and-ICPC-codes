#include <iostream>
using namespace std;
int *DP;
bool winning_method(int N,int m1,int m2,int flag){
    bool a=false,b=false;
    if(N==m1||N==m2)
        return true;
    else if(N < m1 && N < m2)
        return false;
    else{
        if(N-m1>=0){
            if(DP[N-m1]!=-1)
                a=!DP[N-m1];
            else {
                a= !winning_method(N-m1,m1,m2,1-flag);
                DP[N-m1]=!a;
            }
        }
        else
            a=0;
        if(N-m2>=0){
            if(DP[N-m2]!=-1)
                b=!DP[N-m2];
            else {
                b = !winning_method(N-m2,m1,m2,1-flag);
                DP[N-m2]=!b;
            }
        }
        else
          b=false;
        return a||b;

    }

}

int main(){
    int test;
    cin>>test;
    int n,m1,m2;

    for(int some=0;some<test;some++){
        cin>>n>>m1>>m2;
        DP=new int[n+1];
        for(int i=0;i<n+1;i++)
            DP[i]=-1;
        cout<<winning_method(n,m1,m2,1)<<endl;
        delete DP;

    }
}
