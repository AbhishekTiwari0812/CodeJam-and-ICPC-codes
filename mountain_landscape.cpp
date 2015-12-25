#include <iostream>
#include <fstream>

struct point {
double x,y;
};

class segment{
public:
    point l,r;
    double slope(){
    	return (r.y-l.y)/(r.x-l.x);
    }
    int id;
    segment *next_higher;
    void set_next();
};
segment ** mSeg;

void segment::set_next(){
    if(this->id==size-1){
        this->next_higher=NULL;
        return;
    }
    segment *temp=mSeg[this->id+1];
    while(temp->slope() <= this->slope()){
    	temp=temp->next_higher;
    	if(temp==NULL)
    		break;
    }
    this->next_higher=temp;
}


using namespace std;
int main(){


}
