#include<cstdio>
#include<algorithm>
using namespace std; 


int a[30]={7,0,2,1,5,3,5,1,3,2,1,2,1,1,1,2,3,4,1,1};//·ÃÎÊĞòÁĞ 
int aLength=20;

int mem[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},cnt,memSize=3;								//ÄÚ´æ

int main(){
	int l=0;
	for(int i=0; i<aLength; i++){
		bool flag=false;
		if(find(mem,mem+cnt,a[i]) == mem+cnt){
			mem[l++]=a[i];
			if(l==memSize) l=0;
			if(cnt<memSize) cnt++;
			flag=true;
		}
	
		printf("%d: ", a[i]);
		for(int i=0; i<memSize; i++){
			printf("%d ", mem[i]);
		}
		if(flag) printf(" ¡Ì");
		printf("\n");
	}
	return 0;
}
