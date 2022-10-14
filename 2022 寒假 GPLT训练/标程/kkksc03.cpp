#include <iostream>
using namespace std;

int cost[70];//ÿ����Ŀ��ʱ�� 
int maxval = 0;//���Բ�������ʱ��һ��������Ŀʱ��� 
int remain = 0;//ʣ��û��ѡ������Ŀ��ʱ��� 
int sum = 0;//�ܵ�ʱ��� 
int n = 0;//��ǰ��Ŀ�ܵ���Ŀ��
int total = 0;//��ǰ��Ŀ������Ŀ��ʱ���ܺ� 

int dfs(int t, int curval) {
	if (t == n) {//������Ŀ��ѡ���� 
		maxval = max(curval, maxval);//��ǰ�������ֵ�Ƚϣ������Ƿ���Ҫ���� 
		return total - maxval;//������ߵ����ֺ�С��ʱ��͵�һ�룬���Է����ұ���Ҫ��ʱ�� 
	}
	
	remain -= cost[t];
	
	//��ǰҪ��ѡ���Ƿ�ѵ�t����Ŀ������ߵļ��� 
	//1������ǰ��t����Ŀ������ߵļ��� 
	//Լ���������涨�������ѡ����Ŀ��ʱ��Ͳ�������ʱ���һ�� 
	if (curval + cost[t] <= total / 2) {
		dfs(t+1, curval + cost[t]);	
	}
	
	//2�����ѵ�ǰ��t����Ŀ������ߵļ��� 
	//�޽纯������������֧��ʹ���Ϻ���ûѡ��������е�ֵ
	//�������ܳ���ǰ�������ֵ������Ҫ����
	if (curval + remain > maxval)  
		dfs(t+1, curval);
		
	remain += cost[t]; 
	return total - maxval;
}

int main() {
	int s[4];//ÿ����Ŀ��������Ŀ�� 
	for (int i = 0; i < 4; i++)
		cin >> s[i];
	sum = 0;
	for (int i = 0; i < 4; i++) {
		total = 0;
		for (int j = 0; j < s[i]; j++) {
			cin >> cost[j];
			total += cost[j];
		}

		n = s[i];
		remain = total;
		maxval = 0;
		sum += dfs(0, 0);
	}
	
	cout << sum << endl;
} 
