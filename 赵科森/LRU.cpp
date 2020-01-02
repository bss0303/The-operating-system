#include<cstdio>
using namespace std;

int a[30]= {1,4,5,6,7,5,6,2,4,8,9,3,4,5,6,3,4,2,4,5};
int aLength=20;
int mem[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int memSize=3;

void LRU(){
	int stack[10], stackLast=0;//�洢mem�±�����ȼ�ջ
	 
	for(int i=0; i<aLength; i++){
		int loc=-1;
		for(int j=0; j<stackLast; j++){
			if(mem[stack[j]] == a[i]){
				loc=j;
				break;
			}
		}
		if(loc!=-1){//�ҵ��� 
			int tmpi=stack[loc];
			for(int k=loc; k<stackLast-1; k++){
				stack[k] = stack[k+1];
			}
			stack[stackLast-1] = tmpi;
		}
		else
		{//ȱҳ 
			if(stackLast<memSize){//�п���λ��
				mem[stackLast] = a[i];
				stack[stackLast]=stackLast;
				stackLast++;
			}else{//û�п���λ�ã�ջ���׸�Ԫ�� 
				mem[stack[0]] = a[i];
				
				int tmpi=stack[0];
				for(int k=0; k<stackLast-1; k++){
					stack[k] = stack[k+1];
				}
				stack[stackLast-1] = tmpi;
			}
		}
		
		printf("%d:",a[i]);
		for(int j=0; j<memSize; j++){
			if(j<stackLast) printf("%d", mem[j]);
			else printf(" ");
			printf(" ");
		}
		printf("\n");
	} 
}

int main() {
	LRU();
	return 0;
}
