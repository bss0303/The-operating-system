#include<iostream>
using namespace std;
//��������a(30),aLength�������е�ʵ�ʴ�С���ڴ�mem��memSize���ڴ�����ɱ䣩����������Ĭ��ֵ-1
//LRU
//aΪ����Ϊ30������,��������
int a[30] {1,4,5,6,7,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5,2,4,6,8,9,7,5,3,2,6};
//�ڴ��СΪ3��
int mem[10];
int memSize=0;
int aLength=0;
void LRU() {
	//�������������������ʶ������̭�����ȼ���Ԫ��λ����С������ã������ȳ�ȥ����õ����������ұ�
	int temp[10];
	//��ʼ���ڴ沢�����
	for(int i=0; i<10; i++) {
		mem[i]=-1;
		temp[i]=-1;
	}
	//��¼temp�����ֵĸ���
	int num_temp=0;
	//��ʼ�����������ݲ���ʾ
	for(int i=0; i<aLength; i++) {
		//��һ��forѭ��������������
		int flag_jump1=0;
		//��¼�����Ѿ��е��ַ���λ��
		int place=-1;
		//�����Ѿ������ݻ�δ������� 
		for(int t=0; t<memSize; t++) {
			//��������Ѿ��м���Ҫ��������ַ���ֱ������
			if(mem[t]==a[i]) {
				//cout<<"��ƥ��ִ��"<<endl;
				place=i;
				flag_jump1=1;
				break;
			}
			//�����û����ֱ����(�������ظ���
			if(mem[t]==-1) {
				//cout<<"��û��ִ��"<<endl;
				mem[t]=a[i];
				//�������ȼ�
				temp[num_temp++]=a[i];
				flag_jump1=1;
				break;
			}
		}
		if(place!=-1) {
			//�������ȼ�
			//cout<<"�������ȼ�ִ��"<<endl;
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

		//��һ��������������һ��ѭ����������ڴ����� 
		if(flag_jump1==1) {
			//����ڴ��е�����
			//cout<<"��һ������ִ��"<<endl;
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

		//���û�����ַ�����Ҫ�����滻
		//��ʼ�滻���ݲ�����temp�����ȼ�
		//cout<<"û�����ַ�Ҳ��Ϊ��ִ��"<<endl;
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
		//����ڴ�������
		//cout<<"�ڶ������ִ��"<<endl;
		for(int j=0; j<memSize; j++) {
			cout<<mem[j]<<" ";
		}
		cout<<endl;
	}
}



int main() {
	cout<<"����memSize��aLength"<<endl;
	cin>>memSize>>aLength;
	LRU();
	return 0;
}


