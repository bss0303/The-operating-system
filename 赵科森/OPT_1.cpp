#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int a[30]={7,0,2,1,5,3,5,1,3,2,1,2,1,1,1,2,3,4,1,1};//�������� 
int aLength=20;

map<int, int> mp;												//OPT����ʹ�� 

int mem[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, memSize=3;							//�ڴ� 

int ff(){													/*Ѱ���ڴ���Ҫ�û�����ҳ*/
	int minkey=mp[mem[0]], l=0;
	for(int i=1; i<memSize; i++){
		if(minkey > mp[mem[i]]){
			minkey=mp[mem[i]];
			l=i;
		}
	}
	return l;
}

int main(){
	int cnt = 0;//�ڴ汻ռ�ø��� 
	for(int i=0; i<aLength; i++){//Ԥ�����ֵ䣬ͳ�Ƹ��� 
		int &tmpi = a[i];
		mp[tmpi]++;
	}
	
	for(int i=0; i<aLength; i++){
		if(find(mem,mem+cnt, a[i]) == mem+cnt){//�������ȱҳ 
			if(cnt<memSize){
				mem[cnt++] = a[i];
			}else{
				int x=ff();
				mem[x] = a[i];
			}
		}
		mp[a[i]]--;
		
		printf("%d: ", a[i]);
		for(int i=0; i<memSize; i++){
			if(i<cnt) printf("%d", mem[i]);
			else printf(" ");
			printf(" ");
		}
		printf("\n");
	}
	return 0;
} 
