#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include <iostream>
using namespace std;
#define pii pair<int, int>
#define pip pair<long long int, pii>
#define F first
#define S second

inline void inp(int *n)	//fast input function
{
    *n = 0;
    int ch = getchar_unlocked();
    int sign = 1;
    while(ch < '0' || ch > '9') 
    {
        if (ch == '-') 
            sign = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9')
        (*n) = ((*n)<<3) + ((*n)<<1) + ch - '0', ch = getchar_unlocked();
    *n = (*n)*sign;
}

const int MAX = 10000000;

//class implementing Union Find Data Structure with Path Compression
class Union_Find
{
  public:
  

	int id[MAX], sz[MAX];
	Union_Find(int n)	//class constructor
	{
		for (int i = 0; i < n; ++i)
		{
			id[i] = i;
			sz[i] = 1;
		}
	}
	
	int root(int i)
	{
		while(i != id[i])
		{
			id[i] = id[id[i]];	//path Compression
			i = id[i];
		}
		return i;
	}
	int find(int p, int q)
	{
		return root(p)==root(q);
	}
	void unite(int p, int q)
	{
		int i = root(p);
		int j = root(q);

		if(sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			id[j] = i;
			sz[i] += sz[j];
		}
	}
};


vector< pip > graph;
int n, e;
int T;
int cnt;

void Kruskal_MST()
{
	Union_Find UF(n);
	int u, v;

	for (int i = 0; i < e; ++i)
	{
	    
		u = graph[i].S.F;
		v = graph[i].S.S;
		if( !UF.find(u, v) )
		{
		    int i1 = UF.root(u);
	    	int j1 = UF.root(v);
		    cnt=(cnt+(((UF.sz[i1]*UF.sz[j1])%1000000007)*(graph[i].F%1000000007))%1000000007)%1000000007;
			//cout<<UF.sz[i1]*UF.sz[j1]*graph[i].F<<'\n';
			UF.unite(u, v);
			T += graph[i].F;
		
		}
	}
}

int main()
{
	int u, v;
	int c;
	inp(&n);	//enter the no of nodes
	e=n-1;	//enter the no of edges
	
	graph.resize(e);

	for (int i = 0; i < e; ++i)
	{
		//inp(&u);	//enter vertex u
		//inp(&v);	//enter vertex v
		//inp(&c);	//enter cost of edge (u,v)
		
		cin>>u;
		cin>>v;
		cin>>c;
		
		u--;
		v--;
		graph[i] = pip( c, pii(u,v));
	}
	sort(graph.begin(), graph.end());	//sort the edges in increasing order of cost

	T = 0;
	cnt=0;
	Kruskal_MST();
	printf("%lld\n",cnt);
	return 0;
}