#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int a[30]= {1,1,2,2,4,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5};
int aLength=20;
int mem[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int memSize=3;

void LFU(){
	int cnt=0;
	int frequency[10]={0};
	
	for(int i=0; i<aLength; i++){
		int loc=-1;
		for(int j=0; j<cnt; j++){//��ҳ����Ѱ�� 
			if(mem[j] == a[i]){
				loc=j;
				break;
			}
		}
		
		if(loc!=-1){//�ҵ��� 
			frequency[loc]++;
		}else{//ȱҳ
			if(cnt<memSize){//�п����ڴ� 
				mem[cnt] = a[i];
				frequency[cnt++]=1; 
			}else{//ҳ���û� 
				int x = min_element(frequency, frequency+cnt)-frequency;
				mem[x]=a[i];
				frequency[x] = 1;
			}
		}
		
		printf("%d:",a[i]);
		for(int j=0; j<memSize; j++){
			if(j<cnt) printf("%d", mem[j]);
			else printf(" ");
			printf(" ");
		}
		printf("\n");
	}	
}

int main() {
	LFU();
	return 0;
}
