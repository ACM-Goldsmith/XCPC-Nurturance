#include <bits/stdc++.h>
using namespace std;
struct node
{
	int w,v,level;
};

int w[100];
int v[100];
int n;
int c;


int bfs() {
    int maxv = 0;
    queue<node>q;
	q.push({0,0,0});
    while(!q.empty())//q.size()
	{
		node t=q.front();
		q.pop();
        if (t.level >= n) {
            maxv = max(t.v, maxv);
        } else {
	        if (t.w + w[t.level] <= c) {
	            //cout << t.v << " " << t.level << endl;
	            q.push({t.w + w[t.level], t.v + v[t.level], t.level + 1});
	        }
	        q.push({t.w, t.v, t.level+1});        		
		}
    }
    return maxv;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << bfs() << endl;
    
    return 0;
}
