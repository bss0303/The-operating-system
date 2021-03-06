﻿// FIFO1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

int a[30]={7,0,2,1,5,3,5,1,3,2,1,2,1,1,1,2,3,4,1,1};
int aLength=20;
int mem[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},memSize=3;								

void fifo()
{
	int mem[3];//内存页面
	int menSize=3;//内存页面大小
	int loc=0;//每次页面替换的位置
	int count=0;//记录缺页中断的次数
	int i=0,j=0;
	for( i=0;i<aLength;i++)
	{ 
		for( j=0;j<menSize;j++)
		{
			if(a[i]==mem[j])//访问的页面已在内存中
			{
				cout<<endl;
			    break;
			}
		}
		if(j==menSize)//访问的页面不在内存中，发生页面置换
		{
			mem[loc]=a[i];
		    loc++;
			count++;
			for(j=0;j<memSize;j++)//打印内存页面序列
			{
				if(mem[j]==-1)
					cout<<" ";
				cout<<mem[j]<<" ";
			}
			cout<<endl;
		}
		if(loc==memSize)
			loc=0;
	}
	cout<<"缺页中断的次数为："<<count<<endl;
}
int main()
{
	fifo();
	return 0;
}
   