// KMP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include<string>
using namespace std;

int BF(string s,string t)//Brute-Force,��ƥ���㷨
{
	int origin=-1;//ģʽƥ�����ʼλ��
	for(int i=0;i<s.size();i++)
	{
		int k;
		for(k=0;k<t.size();k++)
		{
			if(s[i+k]!=t[k])
				break;
		}
		if(k==t.size())//ƥ��ɹ�
		{
			origin=i;
			break;
		}
	}
	return origin;
}

//����next���飬tΪ�����ַ���
void calculateNext(int * & next,string t)
{
	for(int j=0;j<t.size();j++)
	{
		bool state=true;//�Ƿ��ǵ���0�����
		if(j==0)
			*next=-1;
		else 
		{
			int k=j-1;//0<k<j,��ȡ����k
			while(k>0)
			{
				string str1="",str2="";
				for(int i=0;i<=k-1;i++)
				{
					str1=str1+t[i];
					str2=str2+t[j-k+i];
				}
				if(str1==str2)//����p[0....k-1]=p[j-k...j-1];
				{	
					*(next+j)=k;
					state=false;//���ǵ���0�����
					break;
				}
				k--;
				
			}
			if(state)
				*(next+j)=0;
		}

	}
}

int main()
{
	
	string s="ababcabcacbab";//����
	string t="abcac";//ģʽ��

	int *next=new int[t.size()];//ģʽ����next����

	calculateNext(next,t);
	for(int i=0;i<t.size();i++)
		cout<<*(next+i)<<endl;
	
	int BForigin=BF(s,t);
	cout<<"ģʽƥ���λ���ǣ�"<<BForigin<<"->"<<BForigin+t.size()<<endl;
	return 0;
}

