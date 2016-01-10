#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct node{
    string id;
    vector<node *>nbd;
    int visited;
    node *parent;
    bool color;
};
map<string ,node *>m;

string BFS(){
    queue<node *> q;
    node *temp;
    for(map<string,node *>::iterator it=m.begin();it!=m.end();it++){
        temp=it->second;
        if(temp->visited!=true){
            temp->color=false;
            temp->visited=true;
            q.push(temp);
            while(!q.empty()){
                temp=q.front();
                q.pop();
                for(int i=0;i<temp->nbd.size();i++){
                    if(temp->nbd[i]->visited!=true){
                        temp->nbd[i]->parent=temp;
                        temp->nbd[i]->color=!temp->color;
                        temp->nbd[i]->visited=true;
                        q.push(temp->nbd[i]);
                    }
                    else if(temp->color==temp->nbd[i]->color)
                            return "No";

                }
            }

        }
    }
    return "Yes";
}

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int test;
    in>>test;
    string a,b;
    node *temp;
    int n;
    for(int i=0;i<test;i++){
        in>>n;
        for(int j=0;j<n;j++){
            in>>a>>b;
            if(m.find(a)==m.end()){
                temp=new node;
                temp->id=a;
                temp->visited=false;
                m[a]=(temp);
                }
            if(m.find(b)==m.end()){
                temp=new node;
                temp->id=b;
                temp->visited=false;
                m[b]=(temp);
            }
            m[a]->nbd.push_back(m[b]);
            m[b]->nbd.push_back(m[a]);
        }
        out<<"Case #"<<i+1<<": "<<BFS()<<endl;
        m.clear();
    }
    return 0;
}
