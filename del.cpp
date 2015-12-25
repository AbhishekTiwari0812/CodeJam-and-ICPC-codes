#include <iostream>
using namespace std;

int f(int n){
    if(n==1)
        return 1;
    if(n%2==0)
        return f(n/2);
    else return f(n/2)+1;
}
void bin(int n){
    if(n==1||n==0)
        cout<<" "<<n;
    else {
        bin(n/2);
        cout<<" "<<n%2;


    }
}

int main(){
    int m,n;
    cin>>m>>n;
    int max=-1;
    n-=1;
    int cur;
    for(int i=m;i<=n;i++){
        cur=f(i);
        cout<<i<<"::::::    ";
        bin(i);
        cout<<"=====>>     "<<cur<<endl<<endl;
        if(cur>max)
            max=cur;
    }
    cout<<max;
}
