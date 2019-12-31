#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int aAccessSequence[]={7,0,2,1,5,3,5,1,3,2,1,2,1,1,1,2,3,4,1,1};//访问序列 
int AccessSequenceLength=20;

map<int, int> mp;												//OPT计数使用 

int storage[3]={-1,-1,-1},cnt=0;								//内存 

int ff(){													/*寻找内存中要置换出的页*/
	int a=mp[storage[0]];
	int b=mp[storage[1]];
	int c=mp[storage[2]];
	if(a<b){
		if(a<c) return 0;
		else return 2;
	}else {
		if(b<c) return 1;
		else return 2;
	}
}

int main(){
	for(int i=0; i<AccessSequenceLength; i++){
		int &tmpi = aAccessSequence[i];
		mp[tmpi]++;
	}
	
	for(int i=0; i<AccessSequenceLength; i++){
		if(find(storage,storage+cnt, aAccessSequence[i]) == storage+cnt){
			if(cnt<3){
				storage[cnt++] = aAccessSequence[i];
			}else{
				int x=ff();
				mp[x]--;
				storage[x] = aAccessSequence[i];
			}	
		}
		printf("%d: ", aAccessSequence[i]);
		for(int i=0; i<3; i++){
			printf("%d ", storage[i]);
		}
		printf("\n");
	}
	return 0;
} 
