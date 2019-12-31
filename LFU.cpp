#include<iostream>
#include<stack>
using namespace std;

int visit_time[100] = { 0 };
int yebiao[3] = { 1,4,9 };
int TLB[3] = { 1,4,9 };
void LFU(int arr[]);
int main()
{
	int arr[] = { 3,4,1,2,5,7,2,5,7,8,9,3,4,4,6,2,2,6,6,4 };
	//int arr[] = {1,2,3 };
	visit_time[1]++;
	visit_time[4]++;
	visit_time[9]++;
	LFU(arr);
	system("pause");
}
void LFU(int arr[])
{
	bool flag = false;
	int time = 100;
	int location = -1;
	for (int i = 0; i < 20; i++)
	{
		//cout <<"页    号："<< 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5 << " " << 6 << " " << 7 << " " << 8 << " " << 9 << endl;
		//cout <<"访问次数："<< visit_time[1] << " "<< visit_time[2] << " "<< visit_time[3] << " "<< visit_time[4] <<" " << visit_time[5] << " " << visit_time[6] << " " << visit_time[7] << " " << visit_time[8] << " " << visit_time[9] << endl;
		//cout << "快	  表：" << TLB[0] << " " << TLB[1] << " " << TLB[2] << endl;
		int visit = arr[i];
		for (int j = 0; j <3; j++)
		{
			if (TLB[j] == visit)//是否已经在页表中
			{
				visit_time[visit]++;
				flag = true;
				//cout << "快表命中" << endl;
				break;
			}
			else if (yebiao[j] == visit)//是否已经在页表中
			{
				visit_time[visit]++;
				flag = true;
				//cout << "页表命中" << endl;
				break;
			}
			else//更新最少频率访问的页面位置
				if (time >visit_time[yebiao[j]])
				{
					//cout << time << " " << visit_time[yebiao[j]] << " ";
					time = visit_time[yebiao[j]];
					location = j;
				}
		}
		if (!flag)
		{
			//cout << "页表未命中" << endl;
			yebiao[location] = visit;
			TLB[location] = visit;
			visit_time[visit]++;
		}
		cout << visit << ":" << yebiao[0] << " " << yebiao[1] << " " << yebiao[2] << endl;
		flag = false;
		time = 100;
		location = -1;
	}
}