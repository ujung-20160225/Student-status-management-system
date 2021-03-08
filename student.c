#include<stdio.h> //I/O函数
#include<stdlib.h> //其它说明
#include<string.h> //字符串函数
#define LEN 20 /* 最大字符数*/
#define N 50 /* 最大学生人数*/
struct student{ //定义一个学生结构体
	char code[20]; // 学号
	char name[20]; // 姓名
	int age; //年龄
	char sex[20]; //性别
	char major[20];//专业
    	char tele[20];//电话号码
};
struct student students[N]; //定义一个学生数组

int n=0;// n代表当前记录的学生人数
int m;//m代表新增加的学生人数
void help()//帮助
{
	while(1)
	{
		printf("\n0.欢迎使用系统帮助！\n");
		printf("\n1.初次进入系统后,请先选择增加学生信息;\n");
		printf("\n2.按照菜单提示键入数字代号;\n");
		printf("\n3.增加学生信息后,切记保存;\n");
		printf("\n4.谢谢您的使用！\n");
		printf("\n 退出帮助请按0\n");
		int a;
		scanf("%d",&a);
		switch(a)
		{
			case 0:
			return;//退出当前函数
			default:
			printf("输入错误！");
		}
		}
}

void refresh()//刷新
{
	system("clear");//清屏
}

void seek() //查找
{
	int i,item,flag;
	char s1[20];
	printf("----------------------\n");
	printf("-----1.按学号查询-----\n");
	printf("-----2.按姓名查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("----------------------\n");
	while(1)
	{
	printf("请选择子菜单编号:");
	scanf("%d",&item);
	flag=0;
	switch(item)
	{
		case 1:
		printf("请输入要查询的学生的学号:\n");
		scanf("%s",&s1);//存放输入的字符串
		getchar();
		for(i=0;i<n;i++)
		if(strcmp(students[i].code,s1)==0)//验证俩个字符串是否相等
		{
			flag=1;//判断是否找到该学生
			printf("学号\t      姓名   年龄  性别  专业  手机号\n");
			printf("-------------------------------------------------\n");
			printf("%s %s   %d    %s   %s  %s\n",students[i].code,students[i].name,students[i].age,
			students[i].sex,students[i].major,students[i].tele);
		}
		if(flag==0)
		printf("该学号不存在！\n");
		break;
		case 2:
		printf("请输入要查询的学生的姓名:\n");
		scanf("%s",&s1);
		for(i=0;i<n;i++)
		if(strcmp(students[i].name,s1)==0)//验证俩个字符串是否相等
		{
			flag=1;//判断是否找到该学生
			printf("学号\t      姓名   年龄  性别  专业  手机号\n");
			printf("-------------------------------------------------\n");
			printf("%s %s   %d    %s   %s  %s\n",students[i].code,students[i].name,students[i].age,
			students[i].sex,students[i].major,students[i].tele);
		}
		if(flag==0)
		printf("该姓名不存在！\n");
		break;
		case 3:return;
		default:printf("请在1-3之间选择\n");
	}
	}
}

void modify() //按学号修改信息
{
	int i,item,num;
	int a;
	char s1[LEN+1],s2[LEN+1],s3[LEN+1],s4[LEN+1],s5[LEN+1]; // 以最长长度+1为准
	
	printf("请输入要要修改的学生的学号:\n");
	scanf("%s",s1);
	for(i=0;i<n;i++)
	if(strcmp(students[i].code,s1)==0) //比较字符串是否相等
	{
		num=i;
		printf("------------------\n");
		printf("1.修改姓名\n");
		printf("2.修改年龄\n");
		printf("3.修改性别\n");
		printf("4.修改专业\n");
		printf("5.修改手机号\n");
		printf("6.退出本菜单\n");
		printf("------------------\n");
		while(1)
		{
			printf("请选择子菜单编号:");
			scanf("%d",&item);
			switch(item)
			{
				case 1:
				printf("请输入新的姓名:\n");
				scanf("%s",s2);
				strcpy(students[num].name,s2); break;//将s2的值赋给students[num].name
				case 2:
				printf("请输入新的年龄:\n");
				scanf("%s",s2);
				students[num].age=a;break;
				case 3:
				printf("请输入新的性别:\n");
				scanf("%s",s3);
				strcpy(students[num].sex,s3);break;
				case 4:
				printf("请输入新的专业:\n");
				scanf("%s",s4);
				strcpy(students[num].major,s4);break;
				case 5:
				printf("请输入新的手机号:\n");
				scanf("%s",s5);
				strcpy(students[num].tele,s5);break;
				case 6: return;
				default:printf("请在1-6之间选择\n");
			}
		}
	}
	
}

void sort()//按学号排序
{
	int i,j,k,*p,*q,s;
	char temp[LEN+1],ctemp[20];
	//float ftemp;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
		if(strcmp(students[j-1].code,students[j].code)>0)
		{
			strcpy(temp,students[j-1].code);
			strcpy(students[j-1].code,students[j].code);
			strcpy(students[j].code,temp);
			
			strcpy(temp,students[j-1].name);
			strcpy(students[j-1].name,students[j].name);
			strcpy(students[j].name,temp);
			
			p=&students[j-1].age;
			q=&students[j].age;
			s=*q;
			*q=*p;
			*p=s;

			strcpy(temp,students[j-1].sex);
			strcpy(students[j-1].sex,students[j].sex);
			strcpy(students[j].sex,ctemp);
			
			strcpy(temp,students[j-1].major);
			strcpy(students[j-1].major,students[j].major);
			strcpy(students[j].major,temp);
			
			strcpy(temp,students[j-1].tele);
			strcpy(students[j-1].tele,students[j].tele);
			strcpy(students[j].tele,temp);

		}
	}
}

void insert() //增加信息
{
	int j;
	printf("请输入待增加的学生数:\n");
	scanf("%d",&m);//记录学生数量增加的个数
	for(j=n;j<n+m;j++)//开始增加学生
	{
		printf("请输入第%d 个学生的学号:\n",j+1);
		scanf("%s",&students[j].code);
		printf("请输入第%d 个学生的姓名:\n",j+1);
		scanf("%s",&students[j].name);
		printf("请输入第%d 个学生的年龄:\n",j+1);
		scanf("%d",&students[j].age);
		printf("请输入第%d 个学生的性别:\n",j+1);
		scanf("%s",&students[j].sex);
		printf("请输入第%d 个学生的专业:\n",j+1);
		scanf("%s",&students[j].major);
		printf("请输入第%d 个学生的手机号:\n",j+1);
		scanf("%s",&students[j].tele);
	}
	n+=m;//学生总数加m
	printf("信息增加完毕！\n\n");
	//sort();
}

void del()//删除信息
{
	int i,j,flag=0;
	char s1[LEN+1];
	printf("请输入要删除学生的姓名:\n");
	scanf("%s",s1);
	for(i=0;i<n;i++)
	if(strcmp(students[i].name,s1)==0)//判断俩个字符串是否相等
	{
		flag=1;//是否找到该学生的标志
		for(j=i;j<n-1;j++)
		{
			strcpy(students[j].code,students[j+1].code);//将学生数组中每一个元素向前移一位
			strcpy(students[j].name,students[j+1].name);
			students[j].age=students[j+1].age;
			strcpy(students[j].sex,students[j+1].sex);
			strcpy(students[j].major,students[j+1].major);
			strcpy(students[j].tele,students[j+1].tele);
			
		}
	}
	if(flag==0)
		printf("该学生不存在！\n");
	if(flag==1)
	{
		printf("删除成功,显示结果请选择菜单\n");
		n--;//学生数量减1
	}
	printf("退出请按0\n");
	int a;
	scanf("%d",&a);
	switch(a)
	{
		case 0:
		return;//退出
		default:
		printf("输入错误！");
	}
}

void display()//显示所有信息
{
	int i;
	printf("共有%d位学生的信息:\n",n);
	if(n!=0)//判断学生数量是否为空值
	{	
		printf("学号\t      姓名   年龄  性别  专业  手机号\n");
		printf("-------------------------------------------------\n");
		//sort();
		for(i=0;i<n;i++)
		{
			printf("%s %s   %d    %s   %s  %s\n",students[i].code,students[i].name,students[i].age,students[i].sex,
			students[i].major,students[i].tele);
		}
	}
	else//n=0,表示无学生信息
	{
		printf("暂无学生信息\n");
	}
	printf("退出请按0\n");
	int a;
	scanf("%d",&a);
	if(a==0)
	return;
}

void save()//保存信息
{
	
	FILE *fp;
	fp= fopen("stu.txt","w");//打开文档，写入
	for(int i=0;i<n;i++)
	{
		fprintf(fp,"学号\t      姓名   年龄  性别  专业  手机号\n");
		fprintf(fp,"%s %s   %d    %s   %s  %s\n",students[i].code,students[i].name,students[i].age,students[i].sex,
		students[i].major,students[i].tele);
	}
	fclose(fp);
}

void logo()//退出系统
{
	printf(" \n\n \n\n");
	printf("*********************************");
	printf("\n\n        欢迎下次使用           \n\n");
	printf("*********************************\n\n");
	return;
}

void menu()/* 界面*/
{
	int input=0;
	while(input!=8)
	{
		printf(" *************************************************\n\n");
		printf(" *               学生学籍管理系统                *\n \n");
		printf(" *************************************************\n\n");
		printf(" ------------------------------------------------- \n");
		printf(" * 0.系统帮助及说明 *           * 1.刷新显示屏幕 * \n");
		printf(" ------------------------------------------------- \n");
		printf(" * 2.查询学生信息 *             * 3.修改学生信息 * \n");
		printf(" ------------------------------------------------- \n");
		printf(" * 4.增加学生信息 *             * 5.删除学生信息 * \n");
		printf(" ------------------------------------------------- \n");
		printf(" * 6.显示学生信息 *             * 7.保存学生信息 * \n");
		printf(" ------------------------------------------------- \n");
		printf(" *                  8.退出系统                   * \n");
		printf(" ------------------------------------------------- \n");
		printf("请选择菜单编号:");
		scanf("%d",&input);
		switch(input)
		{
			case 0:help();break;//系统帮助及说明
			case 1:refresh();break;//刷新学生信息
			case 2:seek();break;//查询学生信息
			case 3:modify();break;//修改学生信息
			case 4:insert();break;//增加学生信息
			case 5:del();break;//按学号删除信息
			case 6:display();break;//显示当前信息
			case 7:save();break;//保存当前学生信息
			case 8:printf("即将退出学生管理系统");break;
			default:printf("请在0-8之间选择\n");
		}
		system("clear");//刷新屏幕
	}
	logo();//退出界面
}
void main()
{
	menu();//界面
}
