#include<iostream>
using namespace std;
//LRU
//aΪ����Ϊ20������,��������
int a[20] {1,4,5,6,7,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5};
//�ڴ��СΪ3��
void LRU(int *a) {
	//��ʼ���ڴ沢�����
	int ram[3] {0};
	int temp[3] {0};
	for(int i=0; i<3; i++) {
		ram[i]=a[i];
		temp[i]=ram[i];
		cout<<ram[i]<<" ";
	}
	cout<<endl;
	//��ʼ�����������ݲ���ʾ 
	for(int i=3; i<20; i++) {
		//������������ַ���ֱ��������һ������
		for(int t=0; t<3; t++) {
			if(ram[t]==a[i]) {
				break; 
			}
			//���û�����ַ�����Ҫ�����滻
			else {
				int count=0;
				int flag=0;
				for(int j=i-1; j>=0; j--) {
					//��ʼ��ǰ����ȶ� ������ҵ���Ϊ����õ�
					for(int k=0; k<3; k++) {
						if(ram[k]==a[j]) {
							//����ҵ���,ֱ���滻
							if(count==2) {
								ram[k]=a[i];
								count=0;
								flag=1;
								break;
							}
							//�����δ�ҵ�
							temp[k]=0;
							count++;
						}
					}
					//�ҵ��ˣ�ֱ���˳��Ա�ѭ��
					if(flag==1) {
						flag=0;
						break;
					}
				}
				//����temp��������ڴ�����
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


