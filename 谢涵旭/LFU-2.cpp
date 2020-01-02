#include<iostream>
#include<stack>
using namespace std;

int visit_time[100] = { 0 };											   //访问次数
//int TLB[3] = { 1,4,9 };												   //快表
int a[] = { 3,4,1,2,5,7,2,5,7,8,9,3,4,4,6,2,2,6,6,4,3,4,1,2,5,7,2,5,7,8 }; //默认访问序列
int aLength = 30;														   //默认访问序列大小	
int memSize = 3;														   //默认内存页表大小
int mem[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1};							   //内存页表
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
			if (mem[j] == visit||count++<3)//是否已经在页表中
			{
				visit_time[visit]++;
				flag = true;
				break;
			}
			else//记录页表中目前最少频率访问的页面位置
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

		//打印
		cout << visit << ":";
		for (int i = 0; i < memSize; i++)
			cout << mem[i] << " ";
		cout << endl;
	}
}