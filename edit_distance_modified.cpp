#include <iostream>
#define INF ((1<<31)-1)
using namespace std;

typedef long long int lli;

string s1,s2;
lli **DP;
lli a,b;

lli time_cons(lli i,lli j){
    lli min_cost=INF;
    lli cost;
    for(int i=0;i<=b-a;i++){
        j=a-1;
        cost=0;
       // cout<<"string is:"<<s2.substr(i,j+1)<<endl;
        for(int some=i;some<=j;some++)
            if(s2[some]!=s1[some-i])
                cost++;
        if(cost<min_cost)
            min_cost=cost;

    }
    return cost;
}

int main(){
    int test;
    cin>>test;

    for(int some=0;some<test;some++){
        cin>>s1>>s2;
        a=s1.size();
        b=s2.size();
        cout<<time_cons(0,0)<<endl;
    }
    return 0;
}
