#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int a[30]={7,0,2,1,5,3,5,1,3,2,1,2,1,1,1,2,3,4,1,1};//访问序列 
int aLength=20;

map<int, int> mp;												//OPT计数使用 

int mem[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, memSize=3;							//内存 

int ff(){													/*寻找内存中要置换出的页*/
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
	int cnt = 0;//内存被占用个数 
	for(int i=0; i<aLength; i++){//预处理字典，统计个数 
		int &tmpi = a[i];
		mp[tmpi]++;
	}
	
	for(int i=0; i<aLength; i++){
		if(find(mem,mem+cnt, a[i]) == mem+cnt){//如果发生缺页 
			if(cnt<memSize){
				mem[cnt++] = a[i];
			}else{
				int x=ff();
				mem[x] = a[i];
			}
		}
		mp[a[i]]--;
	
		printf("%d: ", a[i]);
		for(int j=0; j<memSize; j++){
			if(j<cnt) printf("%d", mem[j]);
			else printf(" ");
			printf(" ");
		}
		printf("\n");
	}
	return 0;
} 
