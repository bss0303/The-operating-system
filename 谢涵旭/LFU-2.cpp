#include<iostream>
#include<stack>
using namespace std;

int visit_time[100] = { 0 };											   //���ʴ���
//int TLB[3] = { 1,4,9 };												   //���
int a[] = { 3,4,1,2,5,7,2,5,7,8,9,3,4,4,6,2,2,6,6,4,3,4,1,2,5,7,2,5,7,8 }; //Ĭ�Ϸ�������
int aLength = 30;														   //Ĭ�Ϸ������д�С	
int memSize = 3;														   //Ĭ���ڴ�ҳ���С
int mem[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1};							   //�ڴ�ҳ��
int count = 0;
void LFU(int arr[]);
int main()
{
	LFU(a);
	system("pause");
}
void LFU(int arr[])
{
	for (int i = 0; i < aLength; i++)
	{
		bool flag = false;
		int time = 100;
		int location = -1;
		int visit = arr[i];
		for (int j = 0; j <memSize; j++)
		{
			if (mem[j] == visit||count++<3)//�Ƿ��Ѿ���ҳ����
			{
				visit_time[visit]++;
				flag = true;
				break;
			}
			else//��¼ҳ����Ŀǰ����Ƶ�ʷ��ʵ�ҳ��λ��
				if (time >visit_time[mem[j]])
				{
					time = visit_time[mem[j]];
					location = j;
				}
		}
		if (!flag)
		{
			mem[location] = visit;
			//TLB[location] = visit;
			visit_time[visit]++;
		}

		//��ӡ
		cout << visit << ":";
		for (int i = 0; i < memSize; i++)
			cout << mem[i] << " ";
		cout << endl;
	}
}