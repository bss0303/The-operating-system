#include<iostream>
using namespace std;
//访问序列a(30),aLength访问序列的实际大小，内存mem，memSize（内存个数可变），访问序列默认值-1
//LRU
//a为长度为30的数组,输入序列
int a[30] {1,4,5,6,7,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5,2,4,6,8,9,7,5,3,2,6};
//内存大小为3个
int mem[10];
int memSize=0;
int aLength=0;
void LRU() {
	//辅助数组变量，用来标识数据淘汰的优先级，元素位置最小（最不常用）的最先出去，最常用的数据在最右边
	int temp[10];
	//初始化内存并且填充
	for(int i=0; i<10; i++) {
		mem[i]=-1;
		temp[i]=-1;
	}
	//记录temp中数字的个数
	int num_temp=0;
	//开始更换表中数据并显示
	for(int i=0; i<aLength; i++) {
		//第一级for循环跳出辅助变量
		int flag_jump1=0;
		//记录出现已经有的字符的位置
		int place=-1;
		//表中已经有数据或未满的情况 
		for(int t=0; t<memSize; t++) {
			//如果表中已经有即将要输入的新字符，直接跳过
			if(mem[t]==a[i]) {
				//cout<<"有匹配执行"<<endl;
				place=i;
				flag_jump1=1;
				break;
			}
			//如果表没满，直接填(不会有重复）
			if(mem[t]==-1) {
				//cout<<"表没满执行"<<endl;
				mem[t]=a[i];
				//调整优先级
				temp[num_temp++]=a[i];
				flag_jump1=1;
				break;
			}
		}
		if(place!=-1) {
			//调整优先级
			//cout<<"调整优先级执行"<<endl;
			for(int pointer_temp=0; pointer_temp<memSize; pointer_temp++) {
				if(temp[pointer_temp]==a[place]) {
					for(int ax=pointer_temp; ax<memSize-1; ax++) {
						temp[ax]=temp[ax+1];
					}
					temp[num_temp-1]=a[i];
					break;
				}
			}
		}

		//第一级跳出，进行下一次循环，并输出内存内容 
		if(flag_jump1==1) {
			//输出内存中的数据
			//cout<<"第一次跳出执行"<<endl;
			for(int pointer_mem=0;pointer_mem<memSize;pointer_mem++) {
				if(mem[pointer_mem]==-1) {
					cout<<"  ";
				} else {
					cout<<mem[pointer_mem]<<" ";
				}
			}
			cout<<endl;
			continue;
		}

		//如果没有新字符，将要进行替换
		//开始替换数据并重置temp中优先级
		//cout<<"没有新字符也不为空执行"<<endl;
		for(int pointer_mem=0; pointer_mem<memSize; pointer_mem++) {
			if(mem[pointer_mem]==temp[0]) {
				mem[pointer_mem]=a[i];
				for(int pointer_temp=0; pointer_temp<memSize-1; pointer_temp++) {
					temp[pointer_temp]=temp[pointer_temp+1];
				}
				temp[memSize-1]=a[i];
				break;
			}
		}
		//输出内存中数据
		//cout<<"第二次输出执行"<<endl;
		for(int j=0; j<memSize; j++) {
			cout<<mem[j]<<" ";
		}
		cout<<endl;
	}
}



int main() {
	cout<<"输入memSize和aLength"<<endl;
	cin>>memSize>>aLength;
	LRU();
	return 0;
}


