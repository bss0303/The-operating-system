#include<iostream>
using namespace std;
//LRU
//a为长度为20的数组,输入序列
int a[20] {1,4,5,6,7,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5};
//内存大小为3个
void LRU(int *a) {
	//初始化内存并且填充
	int ram[3] {0};
	//辅助数组变量，用来标识数据淘汰的优先级，元素位置最小（最不常用）的最先出去，最常用的数据在最右边
	int temp[3] {0};
	//记录temp中数字的个数
	int num_temp=0;
	//开始更换表中数据并显示
	for(int i=0; i<20; i++) {
		//第一级for循环跳出辅助变量
		int flag_jump1=0;
		for(int t=0; t<3; t++) {
			//如果表中已经有即将要输入的新字符，直接跳过
			if(ram[t]==a[i]) {
				
				//调整优先级
				for(int pointer_temp=0; pointer_temp<3; pointer_temp++) {
					if(temp[pointer_temp]==a[i]) {
						for(int ax=pointer_temp; ax<2; ax++) {
							temp[ax]=temp[ax+1];
						}
						temp[num_temp-1]=a[i];
						break;
					}
				}
				flag_jump1=1;
				//输出内存中的数据
				for(int pointer_ram=0; pointer_ram<3; pointer_ram++) {
					cout<<ram[pointer_ram]<<" ";
				}
				cout<<endl;
				break;
			}
			//如果表没满，直接填(不会有重复）
			if(ram[t]==0) {
				
				ram[t]=a[i];
				//调整优先级
				temp[num_temp++]=a[i];
				flag_jump1=1;
				//输出内存中的数据
				for(int pointer_ram=0; pointer_ram<3; pointer_ram++) {
					cout<<ram[pointer_ram]<<" ";
				}
				cout<<endl;
				break;
			}
		}
		//第一级跳出，进行下一次循环
		if(flag_jump1==1) {
			continue;
		}
				
		//如果没有新字符，将要进行替换
		//第二级跳出辅助变量
		int flag_jump2=0;
		//开始替换数据并重置temp中优先级
		for(int pointer_ram=0; pointer_ram<3; pointer_ram++) {
			if(ram[pointer_ram]==temp[0]) {
				ram[pointer_ram]=a[i];
				for(int pointer_temp=0; pointer_temp<2; pointer_temp++) {
					temp[pointer_temp]=temp[pointer_temp+1];
				}
				temp[2]=a[i];
				break;
			}
		}
		//输出内存中数据
		for(int j=0; j<3; j++) {
			cout<<ram[j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	LRU(a);
	return 0;
}


