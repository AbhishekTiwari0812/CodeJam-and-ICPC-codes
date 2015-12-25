#include <iostream>
#include <fstream>
#define BIG   (9223372036854775808-1)

using namespace std;
typedef unsigned long long int lli;

bool T(lli k,lli n=BIG){
    if(n==1)
        return 0;
    if(k<(n+1)/2)
        return T(k,(n-1)/2);
    else if(k==(n+1)/2)
        return false;
    else
        return !T(n+1-k,(n-1)/2);

}

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int test;
    in>>test;
    lli k;
    for(int i=0;i<test;i++){
        in>>k;
        out<<"Case #"<<i+1<<": "<<T(k)<<endl;
    }




    in.close();
    out.close();
    return 0;
}
