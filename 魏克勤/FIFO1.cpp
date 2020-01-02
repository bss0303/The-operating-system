// FIFO1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[20]={1,3,4,2,0,3,0,4,2,3,0,3,2,1,2,0,1,5,6,7};
	int mem[3];
	int loc=0;
	int i=0,j=0;
	for( i=0;i<20;i++)
	{ 
		for( j=0;j<3;j++)
		{
			if(a[i]==mem[j])
			{
				cout<<endl;
				break;
			}
		}
		if(j==3)
		{
			mem[loc]=a[i];
		    loc++;
		    if(i<3)
			{
				for(int m=0;m<=i;m++)
					cout<<mem[m]<<" ";
			    cout<<endl;
			}
			else
			{
		    for(int k=0;k<3;k++)
				cout<<mem[k]<<" ";
		    cout<<endl;
			}
		}
		if(loc>2)
			loc=0;
	}

}