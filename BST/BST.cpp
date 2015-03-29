
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//���ṹ
struct node
{
	int key;//�ؼ�����
	node * lchild;
	node * rchild;
	node()
	{
		lchild=rchild=NULL;
	}
};

//�����������ڵ����
int  Insert(node * &root,int key)
{
	if(root==NULL)
	{
		root=new node;
		root->key=key;
		return 1;//����ɹ�
	}
	else if(key==root->key)//�Ѿ�����
		return 0;//����ʧ��

	else if(key<root->key)//�嵽������
		return Insert(root->lchild,key);
	else
		return Insert(root->rchild,key);

}

//��������������
void Create(node * &root)
{
	int a[]={9,7,10,5,8,15,4,6,14};//�������
	for(int i=0;i<9;i++)
	   Insert(root,a[i]);//�ڵ����
	
}

//�ڵ����
node * Search(node * root,int key)
{
	if(root==NULL)
		return NULL;
	if(root->key==key)
		return root;
	if(root->key>key)
		return Search(root->lchild,key);//����������
	else
		return Search(root->rchild,key);//����������
}

void Delete2(node * & root, node * & right)//Ҫ���������ͣ���ΪҪ�����������
{
	node * temp;
	if(right->rchild!=NULL)//���ҵ������������µĽ�㣬�����������ֵ,��ʱ��rightָ����������
		Delete2(root,right->rchild);
	else
	{
		root->key=right->key;
		temp=right;
		right=NULL;
		delete temp;
	}
}

int Delete(node * &root,int key)
{
	if(root==NULL)
		return 0;//����ʧ��
	else
	{
		if(root->key>key)
			return Delete(root->lchild,key);//�ݹ�������ɾ��

		else if(root->key<key)
			return Delete(root->rchild,key);//�ݹ�������ɾ��
		
		else//�ҵ���keyֵ�Ľ��
		{
			//ɾ��
			if(root->rchild==NULL&&root->lchild==NULL)//û��������������Ҷ�ӽ�㣬ֱ��ɾ��
			{
				node * temp=root;
				root=NULL;
				delete temp;
				
				//2.delete root;��ɾ��Ҷ�ӽ�㣬��������lchild��rchildû��NULL
			}

			else if(root->rchild==NULL)//û����������
			{
				 node *temp=root;
				 root=root->lchild;
				 delete temp;
			}
			else if(root->lchild==NULL)//û��������
			{
				 node *temp=root;
				 root=root->rchild;
				 delete temp;
			}
			//����������
			else
			{
				Delete2(root,root->lchild);//Ҫ���������ͣ���ΪҪ�����������
				 
			}
			return 1;
		}


	}
}



int main()
{
	node *root=NULL;//���ڵ�
	Create(root);

	node * ok=Search(root,7);
	cout<<ok->lchild->key<<endl;
	Delete(root,7);
	
	return 0;
}

