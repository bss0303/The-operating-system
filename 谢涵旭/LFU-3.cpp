#include<iostream>
using namespace std;

int visit_time[10];	
int a[30] = { 3,4,1,2,5,7,2,5,7,8,9,3,4,4,6,2,2,6,6,4,3,4,1,2,5,7,2,5,7,8 }; 	//Ĭ�Ϸ�������
int aLength = 30;														   		//Ĭ�Ϸ������д�С	
int memSize = 3;													   			//Ĭ���ڴ�ҳ���С
int mem[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1};							   	    //�ڴ�ҳ��
int cnt = 0;
void LFU(int arr[]);
int main()
{
	LFU(a);
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
			if (mem[j] == visit||cnt<3)//�Ƿ��Ѿ���ҳ����
			{
				if(mem[j]==visit)
					visit_time[j]++;
				if(cnt<3)
				{
					mem[cnt]=visit;
					visit_time[cnt++]++;
				}
				flag = true;
				break;
			}
			else//��¼ҳ����Ŀǰ����Ƶ�ʷ��ʵ�ҳ��λ��
				if (time >visit_time[j])
				{
					time = visit_time[j];
					location = j;
				}
		}
		if (!flag)
		{
			mem[location] = visit;
			visit_time[location]=1;
		}
		cout << visit << ":";
		for (int i = 0; i < memSize; i++)
			cout << mem[i] << " ";
		cout << endl;
	}
}
