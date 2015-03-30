
//ƽ�������

#include<iostream>
#include<queue>
using namespace std;

//ƽ��������Ľ�������������

//�����ṹ
struct node
{
	int data;//����
	int bf;//ƽ������
	node*lchild,*rchild;
	node()
	{
		lchild=rchild=NULL;
	}
};

//ƽ������Ϊ  �������߶�-�������߶�
#define LH +1   //��ʾ��߸�  ��1
#define EH 0    //��ʾ�ȸ�    ��0
#define RH -1  //��ʾ�ұ߸�   С���󣬼�-1

void R_rotate(node * &p){//������
	node * lc=p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}
void L_rotata(node * &p){//������
	node * rc=p->rchild;
	p->rchild=rc->lchild;
	rc->lchild=p;
	p=rc;

}





void Leftbalance(node * &T){//��������ƽ�⴦��
	node * lc=T->lchild;
	switch(lc->bf){
	//LL�����
	case LH:
		T->bf=lc->bf=EH;
		R_rotate(T);
		break;

	case RH://LR�������ͬʱ���rd�ϵĲ�ͬ��������ж�T��lc��ƽ�����ӵ�����
		node * rd=lc->rchild;
		switch(rd->bf){
			case LH:T->bf=RH; lc->bf=EH;break;
			case EH:T->bf=lc->bf=EH;break;
			case RH:T->bf=EH;lc->bf=LH;break;
		}
		rd->bf=EH;
		L_rotata(T->lchild);
		R_rotate(T);
	}


}


void Rightbalance(node * &T)//��������ƽ�⴦������������ƽ�⴦������
{
	node * rc=T->rchild;
	switch (rc->bf)
	{
		case RH:
			T->bf=rc->bf=EH;
			L_rotata(T);break;
		case LH:
		   node * ld=rc->lchild;
			switch(ld->bf){
		case LH:
			T->bf=EH; rc->bf=RH;break;
		case EH:
			T->bf=rc->bf=EH;break;
		case RH:
			T->bf=LH; rc->bf=EH;break;

			}
			ld->bf=EH;
			R_rotate(T->rchild);
			L_rotata(T);
	}

}


bool InsertAVL(node * &T,int e,bool &taller){
	if(!T){//�˽��Ϊ�գ�����룬�����øõ�ƽ������Ϊ0��tallerΪtrue��������
		T=new node;
		T->data =e; 
		T->lchild=T->rchild=NULL;  
		T->bf=EH;
		taller=true;
	}
	else
	{
		if(e==T->data)//�Ѿ����ڣ������룬����0;
		{
			taller =false;
			return 0;
		}
		if(e<T->data)//���eС�ڱ���㣬�������������������
		{
			 if(!InsertAVL(T->lchild,e,taller))
				 return 0;//δ���룬����0;
			 if(taller)//�Ѿ����뵽������������Ҫ���ƽ��ȣ�
			 {        //ע�⣡���ƽ������������ϵģ��ĸ�����ʧȥƽ�⣬��Ըý�����ƽ�����
				switch(T->bf)
				{
				   case LH:   //����㱾������Ҹߣ����ڲ����ˣ�����Ҫ��ƽ�⴦��
					  Leftbalance(T);
					  taller=false; 
					  break;
				   case EH:  //�����ȸߣ����ڲ����ˣ����Ա����ƽ������Ϊ1;taller ��Ϊfalse ��������һ���ݹ��ʱ�򣬲���Ҫ�ڼ��ƽ�⣻
					  T->bf=LH; 
					  taller=true;
					  break;
				   case RH://�����ұ߸ߣ����ڲ����ˣ����Ա����ƽ������Ϊ0;taller ��Ϊfalse ��������һ���ݹ��ʱ�򣬲���Ҫ�ڼ��ƽ�⣻
					  T->bf =EH; 
					  taller=false; 
					  break;
				}

			 }

		}
		else
		{//���������в���
				if(!InsertAVL(T->rchild,e,taller))
					return 0;//δ���룬����0;
				if(taller)
				{ //ͬ�ϣ����ƽ��
				  switch(T->bf)
				  {
					case LH://������ߣ����ڵȸ�
						T->bf=EH; 
						taller=false; 
						break;
					case EH://����ƽ�⣬�����������ˣ����Ա����ƽ������Ϊ-1.tallerΪtrue��������һ���ݹ��Ǽ������ƽ�⣬
						T->bf=RH;
						taller=true;
						break;
					case RH://�����Ҹߣ��������������ˣ�����ʧȥƽ�⣬�Ըýڵ����ƽ�⴦��
						Rightbalance(T);
						taller=false;
						break;
				  }
			}
		}


	}

	return 1;
}

//�������
void cengcitravel(node * T){
    node * p;
    queue<node *>sq;
    sq.push(T);
	while(!sq.empty()){
	 p=sq.front();
	 cout<<p->data<<" ";
	if(p->lchild)sq.push(p->lchild);
	if(p->rchild)sq.push(p->rchild);
	 sq.pop();
	}

}


int main(){
	node * T=NULL;
	bool f=false;//��ʾ�Ƿ����ɹ����ɹ�Ϊtrue

	int data[9]={16,3,7,11,9,26,18,14,15};
	for(int i=0;i<9;i++)
	{
		InsertAVL(T,data[i],f);//������
	}
	
	cengcitravel(T);//�������
	cout<<endl;

	return 0;
}