#include <iostream>
#include <fstream>
using namespace std;
typedef struct node{
    int value;
    int cost;
    struct node *l;
    struct node *r;
    struct node *p;
}node;


int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int t;
    in>>t;
    string s;
    node **N;
    for(int i=0;i<t;i++){
        cin>>s;
        int size=s.length();
        N=new node*[size];
        for(int j=0;j<size;j++){
            N[j]=new node;
            N[j]->value=j+1;
            N[j]->cost=s[j]-'0';
        }
    }
    return 0;
}
