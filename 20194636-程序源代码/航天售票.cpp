#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct Node
{
	int hangbanhao;//航班号
    char qifeichengshi[10];//起飞城市
	char jiangluochengshi[10];//降落城市
	char qifeishijian[10];//起飞时间
	char jiangluoshijian[10];//降落时间
    int zuoweishu;//座位数
	int piaojia;//票价
    struct Node *next;//结点的指针域
}LNode,*LinkList;//定义航班信息 LinkList为指向结构体LNode的指针类型


typedef struct CK
{
  char name[10];//乘客姓名
  char id[18];//乘客身份证号
  struct CK *next;//结点的指针域
}ck,*cke;//乘客信息


void import(int n,LinkList &L)//录入航班函数: n为所要录入航班的数量:
{//建立一个带头结点的单链表L
    L=(LinkList)malloc(sizeof(LNode));//申请表空间
	L->next=NULL;//头结点的指针域置空
	LNode * tail=L;//将尾赋给尾指针，等价LinkList tail=L;
    for(int i=0; i<n; i++)//逐个赋值
     {
		LNode *p=(LinkList)malloc(sizeof(LNode));//创建一个p结点
        cout<<"请输入第"<<i+1<<"个航班的航班号 ";
        cin>>p->hangbanhao;
		cout<<"请输入第"<<i+1<<"个航班的起飞城市 ";
        cin>>p->qifeichengshi;
		cout<<"请输入第"<<i+1<<"个航班的降落城市 ";
        cin>>p->jiangluochengshi;
		cout<<"请输入第"<<i+1<<"个航班的起飞时间 ";
		cin>>p->qifeishijian;
		cout<<"请输入第"<<i+1<<"个航班的降落时间 ";
		cin>>p->jiangluoshijian;
	    cout<<"请输入第"<<i+1<<"个航班的座位数 ";
		cin>>p->zuoweishu;
		cout<<"请输入第"<<i+1<<"个航班的票价";
		cin>>p->piaojia;
		p->next=NULL;//头结点的指针域置空
		tail->next=p;//将新结点插入尾部
		tail=p;//插入的结点变为尾结点，尾插法
	}
}
//写入本地文件，并读取输出显示


void show_L(LinkList &L)//输出浏览机票信息
{
  ofstream out("out.txt");//实例化一个对象
   if (out.is_open())
   {
      LinkList p=L->next;
      while(p)
      {
		out<<"航班号:";
	    out<<p->hangbanhao;
        out<<" 起飞城市:";
	    out <<p->qifeichengshi;
		out<<" 降落城市:";
		out <<p->jiangluochengshi;
		out<<" 起飞时间:";
		out <<p->qifeishijian;
        out<<" 降落时间:";
		out <<p->jiangluoshijian;
		out<<" 座位数:";
		out<<p->zuoweishu;
		out<<" 票价:";
		out<<p->piaojia;
		out<< "\n";//用于换行，是下面in.getline的关键
	    p=p->next;
	  }
  }
   out.close(); //写完
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

//按航班号查找
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

//按航班起降城市查找
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


//删除
int ListDelete_L(LinkList &L,int e){
	LinkList p=L;
	while(p->next&&p->next->hangbanhao!=e){
		p=p->next;//直到查找到要删除的结点
	}
	if(!p->next)
		return 0;
	LinkList q=p->next;
	p->next=q->next;//p->next=p->next->next;
	free(q);//本题q是需要删除的结点
	return 1;
}


//插入
int ListInsert_L(LinkList &L,int i){
	LinkList p=L;//i为插入的位置
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
		return 0;
	LNode *s=(LinkList)malloc(sizeof(LNode));
	cout<<"输入航班号:";
	cin>>s->hangbanhao;
	cout<<"输入起飞城市:";
	cin>>s->qifeichengshi;
	cout<<"输入降落城市:";
	cin>>s->jiangluochengshi;
	cout<<"输入起飞时间:";
	cin>>s->qifeishijian;
	cout<<"输入降落时间:";
	cin>>s->jiangluoshijian;
	cout<<"输入座位数:";
	cin>>s->zuoweishu;
	cout<<"输入票价:";
	cin>>s->piaojia;
	s->next=p->next;
	p->next=s;//s->next=p->next;p->next=s;
	return 1;
}


//修改
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


//乘客信息录入
void importren(int n,cke &C)//录入航班函数: n为所要录入航班的数量:
{
    C=(cke)malloc(sizeof(ck));
	C->next=NULL;
	ck*ta=C;
    for(int i=0; i<n; i++)
     {
		ck *p=(cke)malloc(sizeof(ck));//就是创建一个p结点，关键就是写法，LNdoe *p;
        cout<<"请输入第"<<i+1<<"个乘客的姓名 ";
        cin>>p->name;
		cout<<"请输入第"<<i+1<<"个航班的身份证ID ";
        cin>>p->id;
         p->next=NULL;
		ta->next=p;
		ta=p;//尾插法，根据循环画图可知，tail指针始终在最后
	}
}


//订票乘客信息和航班信息写入本地和读取
void show_dp(cke &C,LinkList &R)
{
  ofstream out("dinpiao.txt");//实例化一个对象
   if (out.is_open())
   {
      cke p=C->next;
      while(p){
		out<<"姓名 ";
	    out<<p->name;
	    out<<"  身份证ID ";
		out<<p->id;
		out<< "\n";//用于换行，是下面in.getline的关键
	    p=p->next;
	  }
	  if(R->zuoweishu-1>=0)
	  {
	   out<<"航班号:"<<R->hangbanhao;
	   out<<" 起飞城市:"<<R->qifeichengshi;
	   out<<" 降落城市:"<<R->jiangluochengshi;
	   out<<" 起飞时间:"<<R->qifeishijian;
	   out<<" 降落时间:"<<R->jiangluoshijian;
	   out<<" 座位数:"<<R->zuoweishu-1;//订票之后座位数减一
	   out<<" 票价:"<<R->piaojia;
	   out<< "\n";//用于换行，是下面in.getline的关键
	   out<<"订票成功";
	   out<< "\n";//用于换行，是下面in.getline的关键
	  }
	  else
	  {
		out<<"航班号:"<<R->hangbanhao;
	    out<<" 起飞城市:"<<R->qifeichengshi;
	    out<<" 降落城市:"<<R->jiangluochengshi;
	    out<<" 起飞时间:"<<R->qifeishijian;
	    out<<" 降落时间:"<<R->jiangluoshijian;
	    out<<" 座位数:"<<R->zuoweishu;
	    out<<" 票价:"<<R->piaojia;
	    out<< "\n";//用于换行，是下面in.getline的关键
        out<<"该航班暂无票,请选择其他航班";
		out<< "\n";//用于换行，是下面in.getline的关键
	  }
   }
   out.close(); //写完
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

//退票乘客信息和航班信息写入本地和读取
void show_tp(cke &C,LinkList &R)
{
  ofstream out("dinpiao.txt");//实例化一个对象
   if (out.is_open())
   {
      cke p=C->next;
      while(p){
		out<<"姓名 ";
	    out<<p->name;
	    out<<"身份证ID ";
		out<<p->id;
		out<< "\n";//用于换行，是下面in.getline的关键
	    p=p->next;
	  }
	  out<<"航班号 "<<R->hangbanhao;
	  out<<" 起飞城市:"<<R->qifeichengshi;
	  out<<" 降落城市:"<<R->jiangluochengshi;
	  out<<" 起飞时间:"<<R->qifeishijian;
	  out<<" 降落时间:"<<R->jiangluoshijian;
	  out<<" 座位数:"<<R->zuoweishu;//退票之后不需要加1，用最初的座位数;
	  out<<" 票价:"<<R->piaojia;
	  out<< "\n";//用于换行，是下面in.getline的关键
	  out<<"退票成功";
	  out<< "\n";//用于换行，是下面in.getline的关键
   }
   out.close(); //写完
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

void menu()//显示菜单界面
{
    cout<<"=================================欢迎使用航空订票系统==============================="<<endl;
    cout<<"*                                1请先录入航班信息                                 *"<<endl;
    cout<<"*                                2根据航班号查找航班                               *"<<endl;
	cout<<"*                                3根据起降城市查找航班                             *"<<endl;
    cout<<"*                                4删除航班                                         *"<<endl;
    cout<<"*                                5插入航班                                         *"<<endl;
    cout<<"*                                6修改航班                                         *"<<endl;
	cout<<"*                                7订票录入乘客信息                                 *"<<endl;
	cout<<"*                                8退票                                             *"<<endl;
	cout<<"===================================================================================="<<endl;
}
int main()
{
   LinkList L;//L是指针 航班
   cke C;//乘客
    while(1)
	{
      menu();
      int caozuo;
      cout<<"请选择操作";
      cin>>caozuo;
      switch(caozuo)
	  {
	case 1:
//创建
	  int num;
      cout<<"请输入要录入的航班数:";
      cin>>num;
      cout<<endl;
      import(num,L);//录入航班函数: n为所要录入航班的数量:
      cout<<endl;
      cout<<"航班信息录入成功";
      cout<<endl<<endl;
//写入本地文件，并读取输出显示
      show_L(L);
	  break;
    case 2:
//根据航班号查找
      int dchbh;//根据航班号查找
 	  printf("请输入待查航班号:");
      cin>>dchbh;
	  LinkList p;
	  p=GetElem_L(L,dchbh);//查找
	  cout<<"待查航班为:";
	  cout<<"航班号:"<<p->hangbanhao;
	  cout<<" 起飞城市:"<<p->qifeichengshi;
	  cout<<" 降落城市:"<<p->jiangluochengshi;
	  cout<<" 起飞时间:"<<p->qifeishijian;
	  cout<<" 降落时间:"<<p->jiangluoshijian;
	  cout<<" 座位数:"<<p->zuoweishu;
	  cout<<" 票价:"<<p->piaojia;
      cout<<endl<<endl;
      break;
    case 3:
//根据起降城市查找
       char qi[10];
	   char ji[10];
	   printf("请输入待查航班起降城市:");
	   cout<<"输入起飞城市:";
	   cin>>qi;
	   cout<<"输入降落城市:";
	   cin>>ji;
	   LinkList J;
	   J=GetElem_Lc(L,qi,ji);//查找
	   cout<<"待查航班为:";
	   cout<<"航班号:"<<J->hangbanhao;
	   cout<<" 起飞城市:"<<J->qifeichengshi;
	   cout<<" 降落城市:"<<J->jiangluochengshi;
	   cout<<" 起飞时间:"<<J->qifeishijian;
	   cout<<" 降落时间:"<<J->jiangluoshijian;
	   cout<<" 座位数:"<<J->zuoweishu;
	   cout<<" 票价:"<<J->piaojia;
       cout<<endl<<endl;
	   break;
    case 4:
//删除
      int shanchu;
	  printf("请输入要删除的航班号:");
	  scanf("%d",&shanchu);
	  ListDelete_L(L,shanchu);//删除
	  show_L(L);
	  cout<<endl<<endl;
	  break;
    case 5:
//插入
   //这里位置始终在第一行
      ListInsert_L(L,1);//插入
      show_L(L);
	  cout<<endl<<endl;
      break;
	case 6:
//修改
      printf("请输入要修改的航班号:");
      int yxg;
      cin>>yxg;
      LinkList q;
	  q=xiugai(L,yxg);//修改
	  cout<<"航班号修改为:";
	  cin>>q->hangbanhao;
	  cout<<"航班起飞城市修改为:";
	  cin>>q->qifeichengshi;
	  cout<<"航班降落城市修改为:";
	  cin>>q->jiangluochengshi;
	  cout<<"航班起飞时间修改为:";
	  cin>>q->qifeishijian;
	  cout<<"航班降落时间修改为:";
	  cin>>q->jiangluoshijian;
	  cout<<"航班座位数修改为:";
      cin>>q->zuoweishu;
	  cout<<"航班票价修改为:";
      cin>>q->piaojia;
      show_L(L);
	  cout<<endl<<endl;
	  break;
    case 7:
//订票
      int renshu;
      cout<<"请选择您要订票的人数:";
      cin>>renshu;
      cout<<endl;
      importren(renshu,C);//录入乘客信息
      cout<<endl;
      cout<<"乘客信息录入成功";
      cout<<endl;
	  int m;
	  cout<<"请输入您要订的航班号:";
	  cin>>m;
	  cout<<endl<<endl;
	  LinkList R;
      R=GetElem_L(L,m);//查找乘客订的航班
	  show_dp(C,R);//写入本地文件，并读取输出显示
	  cout<<endl<<endl;
      break;
    case 8:
//退票
     cout<<"请输入您要退票的航班号:";
	 int yt;
	 cin>>yt;
	 cout<<endl<<endl;
	 LinkList K;
     K=GetElem_L(L,yt);//查找乘客订的航班
	 show_tp(C,K);//写入本地文件，并读取输出显示
     cout<<endl<<endl;
	 break;
	  }//swith的大括号
	}//while的大括号
  return 0;
}//主函数的大括号


