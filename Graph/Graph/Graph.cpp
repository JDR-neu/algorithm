// Graph.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

//ʹ���ڽӱ�洢ͼ����Ϣ

//�����ڽӱ���Ľṹ
struct node
{
	int data;//�����
	int weight;//Ȩֵ
	node * next;//��һ������ָ��
	node()
	{
		next=NULL;
	}
};

//�����ڽӱ�ı�ͷ
struct Head
{
	int data;//�����
	node * first;//ִ�е�һ�����
	Head()
    {
		first=NULL;
	}
};

//����ջ����ջʵ�������������
struct shed
{
	int data[100];
	int top;
};

//�����ڽӱ�
void Create(Head * & head)
{
	
	while(true)
	{
		int name,wg;
		cin>>name;
		if(name==-1)//����-1��ʾ�������
			break;
		cin>>wg;
		node * temp=new node;
		temp->data=name;
		temp->weight=wg;
		if(head->first==NULL)
			head->first=temp;
		else
		{
			temp->next=head->first;
			head->first=temp;
		}


	}

}


void show(Head * head[])
{
	cout<<head[1]->first->data<<endl;
}

//�ݹ������������
void DFS_DG(Head *head[],int v,int visited[])
{
	node * p;
	visited[v]=1;
	cout<<v<<endl;
	p=head[v]->first;
	while(p!=NULL)
	{
		if(visited[p->data]==0)
			DFS_DG(head,p->data,visited);
		p=p->next;
	}
}

void DFS_Shep(Head *head[],int v,int visited[])
{

}
int main()
{
	
	int visited[5]={0};
	Head * head[5];//��ͷָ������
	for(int i=0;i<5;i++)
	{
		head[i]=new Head;
		head[i]->data=i;
		cout<<"��������"<<i<<"�ı��������Ȩֵ"<<endl;
		Create(head[i]);

	}
	while(true)
	{
		for(int i=0;i<5;i++)
			visited[i]=0;
		int ok;
		cout<<"��ʼ��Ϊ"<<endl;
		cin>>ok;
		if(ok==10)
			break;
	    DFS_DG(head,ok,visited);
	}
	
	return 0;
}

