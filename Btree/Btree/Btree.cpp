// Btree.cpp : �������̨Ӧ�ó������ڵ㡣
//
//������ʵ��

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

//�������Ľṹ
struct node
{
	node * lchild;
	node * rchild;
	string data;
	//��ʼ��
	node()
	{
		lchild=rchild=NULL;
	}
};
//����������--�����������Ҫ���ɵĶ��������ݣ�#����ս��
void CreateTree(node * & root)
{
	 char data;
	 cin>>data;
	 if(data!='#')
	 {
		 root=new node;
		 root->data=data;
		 cout<<"zou"<<endl;
		 CreateTree(root->lchild);
		 cout<<"you"<<endl;
		 CreateTree(root->rchild);
		 cout<<"endl"<<endl;
	 }
}

//���������Ƿ��������aim
bool Findnode(node * & root,string aim)
{
	if(root==NULL)//����
		return false;
	else
	{
		if(root->data==aim)
			return true;
		else
		{
			Findnode(root->lchild,aim);
			Findnode(root->lchild,aim);
		}

	}
}

int main()
{
	node * root=NULL;//���ڵ�
	CreateTree(root);//���ɶ�����
	
	return 0;
}

