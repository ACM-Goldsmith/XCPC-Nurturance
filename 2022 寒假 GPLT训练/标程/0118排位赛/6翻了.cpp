#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int i = 0, j;
	while(i<s.size())
	{
		if(s[i]!='6') 
		{
			cout << s[i];
			i++;
		}
		else
		{
			j = i;
			while(s[j] && s[j]=='6') j++;
			if(j-i > 9) cout << "27";
			else if(j-i > 3) cout <<"9";
			else
				for(; i<j; i++) cout << "6";
			i = j;
		}
	}
}

