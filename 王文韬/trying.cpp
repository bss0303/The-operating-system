#include<iostream>
using namespace std;
//LRU
//aΪ����Ϊ20������,��������
int a[20] {1,4,5,6,7,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5};
//�ڴ��СΪ3��
void LRU(int *a) {
	//��ʼ���ڴ沢�����
	int ram[3] {0};
	//�������������������ʶ������̭�����ȼ���Ԫ��λ����С������ã������ȳ�ȥ����õ����������ұ�
	int temp[3] {0};
	//��¼temp�����ֵĸ���
	int num_temp=0;
	//��ʼ�����������ݲ���ʾ
	for(int i=0; i<20; i++) {
		//��һ��forѭ��������������
		int flag_jump1=0;
		for(int t=0; t<3; t++) {
			//��������Ѿ��м���Ҫ��������ַ���ֱ������
			if(ram[t]==a[i]) {
				
				//�������ȼ�
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
				//����ڴ��е�����
				for(int pointer_ram=0; pointer_ram<3; pointer_ram++) {
					cout<<ram[pointer_ram]<<" ";
				}
				cout<<endl;
				break;
			}
			//�����û����ֱ����(�������ظ���
			if(ram[t]==0) {
				
				ram[t]=a[i];
				//�������ȼ�
				temp[num_temp++]=a[i];
				flag_jump1=1;
				//����ڴ��е�����
				for(int pointer_ram=0; pointer_ram<3; pointer_ram++) {
					cout<<ram[pointer_ram]<<" ";
				}
				cout<<endl;
				break;
			}
		}
		//��һ��������������һ��ѭ��
		if(flag_jump1==1) {
			continue;
		}
				
		//���û�����ַ�����Ҫ�����滻
		//�ڶ���������������
		int flag_jump2=0;
		//��ʼ�滻���ݲ�����temp�����ȼ�
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
		//����ڴ�������
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


