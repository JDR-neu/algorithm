// maze.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//����ջ�Ľṹ
struct node
{
	int x;
	int y;
	bool state;//�����Ƿ����ͨ��
	node *next;
	node()
	{
		next=NULL;
		state=true;//Ĭ��Ϊfalse������ͨ��
	}
};
//��ջ---���뵽head֮��
void Push(node * &head,int x,int y)
{
	
     node * temp=new node;
	 temp->x=x;temp->y=y;
	 if(head==NULL)
		 head=temp;
	 else
	 {
		 temp->next=head;
		 head=temp;
	 }

}

//��ջ--ȡhead��
node Pop(node * &head)
{
	node * ok;node temp;
	if(head!=NULL)
	{
		temp.x=head->x;
		temp.y=head->y;temp.state=head->state;
		ok=head;
		head=head->next;
		delete ok;
	}
	return temp;
	
}

//�鿴ջ���Ƿ񺬴�Ԫ��
bool GetItem(node *head)
{
	while(head!=NULL)
	{
		
	}
	return true;
}

int main()
{
	//0��ʾ����ͨ��
	int map[4][4]={
		{0,0,1,0},
		{1,0,0,0},
		{0,0,1,1},
		{1,0,0,0}
	};
	node *head=NULL;//ջ��ͷָ��
	
	for(int i=0;i<10;i++)
	{
		
		Push(head,i,i);

	}
	Pop(head);	Pop(head);	Pop(head);	Pop(head);	
	node * ok=head;
	while(ok!=NULL)
	{
		cout<<"xx: "<<ok->x<<"  yy: "<<ok->y<<endl;
		ok=ok->next;
	}
	return 0;
}

