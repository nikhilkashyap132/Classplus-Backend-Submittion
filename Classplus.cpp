#include <bits/stdc++.h>
using namespace std;

struct arr {
	int start, end;
};

//Finds nodes at distance 'k' from 'node' recursively and store the reference in 'count'
void dfs(const vector<vector<int> >& graph, int node, int k, int ref, int count[])
{

	if (k < 0)
		return;
	count[node]++;

	for (int i : graph[node]) {
		if (i != ref) {
			dfs(graph, i, k-1, node, count);
		}
	}
}

void dfsImpl(struct arr graph[], int node, int k,	int v, int e, int count[])
{
	vector<vector<int> > graphTemp(v + 1,vector<int>());

	for (int i = 0; i < e; i++) {
		int start = graph[i].start;
		int end = graph[i].end;

		graphTemp[start].push_back(end);
		graphTemp[end].push_back(start);
	}

	dfs(graphTemp, node, k, -1, count);
}

int main()
{
	int n,h,x;
	cin>>n>>h>>x;

	int epi[h];

	for(int i=0;i<h;i++){
		cin>>epi[i];
	}


	struct arr graph[n + 1] ;

	for(int i=0;i<n;i++){
		int p;
		int q;

		cin>>p>>q;

		graph[i].start=p;
		graph[i].end=q;

	}

    int count[100]={0};
    int size = sizeof(epi)/sizeof(epi[0]);
	for(int i=0;i<size;i++){
	    	dfsImpl(graph, epi[i], x, n, n-1, count);
	}
    int res=0;

	for(int i=0;i<100;i++){
	    if(count[i]==size){
	        res++;
	    }
	}
    cout<<res;
	return 0;
}


