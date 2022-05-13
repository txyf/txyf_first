#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct Node
{
	int hangbanhao;//�����
    char qifeichengshi[10];//��ɳ���
	char jiangluochengshi[10];//�������
	char qifeishijian[10];//���ʱ��
	char jiangluoshijian[10];//����ʱ��
    int zuoweishu;//��λ��
	int piaojia;//Ʊ��
    struct Node *next;//����ָ����
}LNode,*LinkList;//���庽����Ϣ LinkListΪָ��ṹ��LNode��ָ������


typedef struct CK
{
  char name[10];//�˿�����
  char id[18];//�˿����֤��
  struct CK *next;//����ָ����
}ck,*cke;//�˿���Ϣ


void import(int n,LinkList &L)//¼�뺽�ຯ��: nΪ��Ҫ¼�뺽�������:
{//����һ����ͷ���ĵ�����L
    L=(LinkList)malloc(sizeof(LNode));//�����ռ�
	L->next=NULL;//ͷ����ָ�����ÿ�
	LNode * tail=L;//��β����βָ�룬�ȼ�LinkList tail=L;
    for(int i=0; i<n; i++)//�����ֵ
     {
		LNode *p=(LinkList)malloc(sizeof(LNode));//����һ��p���
        cout<<"�������"<<i+1<<"������ĺ���� ";
        cin>>p->hangbanhao;
		cout<<"�������"<<i+1<<"���������ɳ��� ";
        cin>>p->qifeichengshi;
		cout<<"�������"<<i+1<<"������Ľ������ ";
        cin>>p->jiangluochengshi;
		cout<<"�������"<<i+1<<"����������ʱ�� ";
		cin>>p->qifeishijian;
		cout<<"�������"<<i+1<<"������Ľ���ʱ�� ";
		cin>>p->jiangluoshijian;
	    cout<<"�������"<<i+1<<"���������λ�� ";
		cin>>p->zuoweishu;
		cout<<"�������"<<i+1<<"�������Ʊ��";
		cin>>p->piaojia;
		p->next=NULL;//ͷ����ָ�����ÿ�
		tail->next=p;//���½�����β��
		tail=p;//����Ľ���Ϊβ��㣬β�巨
	}
}
//д�뱾���ļ�������ȡ�����ʾ


void show_L(LinkList &L)//��������Ʊ��Ϣ
{
  ofstream out("out.txt");//ʵ����һ������
   if (out.is_open())
   {
      LinkList p=L->next;
      while(p)
      {
		out<<"�����:";
	    out<<p->hangbanhao;
        out<<" ��ɳ���:";
	    out <<p->qifeichengshi;
		out<<" �������:";
		out <<p->jiangluochengshi;
		out<<" ���ʱ��:";
		out <<p->qifeishijian;
        out<<" ����ʱ��:";
		out <<p->jiangluoshijian;
		out<<" ��λ��:";
		out<<p->zuoweishu;
		out<<" Ʊ��:";
		out<<p->piaojia;
		out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
	    p=p->next;
	  }
  }
   out.close(); //д��
    char buffer[256];
    ifstream in("out.txt");
	if (! in.is_open())
       { cout << "Error opening file"; exit (1); }
       while (!in.eof() )
       {
           in.getline (buffer,100);
           cout << buffer << endl;
       }
}

//������Ų���
LinkList GetElem_L(LinkList &L,int e)
{
      LinkList p=L->next;
      while(p)
	  {
		if(p->hangbanhao!=e)
			p=p->next;
		else return p;
	  }
     return 0;
}

//�������𽵳��в���
LinkList GetElem_Lc(LinkList &L,char qi[10],char ji[10])
{
      LinkList p=L->next;
      while(p)
	  {
		if(strcmp(p->qifeichengshi,qi)!=0||strcmp(p->jiangluochengshi,ji)!=0)
			p=p->next;
		else return p;
	  }
      return 0;
}


//ɾ��
int ListDelete_L(LinkList &L,int e){
	LinkList p=L;
	while(p->next&&p->next->hangbanhao!=e){
		p=p->next;//ֱ�����ҵ�Ҫɾ���Ľ��
	}
	if(!p->next)
		return 0;
	LinkList q=p->next;
	p->next=q->next;//p->next=p->next->next;
	free(q);//����q����Ҫɾ���Ľ��
	return 1;
}


//����
int ListInsert_L(LinkList &L,int i){
	LinkList p=L;//iΪ�����λ��
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
		return 0;
	LNode *s=(LinkList)malloc(sizeof(LNode));
	cout<<"���뺽���:";
	cin>>s->hangbanhao;
	cout<<"������ɳ���:";
	cin>>s->qifeichengshi;
	cout<<"���뽵�����:";
	cin>>s->jiangluochengshi;
	cout<<"�������ʱ��:";
	cin>>s->qifeishijian;
	cout<<"���뽵��ʱ��:";
	cin>>s->jiangluoshijian;
	cout<<"������λ��:";
	cin>>s->zuoweishu;
	cout<<"����Ʊ��:";
	cin>>s->piaojia;
	s->next=p->next;
	p->next=s;//s->next=p->next;p->next=s;
	return 1;
}


//�޸�
LinkList xiugai(LinkList &L,int yxg)
{
  LinkList q=L->next;
      while(q)
	  {
		if(q->hangbanhao!=yxg)
			q=q->next;
		else return q;
	  }
  return 0;
}


//�˿���Ϣ¼��
void importren(int n,cke &C)//¼�뺽�ຯ��: nΪ��Ҫ¼�뺽�������:
{
    C=(cke)malloc(sizeof(ck));
	C->next=NULL;
	ck*ta=C;
    for(int i=0; i<n; i++)
     {
		ck *p=(cke)malloc(sizeof(ck));//���Ǵ���һ��p��㣬�ؼ�����д����LNdoe *p;
        cout<<"�������"<<i+1<<"���˿͵����� ";
        cin>>p->name;
		cout<<"�������"<<i+1<<"����������֤ID ";
        cin>>p->id;
         p->next=NULL;
		ta->next=p;
		ta=p;//β�巨������ѭ����ͼ��֪��tailָ��ʼ�������
	}
}


//��Ʊ�˿���Ϣ�ͺ�����Ϣд�뱾�غͶ�ȡ
void show_dp(cke &C,LinkList &R)
{
  ofstream out("dinpiao.txt");//ʵ����һ������
   if (out.is_open())
   {
      cke p=C->next;
      while(p){
		out<<"���� ";
	    out<<p->name;
	    out<<"  ���֤ID ";
		out<<p->id;
		out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
	    p=p->next;
	  }
	  if(R->zuoweishu-1>=0)
	  {
	   out<<"�����:"<<R->hangbanhao;
	   out<<" ��ɳ���:"<<R->qifeichengshi;
	   out<<" �������:"<<R->jiangluochengshi;
	   out<<" ���ʱ��:"<<R->qifeishijian;
	   out<<" ����ʱ��:"<<R->jiangluoshijian;
	   out<<" ��λ��:"<<R->zuoweishu-1;//��Ʊ֮����λ����һ
	   out<<" Ʊ��:"<<R->piaojia;
	   out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
	   out<<"��Ʊ�ɹ�";
	   out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
	  }
	  else
	  {
		out<<"�����:"<<R->hangbanhao;
	    out<<" ��ɳ���:"<<R->qifeichengshi;
	    out<<" �������:"<<R->jiangluochengshi;
	    out<<" ���ʱ��:"<<R->qifeishijian;
	    out<<" ����ʱ��:"<<R->jiangluoshijian;
	    out<<" ��λ��:"<<R->zuoweishu;
	    out<<" Ʊ��:"<<R->piaojia;
	    out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
        out<<"�ú�������Ʊ,��ѡ����������";
		out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
	  }
   }
   out.close(); //д��
    char buffer[256];
    ifstream in("dinpiao.txt");
	if (! in.is_open())
       { cout << "Error opening file"; exit (1); }
       while (!in.eof() )
       {
           in.getline (buffer,100);
           cout << buffer << endl;
       }
}

//��Ʊ�˿���Ϣ�ͺ�����Ϣд�뱾�غͶ�ȡ
void show_tp(cke &C,LinkList &R)
{
  ofstream out("dinpiao.txt");//ʵ����һ������
   if (out.is_open())
   {
      cke p=C->next;
      while(p){
		out<<"���� ";
	    out<<p->name;
	    out<<"���֤ID ";
		out<<p->id;
		out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
	    p=p->next;
	  }
	  out<<"����� "<<R->hangbanhao;
	  out<<" ��ɳ���:"<<R->qifeichengshi;
	  out<<" �������:"<<R->jiangluochengshi;
	  out<<" ���ʱ��:"<<R->qifeishijian;
	  out<<" ����ʱ��:"<<R->jiangluoshijian;
	  out<<" ��λ��:"<<R->zuoweishu;//��Ʊ֮����Ҫ��1�����������λ��;
	  out<<" Ʊ��:"<<R->piaojia;
	  out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
	  out<<"��Ʊ�ɹ�";
	  out<< "\n";//���ڻ��У�������in.getline�Ĺؼ�
   }
   out.close(); //д��
    char buffer[256];
    ifstream in("dinpiao.txt");
	if (! in.is_open())
       { cout << "Error opening file"; exit (1); }
       while (!in.eof() )
       {
           in.getline (buffer,100);
           cout << buffer << endl;
       }
}

void menu()//��ʾ�˵�����
{
    cout<<"=================================��ӭʹ�ú��ն�Ʊϵͳ==============================="<<endl;
    cout<<"*                                1����¼�뺽����Ϣ                                 *"<<endl;
    cout<<"*                                2���ݺ���Ų��Һ���                               *"<<endl;
	cout<<"*                                3�����𽵳��в��Һ���                             *"<<endl;
    cout<<"*                                4ɾ������                                         *"<<endl;
    cout<<"*                                5���뺽��                                         *"<<endl;
    cout<<"*                                6�޸ĺ���                                         *"<<endl;
	cout<<"*                                7��Ʊ¼��˿���Ϣ                                 *"<<endl;
	cout<<"*                                8��Ʊ                                             *"<<endl;
	cout<<"===================================================================================="<<endl;
}
int main()
{
   LinkList L;//L��ָ�� ����
   cke C;//�˿�
    while(1)
	{
      menu();
      int caozuo;
      cout<<"��ѡ�����";
      cin>>caozuo;
      switch(caozuo)
	  {
	case 1:
//����
	  int num;
      cout<<"������Ҫ¼��ĺ�����:";
      cin>>num;
      cout<<endl;
      import(num,L);//¼�뺽�ຯ��: nΪ��Ҫ¼�뺽�������:
      cout<<endl;
      cout<<"������Ϣ¼��ɹ�";
      cout<<endl<<endl;
//д�뱾���ļ�������ȡ�����ʾ
      show_L(L);
	  break;
    case 2:
//���ݺ���Ų���
      int dchbh;//���ݺ���Ų���
 	  printf("��������麽���:");
      cin>>dchbh;
	  LinkList p;
	  p=GetElem_L(L,dchbh);//����
	  cout<<"���麽��Ϊ:";
	  cout<<"�����:"<<p->hangbanhao;
	  cout<<" ��ɳ���:"<<p->qifeichengshi;
	  cout<<" �������:"<<p->jiangluochengshi;
	  cout<<" ���ʱ��:"<<p->qifeishijian;
	  cout<<" ����ʱ��:"<<p->jiangluoshijian;
	  cout<<" ��λ��:"<<p->zuoweishu;
	  cout<<" Ʊ��:"<<p->piaojia;
      cout<<endl<<endl;
      break;
    case 3:
//�����𽵳��в���
       char qi[10];
	   char ji[10];
	   printf("��������麽���𽵳���:");
	   cout<<"������ɳ���:";
	   cin>>qi;
	   cout<<"���뽵�����:";
	   cin>>ji;
	   LinkList J;
	   J=GetElem_Lc(L,qi,ji);//����
	   cout<<"���麽��Ϊ:";
	   cout<<"�����:"<<J->hangbanhao;
	   cout<<" ��ɳ���:"<<J->qifeichengshi;
	   cout<<" �������:"<<J->jiangluochengshi;
	   cout<<" ���ʱ��:"<<J->qifeishijian;
	   cout<<" ����ʱ��:"<<J->jiangluoshijian;
	   cout<<" ��λ��:"<<J->zuoweishu;
	   cout<<" Ʊ��:"<<J->piaojia;
       cout<<endl<<endl;
	   break;
    case 4:
//ɾ��
      int shanchu;
	  printf("������Ҫɾ���ĺ����:");
	  scanf("%d",&shanchu);
	  ListDelete_L(L,shanchu);//ɾ��
	  show_L(L);
	  cout<<endl<<endl;
	  break;
    case 5:
//����
   //����λ��ʼ���ڵ�һ��
      ListInsert_L(L,1);//����
      show_L(L);
	  cout<<endl<<endl;
      break;
	case 6:
//�޸�
      printf("������Ҫ�޸ĵĺ����:");
      int yxg;
      cin>>yxg;
      LinkList q;
	  q=xiugai(L,yxg);//�޸�
	  cout<<"������޸�Ϊ:";
	  cin>>q->hangbanhao;
	  cout<<"������ɳ����޸�Ϊ:";
	  cin>>q->qifeichengshi;
	  cout<<"���ཱུ������޸�Ϊ:";
	  cin>>q->jiangluochengshi;
	  cout<<"�������ʱ���޸�Ϊ:";
	  cin>>q->qifeishijian;
	  cout<<"���ཱུ��ʱ���޸�Ϊ:";
	  cin>>q->jiangluoshijian;
	  cout<<"������λ���޸�Ϊ:";
      cin>>q->zuoweishu;
	  cout<<"����Ʊ���޸�Ϊ:";
      cin>>q->piaojia;
      show_L(L);
	  cout<<endl<<endl;
	  break;
    case 7:
//��Ʊ
      int renshu;
      cout<<"��ѡ����Ҫ��Ʊ������:";
      cin>>renshu;
      cout<<endl;
      importren(renshu,C);//¼��˿���Ϣ
      cout<<endl;
      cout<<"�˿���Ϣ¼��ɹ�";
      cout<<endl;
	  int m;
	  cout<<"��������Ҫ���ĺ����:";
	  cin>>m;
	  cout<<endl<<endl;
	  LinkList R;
      R=GetElem_L(L,m);//���ҳ˿Ͷ��ĺ���
	  show_dp(C,R);//д�뱾���ļ�������ȡ�����ʾ
	  cout<<endl<<endl;
      break;
    case 8:
//��Ʊ
     cout<<"��������Ҫ��Ʊ�ĺ����:";
	 int yt;
	 cin>>yt;
	 cout<<endl<<endl;
	 LinkList K;
     K=GetElem_L(L,yt);//���ҳ˿Ͷ��ĺ���
	 show_tp(C,K);//д�뱾���ļ�������ȡ�����ʾ
     cout<<endl<<endl;
	 break;
	  }//swith�Ĵ�����
	}//while�Ĵ�����
  return 0;
}//�������Ĵ�����


