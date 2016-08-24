#include <bits/stdc++.h>
#define mp make_pair
#define f(i,a,b) for( int i = ( a ), __ = ( b ); i < __; ++i )
#define fr(i,b,a) for( int i = ( b ), __ = ( a ); i >= __; --i )
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef map<int,int> mii;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<ll,ll> mll;
typedef map<ll,string> mls;
typedef map<string,ll> msl;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sll;
typedef set<ld> sld;
typedef pair<int,int> ii;

ifstream in;
ofstream out;

struct node{
	int li;
	int ri;
	node *l;
	node *r;
	int val;
};
int a[5001];

node *create(int l,int r){
	if( r < l)
		return NULL;
	if(l==r){
		node *n = new node;
		n->li=l;
		n->ri=r;
		n->l = NULL;
		n->r = NULL;
		n->val = 0;
		return n;
	}
	else{
		int mid = (l+r)/2;
		node *n=new node;
		n->li = l;
		n->ri = r;
		n->l = create(l,mid);
		n->r = create(mid+1,r);
		n->val = n->l->val + n->r->val;
		return n;
	}
}

void update(node *root,int x,int y){
	//cout<<"Updating:"<<x<<','<<y<<endl;
	int mid = (root->li+ root->ri)/2;
	if(root->li == x && root->ri == y){
		root->val++;
	}
	else if(y <= mid){
		update(root->l,x,y);
		//root->val = root->l->val + root->r->val;
	}
	else if(x > mid){
		update(root->r,x,y);
		//root->val = root->l->val + root->r->val;
	}
	else{
		update(root->l,x,mid);
		update(root->r,mid+1,y);
		//root->val = root->l->val + root->r->val;
	}
}

int get(node *root,int x){
	int mid = (root->li+ root->ri)/2;
	if(root->li == root->ri && root->li == x){
		return root->val;
	}
	else if(x <= mid){
		int val = get(root->l,x);
		return val + root->val;
	}
	else if(x > mid){
		int val = get(root->r,x);
		return val + root->val;	
	}
	else{
		//cout<<"There's some error\n";
	}
}


int main(){
	in.open("in.txt");
	out.open("out.txt");
	int test;
	in>>test;
	ii p[501];
	f(i0,0,test){
		cout<<"Processing case:"<<i0<<endl;
		out<<"Case #"<<i0+1<<": ";
		int n;
		in>>n;
		int x,y;
		int max = INT_MIN;
		int min = INT_MAX;
		f(i,0,n){
			in>>x>>y;
			if(x < min)
				min = x;
			if(y < min)
				min = y;
			if(x > max)
				max=x;
			if(y>max)
				max=y;
			p[i]=mp(x,y);
		}
		f(i,0,max+1)
		a[i]=0;
		node *root = create(0,max);
		f(i,0,n){
			//cout<<"update:"<<p[i].first<<','<<p[i].second<<endl;
			update(root,p[i].first,p[i].second);
		}
		int q;
		in>>q;
		int ans;
		f(i,0,q){
			in>>x;
			if(x > max || x < min){
				out<<0<<' ';
				continue;
			}
			ans = get(root,x);
			out<<ans<<' ';
		}
		out<<'\n';
	}

	in.close();
	out.close();
	return 0;
}