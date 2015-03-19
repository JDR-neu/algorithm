// maze.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;

#define BLOCKNUM 4//�Թ���ͼ��С

//��Ҫ���⣬������������ѭ��

//����ջ�Ľṹ
struct node
{
	int x;//��
	int y;//��  ��Ӧmap[x][y]
	int direction;//1�������ң�2�������£�3��������4�������ϣ����̽������
	node *next;
	node()
	{
		next=NULL;
	}
};

//��ջ---���뵽head֮��
void Push(node * &head,int x,int y,int direction)
{
	
     node * temp=new node;
	 temp->x=x;temp->y=y;temp->direction=direction;
	 if(head==NULL)
		 head=temp;
	 else
	 {
		 temp->next=head;
		 head=temp;
	 }

}

//��ջ--ȡhead��
void Pop(node * &head)
{
	node * ok;
	if(head!=NULL)
	{
		
		ok=head;
		head=head->next;
		delete ok;
	}
	
	
}

//��ȡջ��Ԫ��
node Getpop(node * head)
{
	node temp;
	temp.x=head->x;
	temp.y=head->y;
	temp.direction=head->direction;
	return temp;
}


//�޸�ջ��Ԫ�ط���
void Change(node * & head,int drection)
{
	head->direction=drection;
}


int main()
{
	//0��ʾ����ͨ��
	int map[BLOCKNUM][BLOCKNUM]={
		{0,0,1,0},
		{1,0,0,0},
		{0,0,1,1},
		{1,0,0,0}
	};
	node *head=NULL;//ջ��ͷָ��
	Push(head,0,0,1);//��ڽ�ջ
	
	int i=0;
	while(i<10)
	{
		i++;
		//����һ�����̽��
		bool sea=true;
		node  temp;
		int dre=-1;//��¼ǰ���ķ��򣬷�ֹ����������ѭ��
		while(sea)
		{
			temp=Getpop(head);
			
			cout<<temp.direction<<endl;
			switch (temp.direction)
			{
			case 1:
				//cout<<temp.x<<"  huoqu "<<temp.y<<"  map[temp.x+1][temp.y]:"<<map[temp.x+1][temp.y]<<endl;
				if((temp.y+1)<BLOCKNUM&&map[temp.x][temp.y+1]==0)
				{
					Push(head,temp.x,temp.y+1,1);
					sea=false;
					
				}
				else
				{
					Change(head,temp.direction+1);		
				}
			
				break;
			case 2:
				if((temp.x+1)<BLOCKNUM&&map[temp.x+1][temp.y]==0)
				{
					Push(head,temp.x+1,temp.y,1);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 3:
				if((temp.y-1)>=0&&map[temp.x][temp.y-1]==0)
				{
					Push(head,temp.x,temp.y-1,1);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 4:
				if((temp.x-1)>=0&&map[temp.x-1][temp.y]==0)
				{
					Push(head,temp.x-1,temp.y,1);
					sea=false;
				}
				else
				{
					Pop(head);
				}
				break;
			default:
				break;
			}
		}
	}
	node *kk=head;
	while(kk!=NULL)
	{
		cout<<kk->x<<"  "<<kk->y<<"  "<<kk->direction<<endl;
		kk=kk->next;
	}

	
	return 0;
}

