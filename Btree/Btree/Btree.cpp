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
//����������
void CreateTree(node * & root,string tree)
{
	 char data;
	 cin>>data;
	 if(data!='#')
	 {
		 root=new node;
		 root->data=data;
		 cout<<"��"<<endl;
		 CreateTree(root->lchild,tree);
		 cout<<"you"<<endl;
		 CreateTree(root->rchild,tree);
	 }
}


int main()
{
	string tree;
	node * root;
		root=NULL;//���ڵ�
	//cout<<"�밴�����������Ҫ���ɵĶ��������ݣ�#����ս��: "<<endl;	
	//cin>>tree;
	CreateTree(root,tree);//���ɶ�����

	return 0;
}

