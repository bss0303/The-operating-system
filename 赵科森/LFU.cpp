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
		for(int j=0; j<cnt; j++){//在页表中寻找 
			if(mem[j] == a[i]){
				loc=j;
				break;
			}
		}
		
		if(loc!=-1){//找到了 
			frequency[loc]++;
		}else{//缺页
			if(cnt<memSize){//有空闲内存 
				mem[cnt] = a[i];
				frequency[cnt++]=1; 
			}else{//页面置换 
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
