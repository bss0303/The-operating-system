#include<iostream>
using namespace std;
//LRU
//a为长度为20的数组,输入序列
int a[20] {1,4,5,6,7,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5};
//内存大小为3个
void LRU(int *a) {
	//初始化内存并且填充
	int ram[3] {0};
	int temp[3] {0};
	for(int i=0; i<3; i++) {
		ram[i]=a[i];
		temp[i]=ram[i];
		cout<<ram[i]<<" ";
	}
	cout<<endl;
	//开始更换表中数据并显示 
	for(int i=3; i<20; i++) {
		//如果表中有新字符，直接输入下一个数据
		for(int t=0; t<3; t++) {
			if(ram[t]==a[i]) {
				break; 
			}
			//如果没有新字符，将要进行替换
			else {
				int count=0;
				int flag=0;
				for(int j=i-1; j>=0; j--) {
					//开始往前逐个比对 ，最后找到的为最不常用的
					for(int k=0; k<3; k++) {
						if(ram[k]==a[j]) {
							//如果找到了,直接替换
							if(count==2) {
								ram[k]=a[i];
								count=0;
								flag=1;
								break;
							}
							//如果还未找到
							temp[k]=0;
							count++;
						}
					}
					//找到了，直接退出对比循环
					if(flag==1) {
						flag=0;
						break;
					}
				}
				//重置temp，输出新内存序列
				for(int l=0; l<3; l++) {
					temp[l]=ram[l];
					cout<<ram[l]<<" ";
				}
				cout<<endl;
			}
		}
	}
}
int main() {
	LRU(a);
	return 0;
}


