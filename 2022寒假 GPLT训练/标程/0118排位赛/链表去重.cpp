#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct node
{
	int ad, key, ne;//结点地址，数据，下一个结点的地址 
};

node a[100000], c[100000], d[100000];

int main()
{
	int fi, n;
	cin >> fi >> n;
	for(int i=0; i<n; i++) 
	{
		int x;
		cin >> x;
		cin >> a[x].key >> a[x].ne;
		a[x].ad = x;//下标 <=> 结点的地址 
	}
	int b[10001] = {0};	
	int cj=0, dj=0;
	for(int i=fi; fi!=-1; fi=a[fi].ne)
	{//把原来的链表分为两个链表 
		if(b[abs(a[fi].key)]==0) b[abs(a[fi].key)]=1, c[cj++]=a[fi];
		else d[dj++]=a[fi];
	}
	if(cj>0) c[cj].ad = -1;//该链表右结点的话，最后一个的下一个结点地址是-1 
	if(dj>0) d[dj].ad = -1;
	for(int i=0; i<cj; i++)
		if(i<cj-1) printf("%05d %d %05d\n", c[i].ad, c[i].key, c[i+1].ad);
		else printf("%05d %d -1\n", c[i].ad, c[i].key);
	for(int i=0; i<dj; i++)
		if(i<dj-1) printf("%05d %d %05d\n", d[i].ad, d[i].key, d[i+1].ad);
		else printf("%05d %d -1\n", d[i].ad, d[i].key);
 	return 0;
}

