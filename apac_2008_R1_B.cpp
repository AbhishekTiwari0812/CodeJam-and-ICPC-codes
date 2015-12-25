#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
struct  point{
	int type;
	int malted;
	point(int a,int b){
		type=a;
		malted=b;
	}
};

struct comp {
    bool operator() (const point& lhs, const point& rhs) const{
        return lhs.type + 1e4*lhs.malted <  rhs.type + 1e4*rhs.malted;
    }
};

class customer{
    public:
	set<point,comp> items;
};


int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int test;
	in>>test;
	//out<<test<<endl;
	int type_of_shakes;			//how many types of milks shakes there are.
	int num_of_cust;			//number of customers
	int num_of_shakes;			//numbers of shakes one customer orders
	int shake_id,shake_type;	//that shakes' id and type (malter/unmalted)
	int impossible;
	customer **list;
	for(int i0=0;i0<test;i0++){
        int *answer;
		in>>type_of_shakes;
		//out<<type_of_shakes<<endl;
		answer=new int[type_of_shakes];
		in>>num_of_cust;
		//out<<num_of_cust<<endl;
		list=new customer*[num_of_cust];
		customer *temp;
		for(int i=0;i<num_of_cust;i++){
			temp=new customer;
			in>>num_of_shakes;
			//out<<num_of_shakes;
			for(int j=0;j<num_of_shakes;j++){
				in>>shake_id>>shake_type;
				//out<<" "<<shake_id<<" "<<shake_type;
				temp->items.insert(point(shake_id,shake_type));
			}
			//out<<endl;
			list[i]=temp;
		}
		for(int i=0;i<num_of_cust;i++){
			if(list[i]->items.size()==1 ){
				if(list[i]->items.begin()->malted==1)
					answer[i]=1 ;
			}
			else answer[i]=0 ;
		}
		impossible=0 ;
		for(int i=0;i<num_of_cust;i++){
			impossible=1 ;
			for(set<point>::iterator it=list[i]->items.begin();it!=list[i]->items.end();it++){
				if(answer[it->type-1]==it->malted){
					impossible=0 ;
					break;
				}
			}
			if(impossible==1)
				break;
		}
		if(impossible==1)
			out<<"Case #"<<i0+1<<": IMPOSSIBLE";
		else {
            out<<"Case #"<<i0+1<<": ";
			for(int i=0;i<type_of_shakes;i++)
				out<<answer[i]<<" ";
		}
		out<<endl;
		delete answer;
		delete list;

	}

	in.close();
	out.close();
	return 0;
}
