#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Student;

class StuNode
{
  public:
    Student* head;
    Student* tail;
    int num;
};

class Student
{
   private:
	   int num;
	   char name[10];
	   char major[10];
	   char clas[10];
	   int math_sc;
	   int English_sc;
	   int C_sc;
   public:
      friend class StuFun;
	  Student* creat_stu();
	  Student* next;
};

class StuFun:public Student
{
   public:
      int Add_info(StuNode* list,Student* node);
	  int find_mod(StuNode* list,int flag);
	  int aver_jg_yx(StuNode* list);
	  int All_aver_max_min(StuNode* list);
	  int pm(StuNode* list);
	  int deleteStu(StuNode* list);
	  int show(StuNode* list);
	  int Free_Node(StuNode* list);
	  int Read_File(StuNode* list);  
};

StuNode* creat_node(StuNode* list)
{
    if(list)
    return NULL;
    list=(StuNode*)malloc(sizeof(class StuNode));
    list->head=NULL;
    list->tail=NULL;
    list->num=0;
    return list;
}

Student* Student::creat_stu()
{
   Student* node=(Student*)malloc(sizeof(class Student));
   if(!node)
  return NULL;
   cout<<"\t学号：";
   cin>>node->num;

   cout<<"\t姓名：";
   cin>>node->name;

   cout<<"\t系别：";
   cin>>node->major;

   cout<<"\t班级：";
   cin>>node->clas;

   cout<<"\t高数分数：";
   cin>>node->math_sc;
 
   cout<<"\t英语分数：";
   cin>>node->English_sc;

   cout<<"\tC++分数：";
   cin>>node->C_sc;
   
   node->next=NULL;
   return node;
}

int StuFun::Add_info(StuNode* list,Student* node) //输入1调用
{
	if(!list||!node)
 	return -1;
 	if(!list->head)
 	{
      list->head = node;
      list->tail = node;
    }
    else
    {
 	  list->tail->next = node;
 	  list->tail=node;
	}
	
	list->num++;
	return 0;
}

int StuFun::find_mod(StuNode* list,int flag) //查询和修改学生信息  输入2,3调用
{
    int n,mat=0,English=0,Csc=0;
    char cla[10],maj[10],name[10];
    Student *node=list->head,*find=NULL;
    
    if(flag==0) //查询学生信息 
    {
                     cout<<"\t*************************************\n";
                     cout<<"\t*****     1,按系别查询！       ******\n";
                     cout<<"\t*****     2,按班级查询！       ******\n";
                     cout<<"\t*****     3,按高数成绩查询！   ******\n";
                     cout<<"\t*****     4,按英语成绩查询！   ******\n";
                     cout<<"\t*****     5,按C语言成绩查询！  ******\n";
                     cout<<"\t*****     6,按学生姓名查询！   ******\n";
                     cout<<"\t*************************************\n\n"; 
                     cout<<"请输入选项[ ]\b\b";
                 cin>>n;
          if(!list)
          return -1;
          switch(n)
          {
                 case 1:cout<<"\t请输入您要查询学生的系别：";
                        cin>>maj;break;
                 case 2:cout<<"\t请输入您要查询学生的班级：";
                        cin>>cla;break;
                 case 3:cout<<"\t请输入您要查询学生的高数成绩：";
                        cin>>mat;break;
                 case 4:cout<<"\t请输入您要查询学生的英语成绩：";
                        cin>>English;break;
                 case 5:cout<<"\t请输入您要查询学生的C语言成绩：";
                        cin>>Csc;break; 
                 case 6:cout<<"\t请输入您要查询学生的C语言成绩：";
                        cin>>name;break; 
                 default:cout<<"\t输入错误！\n";
           }
        cout<<"\n\t学号\t姓名\t系别\t班级\t高数\t英语\tC语言\n\n"; 
    }
    
    if(flag==1) //修改学生信息 
    {
       cout<<"\t请输入你要修改学生姓名：";
       cin>>name;
    }
    
    while(node)
    {
          switch(n)
          {
                case 1:if(!strcmp(node->major , maj)) 
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 2:if(!strcmp(node->clas , cla))
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 3:if(node->math_sc == mat)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 4:if(node->English_sc == English)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 5:if(node->C_sc == Csc)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break; 
                case 6:if(!strcmp(node->name , name))
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
          }
          
           if(flag==1) //修改学生信息 
           {
                    if(!strcmp(node->name, name))
                      {
                          cout<<"\t\t学号：";
                           cin>>node->num;
                          cout<<"\t\t姓名：";
                           cin>>node->name;
                          cout<<"\t\t系别：";
                           cin>>node->major;
                          cout<<"\t\t班级：";
                           cin>>node->clas;
                          cout<<"\t\t高数分数：";
                           cin>>node->math_sc;
                          cout<<"\t\t英语分数：";
                           cin>>node->English_sc;
                          cout<<"\t\tC++分数：";
                           cin>>node->C_sc;
                            break;
                       }
               
           } 
        
          find = node;
          node = node->next;
      }
      getchar();
    return 0;
}

int StuFun::aver_jg_yx(StuNode* list) //对学生信息进行分析
{
    Student* node=list->head;
    char major_name[10],class_name[10];
    float sum_math=0,sum_El=0,sum_C=0,aver_math,aver_El,aver_C,flag,m=0;
    float jg_math,jg_El,jg_C,yx_math,yx_El,yx_C,n=0.0,n1=0.0,n2=0.0,n3=0.0,n4=0.0,n5=0.0,n6=0.0;;
       //求单科平均分,及格率和优秀率
               cout<<"\t*****************************************\n"; 
               cout<<"\t****    1,按系对学生信息进行分析！   ****\n"; 
               cout<<"\t****    2,按班对学生信息进行分析！   ****\n";
               cout<<"\t*****************************************\n\n"; 
               cout<<"\t请输入选项[ ]\b\b";
               cin>>flag;
       if(flag == 1) //按系对学生信息进行分析！
       {
           cout<<"\t请输入系别名称：";
           cin>>major_name;
           m = strcmp( node->major,major_name );
       }
       if(flag == 2) //按班对学生信息进行分析！  //有点问题 
       {
           cout<<"\t请输入班级名称：";
           cin>>class_name;
           m = strcmp( node->clas,class_name );
       }
       while(node)
       {
         if(!m) 
         {
          sum_math += node->math_sc;
          sum_El += node->English_sc;
          sum_C += node->C_sc;        
          if(node->math_sc >=60)  //统计单科及格和优秀人数 
          { 
            n1++; 
            if(node->math_sc >=90)
             n4++;  
          }
          if(node->English_sc >=60)
          {
            n2++;
            if(node->English_sc >=90)
            n5++;
          }
          if(node->C_sc >=60)
          {
            n3++;
            if(node->C_sc >=90)
            n6++;
          }
            n++;
         }
           node = node->next;
       }
        aver_math=sum_math/n;
        aver_El=sum_El/n;
        aver_C=sum_C/n;
      
        jg_math=n1/n;
        jg_El=n2/n;
        jg_C=n3/n;
       
        yx_math=n4/n;
        yx_El=n5/n;
        yx_C=n6/n;

        cout<<"\t平均成绩为："<<"\n高数："<<aver_math<<"\t英语："<<aver_El<<"\tC++："<<aver_C<<endl;
        cout<<"\t及格率为："<<"\n高数："<<jg_math<<"\t英语："<<jg_math<<"\tC++："<<jg_C<<endl;
        cout<<"\t优秀率为："<<"\n高数："<<yx_math<<"\t英语："<<yx_El<<"\tC++："<<yx_C<<endl; 
        getchar();
    return 0; 
}

int StuFun::All_aver_max_min(StuNode* list) //对所开课程的成绩分析（求其平均成绩，最高分和最低分）
{
    Student* node=list->head;
    Student* p=list->head->next; 
    int sum_math=0,sum_El=0,sum_C=0,aver_math,aver_El,aver_C,max_math,max_El,max_C,min_math,min_El,min_C,n=0;
    while(node)
    {
       sum_math += node->math_sc;
       sum_El += node->English_sc;
       sum_C += node->C_sc;
       n++;
       node = node->next;
    }
    aver_math = sum_math/n;
    aver_El = sum_El/n;
    aver_C = sum_C/n;
    cout<<"\t所开课程平均成绩为："<<aver_math<<"\t英语："<<aver_El<<"\tC++："<<aver_C<<endl;
    
       node=list->head;
       max_math=node->math_sc;
       max_El=node->English_sc;
       max_C=node->C_sc;
       min_math=node->math_sc;
       min_El=node->English_sc;
       min_C=node->C_sc;
       for(;p!=NULL;p=p->next)
       {
        if(p->math_sc > max_math)
        max_math = p->math_sc;
        
        if(p->English_sc > max_El)
        max_El = p->English_sc;
        
        if(p->C_sc > max_C)
        max_C = p->C_sc;
        
        if(p->math_sc < min_math)
        min_math = p->math_sc;
        
        if(p->English_sc < min_El)
        min_El = p->English_sc;
        
        if(p->C_sc < min_C)
        min_C = p->C_sc;
       }
      cout<<"\t单科最高分为："<<"\n高数："<<max_math<<"\t英语："<<max_El<<"\tC++："<<max_C<<endl; 
      cout<<"\t单科最低分为："<<"\n高数："<<min_math<<"\t英语："<<min_El<<"\tC++："<<min_C<<endl; 
      getchar();
    return 0; 
}

int StuFun::pm(StuNode* list)   //对学生成绩进行排名 
{
    int n,i,j,max,t,x,y,z,a=0;
    char class_name[10],major_name[10];
    int m=list->num;
    int sum[m];
    Student stu[m],stud[m];
    Student* p=list->head;
    Student* q=list->head;

     
            
            printf("\t**************************************\n");
            printf("\t****    1,以班级单科进行排名！    ****\n");   //单科成绩进行排名 
            printf("\t****    2,以系别单科进行排名！    ****\n");
            printf("\t****    3,学生总体成绩进行排名！  ****\n ");
            printf("\t**************************************\n\n");
            printf("请输入选项[ ]\b\b");
            scanf("%d",&n);
  if(n==1||n==2)
  {          
    if(n==1)
    {
              cout<<"\t请输入您要排名的班级名称：";
              cin>>class_name;
    }
    else if(n==2)
    {
              cout<<"\t请输入您要排名的系别名称：";
              cin>>major_name;
    }
            
         for(i=0;q!=NULL;q=q->next)
         {
             if(n==1&&!strcmp(q->clas,class_name))
             {
                stud[i].math_sc = q->math_sc;
                stud[i].English_sc = q->English_sc;
                stud[i].C_sc = q->C_sc;
                i++;
             }
             else if(n==2&&!strcmp(q->major,major_name))
             {
                stud[i].math_sc = q->math_sc;
                stud[i].English_sc = q->English_sc;
                stud[i].C_sc = q->C_sc;
                i++;
             }
         }
         a=i;           
         for(i=0;i<a-1;i++)
         {
                max=i;
                for(j=i+1;j<a;j++)
                if(stud[j].math_sc > stud[max].math_sc)
                max=j;
                 if(max != i)
                 {
                      t=stud[i].math_sc;
                      stud[i].math_sc = stud[max].math_sc;
                      stud[max].math_sc =t;
                 }  
         }
         for(i=0;i<a-1;i++)
         {
                max=i; 
                for(j=i+1;j<a;j++)     
                 if(stud[j].English_sc >stud[max].English_sc)
                   max=j;
                  if(max != i)
                  {
                      x=stud[i].English_sc;
                      stud[i].English_sc =stud[max].English_sc;
                      stud[max].English_sc = x;
                  }
         } 
         for(i=0;i<a-1;i++)
         {
                max=i; 
                for(j=i+1;j<a;j++)          
                 if(stud[j].C_sc > stud[max].C_sc)
                  max=j;                     
                  if(max != i)
                  {
                      y=stud[i].C_sc;
                      stud[i].C_sc = stud[max].C_sc;
                      stud[max].C_sc =y;     
                  }
         }
  }
    else if(n==3)
    {      
       for(i=0;p!=NULL,i<m;p=p->next,i++)      //总体成绩进行排名 
       {
          sum[i]=p->math_sc + p->English_sc + p->C_sc;
          stu[i].math_sc = p->math_sc;
          stu[i].English_sc = p->English_sc;
          stu[i].C_sc = p->C_sc;
       }
   
            for(i=0;i<m-1;i++) 
           {
              max=i;
              for(j=i+1;j<m;j++)
               if(sum[j] > sum[max])
                max=j;
               if(max != i)
               {
                   t=sum[i];
                   sum[i]=sum[max];
                   sum[max]=t;
                   
                   x=stu[i].math_sc;
                   stu[i].math_sc = stu[max].math_sc;
                   stu[max].math_sc = x;
                   
                   y=stu[i].English_sc;
                   stu[i].English_sc = stu[max].English_sc;
                   stu[max].English_sc=y;
                   
                   z=stu[i].C_sc;
                   stu[i].C_sc = stu[max].C_sc;
                   stu[max].C_sc=z;
               }
            }
    }   
       
      if(n==1||n==2)
      { 
         if(n==1)
          cout<<class_name<<"班单科进行排名如下：\n\n";
         else if(n==2)
          cout<<major_name<<"系单科进行排名如下：\n\n";
          cout<<"\t\t高数\t英语\tC++\n\n";
           for(i=0;i<a;i++)
           cout<<i+1<<"名\t"<<stud[i].math_sc<<"\t"<<stud[i].English_sc<<"\t"<<stud[i].C_sc<<endl;
      }
           
     else if(n==3)
     {
        cout<<"\n\t学生总体成绩排名如下:\n\n ";
        cout<<"\t\t总分\t高数\t英语\tC++\n\n";
        for(i=0;i<m;i++)
        cout<<i+1<<"名\t"<<sum[i]<<"\t"<<stu[i].math_sc<<"\t"<<stu[i].English_sc<<"\t"<<stu[i].C_sc<<endl;
     }  
     else
     cout<<"\t\t输入错误！\n";
     getchar();
    return 0;
}


int StuFun::deleteStu(StuNode* list)
{
       char name[10];
       Student *node=list->head,*q=NULL;
       cout<<"\t请输入你要删除学生姓名：";
       cin>>name; 
       if(node==NULL)
       return 0;
        if(!strcmp(node->name , name))
         {
                    list->head = node->next;
                    delete node;
                    cout<<"已经成功删除该学生信息！\n";
         }
         else
         {
                 
                 while(strcmp(node->name , name )&& node->next!=NULL)
                 {
                              find = node;
                              node = node->next;         
                 }   
                            
                 if(!strcmp(node->name, name))
                 {
                             find->next=node->next;
                             delete node;
                       cout<<"已经成功删除该学生信息！\n";
                 }
         }
         
   getchar();
   return 0;
}

int StuFun::show(StuNode* list)
{
    Student *node=list->head,*q=NULL;
    int n=0;
    if(!n)
    {
      cout<<"\n\t学号\t姓名\t系别\t班级\t高数\t英语\tC语言\n\n"; 
      n++;
    }
    while(node)
    {
      cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
    q = node;  
    node = node->next;
    }  
    getchar();
    return 0;
}

int menu()
{
    int n;
    system("cls"); 
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------    成绩管理分析系统     ----------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------------    菜单     ----------------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t*****       1,添加学生信息！            *****\n";
	cout<<"\t*****       2,查询学生信息！            *****\n";
	cout<<"\t*****       3,修改学生信息！            *****\n";
	cout<<"\t*****       4,对学生信息进行分析！      *****\n";
    cout<<"\t*****       5,对所开课程的成绩分析！    *****\n";
    cout<<"\t*****       6,对学生考试成绩进行排名    *****\n";
    cout<<"\t*****       7,删除学生信息！            *****\n";
	cout<<"\t*****       8,显示所有学生信息！        *****\n";
	cout<<"\t*****       0,退出该系统！              *****\n";
	cout<<"\t---------------------------------------------\n\n";
	cout<<"请输入选项[ ]\b\b";
    cin>>n;
    return n;
}

int StuFun::Free_Node(StuNode* list)                  //释放
{
    while(list->head)
    {
          list->tail = list->head;
          list->head = list->head->next;
          free(list->tail);
    }
    
    free(list);
    return 0;
}

int StuFun::Read_File(StuNode* list)                           //读取文件信息
{
     FILE* fp;
     Student* p = (Student*)malloc(sizeof(class Student));
     
     if((fp = fopen("data","rb")) == NULL)      //打开文件 
            return -1;
      
     while(fread(p,sizeof(class Student),1,fp))
     {
            p->next = NULL;
            Add_info(list,p);
            p = (Student*)malloc(sizeof(class Student));
     }
     
	 fclose(fp);
	 return 0;
}

void Write_File(StuNode* list)            //写入文件 
{
	Student* p = list->head;
    FILE* fp = fopen("data","wb");

	while(p)
	{
	   fwrite(p,sizeof(class Student),1,fp);
	   p = p -> next; 
	}
	
	fclose(fp);
}


int main()
{
	StuNode* list=NULL;
	StuFun s1;
    string name;
    int n;
    while(!(list=creat_node(list)))
    s1.Read_File(list);
    while(n=menu())
    {
       switch(n)
       {
	     case 1:system("cls");if(s1.Add_info(list,s1.creat_stu())==-1)
                cout<<"\t\t添加失败\n";
                break;
         case 2:
         case 3:system("cls");s1.find_mod(list,n-2);break; 
         case 4:system("cls");
                s1.aver_jg_yx(list);break;
         case 5:system("cls");s1.All_aver_max_min(list);break;
         case 6:system("cls");s1.pm(list);break;
         case 7:system("cls");
                s1.deleteStu(list);break;
         case 8:system("cls");s1.show(list);break;
         default:system("cls");cout<<"\t\t输入错误！";
       }
      getchar();
    }
    
    Write_File(list);
	getchar();
    return 0;
}
