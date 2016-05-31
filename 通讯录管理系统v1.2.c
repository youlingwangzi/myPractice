/*
 *2014年7月16日 星期三
 *程序名称：天朝皇家成员管理系统v1.1
 *程序描述：一个管理天朝皇家成员信息的系统
 *版本信息：v1.2
 *版本更新：
 *v1.1：
 *         1：文件打开错误不提示的问题
 *         2：按名称删除连续的成员信息是只删除第一个的bug
 *         3：解决初始化菜单显示版权信息后不在显示初始化菜单的问题
 *v1.2：
 *         1：调整界面颜色显示，界面更美观
 *         2：根据生日自动显示对应属相，星座
 *         3：退出时显示版权信息 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define STU struct stu
#define LEN sizeof(struct stu)

struct stu
{
	char name[15];
	char phone[15];
	char email[30];
	char address[50];
	int birth[3];
	struct stu *next;
};

void add_data(STU *h);
void show_one(STU *p);
void show(STU *h);
void file_out(STU *h);
void file_in(STU *h);
void delete_data(STU *h);
void delete_data1(STU *h);
void delete_data2(STU *h);
void search_data(STU *h);
void search_data1(STU *h);
void search_data2(STU *h);
void about(int n);
void shengxiao(STU *p);
void xingzuo(STU *p);

int main()
{
	int n;
	STU *h;
	h = (STU*)malloc(LEN);
	h->next = NULL;

	//初始化菜单，启动系统时显示，执行操作后不再显示。
	for (; 1;)
	{
		system("cls");
		system("color 0F");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                       欢迎使用天朝皇家成员管理系统                       ║\n");
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┃          1->初始化成员             ┃┃        2->从文件导入系统         ┃\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┃         3->About our team！        ┃┃            0->结束使用           ┃\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("请输入你的指令：");
		scanf("%d", &n);
		getchar();
		for (; 1;)
		{
			switch (n)
			{
			case 1:add_data(h); break;
			case 2:file_in(h); break;
			case 0:about(0); Sleep(1000); return 0;
			}
			if (n<0 || n>3)
			{
				printf("请输入正确选项:");
				scanf("%d", &n);
				getchar();
			}
			else
				break;
		}
		if (n == 3)
			about(1);
		else
			break;
	}

	//系统主菜单，初始化数据后显示。
	for (; 1;)
	{
		system("cls");
		system("color 0F");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                           欢迎使用天朝皇家通讯录                         ║\n");
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃            1->新增成员             ┃┃            2->删除成员           ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃            3->查找成员             ┃┃            4->浏览列表           ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃          5->从文件导入系统         ┃┃         6->向文件导出系统        ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃          7->About our team！       ┃┃            0->结束使用           ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("请输入您的指令：");
		scanf("%d", &n);
		getchar();
		for (; 1;)
		{
			switch (n)
			{
			case 1:add_data(h); break;
			case 2:delete_data(h); break;
			case 3:search_data(h); break;
			case 4:show(h); break;
			case 5:file_in(h); break;
			case 6:file_out(h); break;
			case 7:about(1); break;

			case 0:about(0); Sleep(1000); return 0;
			}
			if (n<1 || n>7)
			{
				printf("请输入正确选项:");
				scanf("%d", &n);
				getchar();
			}
			else
				break;
		}
	}
}

/*
 *添加数据函数，由主函数调用
 *向链表尾部添加数据
 *参数：链表头指针
 */
void add_data(STU *h)
{
	char ch = 'y';
	int count = 1;
	STU *p = h;
	for (; p->next; p = p->next);
	for (; ch == 'y' || ch == 'Y';)
	{
		p->next = (STU*)malloc(LEN);
		p = p->next;
		system("cls");
		system("color 2F");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                           请输入第%2d个成员信息                           ║\n", count);
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━┓┏━━━━┯━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┓\n");
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┃ 姓名： │                  ┃   电话： │                        ┃\n");
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┳━┻━━┯━━┷━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┃ 生日： │              ┃ E-mail:│                              ┃\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┻━━━━┷━━━━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┃━━┃┃家庭住址│                                                        ┃\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┗━━┛┗━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("输入姓名：");
		gets(p->name);
		system("cls");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                           请输入第%2d个成员信息                           ║\n", count);
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━┓┏━━━━┯━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┓\n");
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┃ 姓名： │ %-15s  ┃   电话： │                        ┃\n", p->name);
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┳━┻━━┯━━┷━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┃ 生日： │              ┃ E-mail:│                              ┃\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┻━━━━┷━━━━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┃━━┃┃家庭住址│                                                        ┃\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┗━━┛┗━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("输入电话号码：");
		gets(p->phone);
		system("cls");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                           请输入第%2d个成员信息                           ║\n", count);
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━┓┏━━━━┯━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┓\n");
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┃ 姓名： │ %-15s  ┃   电话： │  %-15s       ┃\n", p->name, p->phone);
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┳━┻━━┯━━┷━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┃ 生日： │              ┃ E-mail:│                              ┃\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┻━━━━┷━━━━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┃━━┃┃家庭住址│                                                        ┃\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┗━━┛┗━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("输入生日：（年月日以空格隔开）");
		scanf("%d%d%d", p->birth, p->birth + 1, p->birth + 2);
		getchar();
		system("cls");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                           请输入第%2d个成员信息                           ║\n", count);
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━┓┏━━━━┯━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┓\n");
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┃ 姓名： │ %-15s  ┃   电话： │  %-15s       ┃\n", p->name, p->phone);
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┳━┻━━┯━━┷━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┃ 生日： │ %4d-%2d-%2d   ┃ E-mail:│                              ┃\n", p->birth[0], p->birth[1], p->birth[2]);
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┻━━━━┷━━━━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┃━━┃┃家庭住址│                                                        ┃\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┗━━┛┗━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("输入E-mail：");
		gets(p->email);
		system("cls");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                           请输入第%2d个成员信息                           ║\n", count);
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━┓┏━━━━┯━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┓\n");
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┃ 姓名： │ %-15s  ┃   电话： │  %-15s       ┃\n", p->name, p->phone);
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┳━┻━━┯━━┷━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┃ 生日： │ %4d-%2d-%2d   ┃ E-mail:│%-30s┃\n", p->birth[0], p->birth[1], p->birth[2], p->email);
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┻━━━━┷━━━━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┃━━┃┃家庭住址│                                                        ┃\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┗━━┛┗━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("输入家庭住址：");
		gets(p->address);
		system("cls");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                           请输入第%2d个成员信息                           ║\n", count);
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━┓┏━━━━┯━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┓\n");
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┃ 姓名： │ %-15s  ┃   电话： │  %-15s       ┃\n", p->name, p->phone);
		printf("┃━━┃┃        │                  ┃          │                        ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┳━┻━━┯━━┷━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┃ 生日： │ %4d-%2d-%2d   ┃ E-mail:│%-30s┃\n", p->birth[0], p->birth[1], p->birth[2], p->email);
		printf("┃━━┃┃        │              ┃        │                              ┃\n");
		printf("┃━━┃┣━━━━┿━━━━━━━┻━━━━┷━━━━━━━━━━━━━━━┫\n");
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┃━━┃┃家庭住址│ %-50s     ┃\n", p->address);
		printf("┃━━┃┃        │                                                        ┃\n");
		printf("┗━━┛┗━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		++count;
		printf("是否继续输入？(y/n)");
		scanf("%c", &ch);
		getchar();
	}
	p->next = NULL;
}

/*
 *浏览链表数据函数，由主函数调用
 *显示链表当前所有数据
 *参数：链表头指针
 */
void show(STU *h)
{
	STU *p = h;
	p = p->next;
	system("cls");
	system("color 9F");
	printf("╔═════════════════════════════════════╗\n");
	printf("║                             天朝皇家成员列表                             ║\n");
	printf("╚═════════════════════════════════════╝\n");
	for (; p; p = p->next)
		show_one(p);
	printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
	printf("按任意键继续……");
	while (!kbhit());
	getchar();

}

/*
 *数据导出函数，由主函数调用
 *将链表当前所有数据以文件导出，可自选文件名
 *参数：链表头指针
 */
void file_out(STU *h)
{
	char fname[20];
	FILE *fp;
	STU *p = h->next;
	system("color 6F");
	if (p == NULL)
		printf("链表为空，请添加数据。\n");
	else
	{
		printf("输入文件名：");
		gets(fname);
		if ((fp = fopen(fname, "wb")) == NULL)
		{
			printf("打开文件出错");
			printf("按任意键继续……");
			while (!kbhit());
			getchar();
		}
		else
		{
			for (; p;)
			{
				fwrite(p, LEN, 1, fp);
				p = p->next;
			}
			printf("文件写入成功!\n");
			fclose(fp);
			printf("按任意键继续……");
			while (!kbhit());
			getchar();
		}
	}
}

/*
 *从文件导入数据，由主函数调用
 *将自选文件中的数据连接到当前链表尾部
 *参数：链表头指针
 */
void file_in(STU *h)
{
	char fname[20];
	int count = 0;
	FILE *fp;
	STU *p = h;
	system("color 6F");
	for (; p->next; p = p->next);

	printf("输入文件名：");
	gets(fname);
	if ((fp = fopen(fname, "rb")) == NULL)
	{
		printf("打开文件出错");
		printf("按任意键继续……");
		while (!kbhit());
		getchar();
	}
	else
	{
		p->next = (STU*)malloc(LEN);
		p = p->next;
		fread(p, LEN, 1, fp);
		++count;
		for (; p->next;)
		{
			p->next = (STU*)malloc(LEN);
			p = p->next;
			fread(p, LEN, 1, fp);
			++count;
		}
		printf("导入成功，本次共导入%d条数据。\n", count);
		fclose(fp);
		p->next = NULL;
		printf("按任意键继续……");
		while (!kbhit());
		getchar();
	}
}

/*
 *删除链表数据函数，由主函数调用
 *删除链表中数据的主调用函数，按照用户选择调用不同的执行删除函数
 *参数：链表头指针
 */
void delete_data(STU *h)

{
	int n;
	for (; 1;)
	{
		system("cls");
		system("color 4F");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                        天朝皇家成员管理系统——删除                      ║\n");
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┃           1->按名字删除            ┃┃         2->按电话号码删除        ┃\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┃         3->About our team！        ┃┃          0->返回上一级           ┃\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("请输入您的指令：");
		scanf("%d", &n);
		getchar();
		for (; 1;)
		{
			switch (n)
			{
			case 1:delete_data1(h); break;
			case 2:delete_data2(h); break;
			case 3:about(1); break;
			}
			if (n<0 || n>3)
			{
				printf("请输入正确选项:");
				scanf("%d", &n);
				getchar();
			}
			else
				break;
		}
		if (n == 0)
			break;
	}
}

/*
 *链表数据删除执行函数，由delete_data函数调用
 *按照姓名删除链表中的数据
 *参数：链表头指针
 */
void delete_data1(STU *h)
{
	STU *p = h, *temp;
	char name[15];
	int count = 0;
	if (!p->next)
		printf("通讯录为空不能删除。\n");
	else
	{
		printf("请输入要删除的名字：");
		gets(name);
		for (; p && p->next;)
			if (strcmp(p->next->name, name) == 0)
			{
			temp = p->next->next;
			free(p->next);
			p->next = temp;
			++count;
			}
			else
				p = p->next;
		printf("共删除%d条数据。\n", count);
		printf("按任意键继续……");
		while (!kbhit());
		getchar();
	}
}

/*
 *删除链表数据执行函数，由delete_data函数调用
 *按照电话删除链表中的数据
 *参数：链表头指针
 */
void delete_data2(STU *h)
{
	STU *p = h, *temp;
	char phone[15];
	int count = 0;
	if (!p->next)
		printf("通讯录为空不能删除。\n");
	else
	{
		printf("请输入要删除的手机号：");
		gets(phone);
		for (; p && p->next;)
			if (strcmp(p->next->phone, phone) == 0)
			{
			temp = p->next->next;
			free(p->next);
			p->next = temp;
			++count;
			}
			else
				p = p->next;
		printf("共删除%d条数据。\n", count);
		printf("按任意键继续……");
		while (!kbhit());
		getchar();
	}
}

/*
 *查找链表数据函数，由主函数调用
 *查找链表中数据的主调用函数，按照用户选择调用不同的执行查找函数
 *参数：链表头指针
 */
void search_data(STU *h)
{
	int n;
	for (; 1;)
	{
		system("cls");
		system("color 1F");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                                                                          ║\n");
		printf("║                         天朝皇家成员管理系统——查找                     ║\n");
		printf("║                                                                          ║\n");
		printf("╚═════════════════════════════════════╝\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┃           1->按名字查找            ┃┃         2->按电话号码查找        ┃\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┃         3->About our team！        ┃┃          0->返回上一级           ┃\n");
		printf("┃                                    ┃┃                                  ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("请输入您的指令：");
		scanf("%d", &n);
		getchar();
		for (; 1;)
		{
			switch (n)
			{
			case 1:search_data1(h); break;
			case 2:search_data2(h); break;
			case 3:about(1); break;
			}
			if (n<0 || n>3)
			{
				printf("请输入正确选项:");
				scanf("%d", &n);
				getchar();
			}
			else
				break;
		}
		if (n == 0)
			break;
	}
}

/*
 *查找链表数据执行函数，由search_data函数调用
 *按照姓名查找链表中的数据
 *参数：链表头指针
 */
void search_data1(STU *h)
{
	STU *p = h;
	char name[15];
	int count = 0;
	if (!p->next)
		printf("通讯录为空不能查找。\n");
	else
	{
		printf("请输入要查找的名字：");
		gets(name);
		system("cls");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                            为您找到的皇家成员                            ║\n");
		printf("╚═════════════════════════════════════╝\n");
		for (; p->next; p = p->next)
			if (strcmp(p->next->name, name) == 0)
			{
			show_one(p->next);
			++count;
			}
		printf("\n\n\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("共查找到%d条数据。\n", count);
		printf("按任意键继续……");
		while (!kbhit());
		getchar();
	}
}

/*
 *查找链表数据执行函数，由search_data函数调用
 *按照电话查找链表中的数据
 *参数：链表头指针
 */
void search_data2(STU *h)
{
	STU *p = h;
	char phone[15];
	int count = 0;
	if (!p->next)
		printf("通讯录为空不能查找。\n");
	else
	{
		printf("请输入要查找的号码：");
		gets(phone);
		system("cls");
		printf("╔═════════════════════════════════════╗\n");
		printf("║                            为您找到的皇家成员                            ║\n");
		printf("╚═════════════════════════════════════╝\n");
		for (; p->next; p = p->next)
			if (strcmp(p->next->phone, phone) == 0)
			{
			show_one(p->next);
			++count;
			}
		printf("\n\n\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("共查找到%d条数据。\n", count);
		printf("按任意键继续……");
		while (!kbhit());
		getchar();
	}
}

/*
 *显示链表中一条数据执行函数，由show、search_data1、search_data2函数调用
 *只显示一条链表结点数据
 *参数：要输出的链表结点指针
 */
void show_one(STU *p)
{
	printf("┏━━┓┏━━━━┯━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┓\n");
	printf("┃━━┃┃ 姓名： │ %-15s  ┃   电话： │  %-15s       ┃\n", p->name, p->phone);
	printf("┃━━┃┣━━━━┿━━━━━━━┳━┻━━┯━━┷━━━━━━━━━━━━┫\n");
	printf("┃━━┃┃ 生日： │ %4d-%2d-%2d   ┃ E-mail:│%-30s┃\n", p->birth[0], p->birth[1], p->birth[2], p->email);
	printf("┃━━┃┣━━━━┿━━━━━━━┻━━━━┷━━━━━━━━━━━━━━━┫\n");
	printf("┃━━┃┃家庭住址│ %-50s     ┃\n", p->address);
	printf("┃━━┃┣━━━━┿━━━━━━━━━┳━━━━━┯━━━━━━━━━━━━┫\n");
	printf("┃━━┃┃  生肖：│       ");    shengxiao(p); printf("         ┃   星座   │       "); xingzuo(p); printf("           ┃\n");
	printf("┗━━┛┗━━━━┷━━━━━━━━━┻━━━━━┷━━━━━━━━━━━━┛\n");
}

/*
 *版权信息输出函数，由search_data、delete_data、主函数调用
 *输出版权信息
 *参数：显示完毕后是否暂停的标志位
 */
void about(int n)
{
	system("cls");
	system("color 8F");
	printf("\n\n\n╔═════════════════════════════════════╗\n");
	printf("║                                                                          ║\n");
	printf("║                                                                          ║\n");
	printf("║                                                                          ║\n");
	printf("║                          天朝皇家成员管理系统V1.2                        ║\n");
	printf("║                                                                          ║\n");
	printf("║                                                                          ║\n");
	printf("║                                                                          ║\n");
	printf("╚═════════════════════════════════════╝\n");
	printf("\n\n\n\n\n\n┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
	if (n)
	{
		printf("按任意键继续……");
		while (!kbhit());
		getchar();
	}
}

/*
 *生肖显示函数，由show_one函数调用
 *参数：结构体节点地址指针
 */
void shengxiao(STU *p)
{
	switch (p->birth[0] % 12)
	{
	case 0: printf("猴"); break;
	case 1: printf("鸡"); break;
	case 2: printf("狗"); break;
	case 3: printf("猪"); break;
	case 4: printf("鼠"); break;
	case 5: printf("牛"); break;
	case 6: printf("虎"); break;
	case 7: printf("兔"); break;
	case 8: printf("龙"); break;
	case 9: printf("蛇"); break;
	case 10: printf("马"); break;
	case 11: printf("羊"); break;
	}
}

/*
 *星座显示函数，由show_one函数调用
 *参数：结构体节点地址指针
 */
void xingzuo(STU *p)
{
	if ((p->birth[1] == 3 && p->birth[2] >= 21 && p->birth[2] <= 31) || (p->birth[1] == 4 && p->birth[2] >= 1 && p->birth[2] <= 19))
		printf("白羊座");
	else if ((p->birth[1] == 4 && p->birth[2] >= 20 && p->birth[2] <= 30) || (p->birth[1] == 5 && p->birth[2] >= 1 && p->birth[2] <= 20))
		printf("金牛座");
	else if ((p->birth[1] == 5 && p->birth[2] >= 21 && p->birth[2] <= 31) || (p->birth[1] == 6 && p->birth[2] >= 1 && p->birth[2] <= 21))
		printf("双子座");
	else if ((p->birth[1] == 6 && p->birth[2] >= 22 && p->birth[2] <= 31) || (p->birth[1] == 7 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("巨蟹座");
	else if ((p->birth[1] == 7 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 8 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("狮子座");
	else if ((p->birth[1] == 8 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 9 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("处女座");
	else if ((p->birth[1] == 9 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 10 && p->birth[2] >= 1 && p->birth[2] <= 23))
		printf("天秤座");
	else if ((p->birth[1] == 10 && p->birth[2] >= 24 && p->birth[2] <= 31) || (p->birth[1] == 11 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("天蝎座");
	else if ((p->birth[1] == 11 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 12 && p->birth[2] >= 1 && p->birth[2] <= 21))
		printf("射手座");
	else if ((p->birth[1] == 12 && p->birth[2] >= 22 && p->birth[2] <= 31) || (p->birth[1] == 1 && p->birth[2] >= 1 && p->birth[2] <= 19))
		printf("摩羯座");
	else if ((p->birth[1] == 1 && p->birth[2] >= 20 && p->birth[2] <= 31) || (p->birth[1] == 2 && p->birth[2] >= 1 && p->birth[2] <= 18))
		printf("水瓶座");
	else
		printf("双鱼座");
}