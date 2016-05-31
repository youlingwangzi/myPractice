/*
 *2014��7��16�� ������
 *�������ƣ��쳯�ʼҳ�Ա����ϵͳv1.1
 *����������һ�������쳯�ʼҳ�Ա��Ϣ��ϵͳ
 *�汾��Ϣ��v1.2
 *�汾���£�
 *v1.1��
 *         1���ļ��򿪴�����ʾ������
 *         2��������ɾ�������ĳ�Ա��Ϣ��ֻɾ����һ����bug
 *         3�������ʼ���˵���ʾ��Ȩ��Ϣ������ʾ��ʼ���˵�������
 *v1.2��
 *         1������������ɫ��ʾ�����������
 *         2�����������Զ���ʾ��Ӧ���࣬����
 *         3���˳�ʱ��ʾ��Ȩ��Ϣ 
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

	//��ʼ���˵�������ϵͳʱ��ʾ��ִ�в���������ʾ��
	for (; 1;)
	{
		system("cls");
		system("color 0F");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                       ��ӭʹ���쳯�ʼҳ�Ա����ϵͳ                       �U\n");
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��                                    ����                                  ��\n");
		printf("��          1->��ʼ����Ա             ����        2->���ļ�����ϵͳ         ��\n");
		printf("��                                    ����                                  ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��                                    ����                                  ��\n");
		printf("��         3->About our team��        ����            0->����ʹ��           ��\n");
		printf("��                                    ����                                  ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("���������ָ�");
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
				printf("��������ȷѡ��:");
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

	//ϵͳ���˵�����ʼ�����ݺ���ʾ��
	for (; 1;)
	{
		system("cls");
		system("color 0F");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                           ��ӭʹ���쳯�ʼ�ͨѶ¼                         �U\n");
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��            1->������Ա             ����            2->ɾ����Ա           ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��            3->���ҳ�Ա             ����            4->����б�           ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��          5->���ļ�����ϵͳ         ����         6->���ļ�����ϵͳ        ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��          7->About our team��       ����            0->����ʹ��           ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("\n\n������������������������������������������������������������������������������\n");
		printf("����������ָ�");
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
				printf("��������ȷѡ��:");
				scanf("%d", &n);
				getchar();
			}
			else
				break;
		}
	}
}

/*
 *������ݺ�����������������
 *������β���������
 *����������ͷָ��
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
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                           �������%2d����Ա��Ϣ                           �U\n", count);
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("�������������������ө������������������ש����������ө�������������������������\n");
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������� ������ ��                  ��   �绰�� ��                        ��\n");
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������ǩ��������㩥�������������ש��ߩ����ө����۩�������������������������\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������� ���գ� ��              �� E-mail:��                              ��\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������ǩ��������㩥�������������ߩ��������۩�������������������������������\n");
		printf("����������        ��                                                        ��\n");
		printf("������������ͥסַ��                                                        ��\n");
		printf("����������        ��                                                        ��\n");
		printf("�������������������۩���������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("����������");
		gets(p->name);
		system("cls");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                           �������%2d����Ա��Ϣ                           �U\n", count);
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("�������������������ө������������������ש����������ө�������������������������\n");
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������� ������ �� %-15s  ��   �绰�� ��                        ��\n", p->name);
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������ǩ��������㩥�������������ש��ߩ����ө����۩�������������������������\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������� ���գ� ��              �� E-mail:��                              ��\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������ǩ��������㩥�������������ߩ��������۩�������������������������������\n");
		printf("����������        ��                                                        ��\n");
		printf("������������ͥסַ��                                                        ��\n");
		printf("����������        ��                                                        ��\n");
		printf("�������������������۩���������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("����绰���룺");
		gets(p->phone);
		system("cls");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                           �������%2d����Ա��Ϣ                           �U\n", count);
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("�������������������ө������������������ש����������ө�������������������������\n");
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������� ������ �� %-15s  ��   �绰�� ��  %-15s       ��\n", p->name, p->phone);
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������ǩ��������㩥�������������ש��ߩ����ө����۩�������������������������\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������� ���գ� ��              �� E-mail:��                              ��\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������ǩ��������㩥�������������ߩ��������۩�������������������������������\n");
		printf("����������        ��                                                        ��\n");
		printf("������������ͥסַ��                                                        ��\n");
		printf("����������        ��                                                        ��\n");
		printf("�������������������۩���������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("�������գ����������Կո������");
		scanf("%d%d%d", p->birth, p->birth + 1, p->birth + 2);
		getchar();
		system("cls");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                           �������%2d����Ա��Ϣ                           �U\n", count);
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("�������������������ө������������������ש����������ө�������������������������\n");
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������� ������ �� %-15s  ��   �绰�� ��  %-15s       ��\n", p->name, p->phone);
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������ǩ��������㩥�������������ש��ߩ����ө����۩�������������������������\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������� ���գ� �� %4d-%2d-%2d   �� E-mail:��                              ��\n", p->birth[0], p->birth[1], p->birth[2]);
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������ǩ��������㩥�������������ߩ��������۩�������������������������������\n");
		printf("����������        ��                                                        ��\n");
		printf("������������ͥסַ��                                                        ��\n");
		printf("����������        ��                                                        ��\n");
		printf("�������������������۩���������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("����E-mail��");
		gets(p->email);
		system("cls");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                           �������%2d����Ա��Ϣ                           �U\n", count);
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("�������������������ө������������������ש����������ө�������������������������\n");
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������� ������ �� %-15s  ��   �绰�� ��  %-15s       ��\n", p->name, p->phone);
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������ǩ��������㩥�������������ש��ߩ����ө����۩�������������������������\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������� ���գ� �� %4d-%2d-%2d   �� E-mail:��%-30s��\n", p->birth[0], p->birth[1], p->birth[2], p->email);
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������ǩ��������㩥�������������ߩ��������۩�������������������������������\n");
		printf("����������        ��                                                        ��\n");
		printf("������������ͥסַ��                                                        ��\n");
		printf("����������        ��                                                        ��\n");
		printf("�������������������۩���������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("�����ͥסַ��");
		gets(p->address);
		system("cls");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                           �������%2d����Ա��Ϣ                           �U\n", count);
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("�������������������ө������������������ש����������ө�������������������������\n");
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������� ������ �� %-15s  ��   �绰�� ��  %-15s       ��\n", p->name, p->phone);
		printf("����������        ��                  ��          ��                        ��\n");
		printf("���������ǩ��������㩥�������������ש��ߩ����ө����۩�������������������������\n");
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������� ���գ� �� %4d-%2d-%2d   �� E-mail:��%-30s��\n", p->birth[0], p->birth[1], p->birth[2], p->email);
		printf("����������        ��              ��        ��                              ��\n");
		printf("���������ǩ��������㩥�������������ߩ��������۩�������������������������������\n");
		printf("����������        ��                                                        ��\n");
		printf("������������ͥסַ�� %-50s     ��\n", p->address);
		printf("����������        ��                                                        ��\n");
		printf("�������������������۩���������������������������������������������������������\n");
		printf("\n\n������������������������������������������������������������������������������\n");
		++count;
		printf("�Ƿ�������룿(y/n)");
		scanf("%c", &ch);
		getchar();
	}
	p->next = NULL;
}

/*
 *����������ݺ�����������������
 *��ʾ����ǰ��������
 *����������ͷָ��
 */
void show(STU *h)
{
	STU *p = h;
	p = p->next;
	system("cls");
	system("color 9F");
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("�U                             �쳯�ʼҳ�Ա�б�                             �U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	for (; p; p = p->next)
		show_one(p);
	printf("\n\n\n\n������������������������������������������������������������������������������\n");
	printf("���������������");
	while (!kbhit());
	getchar();

}

/*
 *���ݵ���������������������
 *������ǰ�����������ļ�����������ѡ�ļ���
 *����������ͷָ��
 */
void file_out(STU *h)
{
	char fname[20];
	FILE *fp;
	STU *p = h->next;
	system("color 6F");
	if (p == NULL)
		printf("����Ϊ�գ���������ݡ�\n");
	else
	{
		printf("�����ļ�����");
		gets(fname);
		if ((fp = fopen(fname, "wb")) == NULL)
		{
			printf("���ļ�����");
			printf("���������������");
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
			printf("�ļ�д��ɹ�!\n");
			fclose(fp);
			printf("���������������");
			while (!kbhit());
			getchar();
		}
	}
}

/*
 *���ļ��������ݣ�������������
 *����ѡ�ļ��е��������ӵ���ǰ����β��
 *����������ͷָ��
 */
void file_in(STU *h)
{
	char fname[20];
	int count = 0;
	FILE *fp;
	STU *p = h;
	system("color 6F");
	for (; p->next; p = p->next);

	printf("�����ļ�����");
	gets(fname);
	if ((fp = fopen(fname, "rb")) == NULL)
	{
		printf("���ļ�����");
		printf("���������������");
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
		printf("����ɹ������ι�����%d�����ݡ�\n", count);
		fclose(fp);
		p->next = NULL;
		printf("���������������");
		while (!kbhit());
		getchar();
	}
}

/*
 *ɾ���������ݺ�����������������
 *ɾ�����������ݵ������ú����������û�ѡ����ò�ͬ��ִ��ɾ������
 *����������ͷָ��
 */
void delete_data(STU *h)

{
	int n;
	for (; 1;)
	{
		system("cls");
		system("color 4F");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                        �쳯�ʼҳ�Ա����ϵͳ����ɾ��                      �U\n");
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��                                    ����                                  ��\n");
		printf("��           1->������ɾ��            ����         2->���绰����ɾ��        ��\n");
		printf("��                                    ����                                  ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��                                    ����                                  ��\n");
		printf("��         3->About our team��        ����          0->������һ��           ��\n");
		printf("��                                    ����                                  ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("����������ָ�");
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
				printf("��������ȷѡ��:");
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
 *��������ɾ��ִ�к�������delete_data��������
 *��������ɾ�������е�����
 *����������ͷָ��
 */
void delete_data1(STU *h)
{
	STU *p = h, *temp;
	char name[15];
	int count = 0;
	if (!p->next)
		printf("ͨѶ¼Ϊ�ղ���ɾ����\n");
	else
	{
		printf("������Ҫɾ�������֣�");
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
		printf("��ɾ��%d�����ݡ�\n", count);
		printf("���������������");
		while (!kbhit());
		getchar();
	}
}

/*
 *ɾ����������ִ�к�������delete_data��������
 *���յ绰ɾ�������е�����
 *����������ͷָ��
 */
void delete_data2(STU *h)
{
	STU *p = h, *temp;
	char phone[15];
	int count = 0;
	if (!p->next)
		printf("ͨѶ¼Ϊ�ղ���ɾ����\n");
	else
	{
		printf("������Ҫɾ�����ֻ��ţ�");
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
		printf("��ɾ��%d�����ݡ�\n", count);
		printf("���������������");
		while (!kbhit());
		getchar();
	}
}

/*
 *�����������ݺ�����������������
 *�������������ݵ������ú����������û�ѡ����ò�ͬ��ִ�в��Һ���
 *����������ͷָ��
 */
void search_data(STU *h)
{
	int n;
	for (; 1;)
	{
		system("cls");
		system("color 1F");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                                                                          �U\n");
		printf("�U                         �쳯�ʼҳ�Ա����ϵͳ��������                     �U\n");
		printf("�U                                                                          �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��                                    ����                                  ��\n");
		printf("��           1->�����ֲ���            ����         2->���绰�������        ��\n");
		printf("��                                    ����                                  ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("������������������������������������������������������������������������������\n");
		printf("��                                    ����                                  ��\n");
		printf("��         3->About our team��        ����          0->������һ��           ��\n");
		printf("��                                    ����                                  ��\n");
		printf("������������������������������������������������������������������������������\n");
		printf("\n\n\n\n������������������������������������������������������������������������������\n");
		printf("����������ָ�");
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
				printf("��������ȷѡ��:");
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
 *������������ִ�к�������search_data��������
 *�����������������е�����
 *����������ͷָ��
 */
void search_data1(STU *h)
{
	STU *p = h;
	char name[15];
	int count = 0;
	if (!p->next)
		printf("ͨѶ¼Ϊ�ղ��ܲ��ҡ�\n");
	else
	{
		printf("������Ҫ���ҵ����֣�");
		gets(name);
		system("cls");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                            Ϊ���ҵ��Ļʼҳ�Ա                            �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		for (; p->next; p = p->next)
			if (strcmp(p->next->name, name) == 0)
			{
			show_one(p->next);
			++count;
			}
		printf("\n\n\n\n\n\n������������������������������������������������������������������������������\n");
		printf("�����ҵ�%d�����ݡ�\n", count);
		printf("���������������");
		while (!kbhit());
		getchar();
	}
}

/*
 *������������ִ�к�������search_data��������
 *���յ绰���������е�����
 *����������ͷָ��
 */
void search_data2(STU *h)
{
	STU *p = h;
	char phone[15];
	int count = 0;
	if (!p->next)
		printf("ͨѶ¼Ϊ�ղ��ܲ��ҡ�\n");
	else
	{
		printf("������Ҫ���ҵĺ��룺");
		gets(phone);
		system("cls");
		printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U                            Ϊ���ҵ��Ļʼҳ�Ա                            �U\n");
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		for (; p->next; p = p->next)
			if (strcmp(p->next->phone, phone) == 0)
			{
			show_one(p->next);
			++count;
			}
		printf("\n\n\n\n\n\n������������������������������������������������������������������������������\n");
		printf("�����ҵ�%d�����ݡ�\n", count);
		printf("���������������");
		while (!kbhit());
		getchar();
	}
}

/*
 *��ʾ������һ������ִ�к�������show��search_data1��search_data2��������
 *ֻ��ʾһ������������
 *������Ҫ�����������ָ��
 */
void show_one(STU *p)
{
	printf("�������������������ө������������������ש����������ө�������������������������\n");
	printf("���������� ������ �� %-15s  ��   �绰�� ��  %-15s       ��\n", p->name, p->phone);
	printf("���������ǩ��������㩥�������������ש��ߩ����ө����۩�������������������������\n");
	printf("���������� ���գ� �� %4d-%2d-%2d   �� E-mail:��%-30s��\n", p->birth[0], p->birth[1], p->birth[2], p->email);
	printf("���������ǩ��������㩥�������������ߩ��������۩�������������������������������\n");
	printf("������������ͥסַ�� %-50s     ��\n", p->address);
	printf("���������ǩ��������㩥�����������������ש����������ө�������������������������\n");
	printf("����������  ��Ф����       ");    shengxiao(p); printf("         ��   ����   ��       "); xingzuo(p); printf("           ��\n");
	printf("�������������������۩������������������ߩ����������۩�������������������������\n");
}

/*
 *��Ȩ��Ϣ�����������search_data��delete_data������������
 *�����Ȩ��Ϣ
 *��������ʾ��Ϻ��Ƿ���ͣ�ı�־λ
 */
void about(int n)
{
	system("cls");
	system("color 8F");
	printf("\n\n\n�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("�U                                                                          �U\n");
	printf("�U                                                                          �U\n");
	printf("�U                                                                          �U\n");
	printf("�U                          �쳯�ʼҳ�Ա����ϵͳV1.2                        �U\n");
	printf("�U                                                                          �U\n");
	printf("�U                                                                          �U\n");
	printf("�U                                                                          �U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\n\n\n\n\n\n������������������������������������������������������������������������������\n");
	if (n)
	{
		printf("���������������");
		while (!kbhit());
		getchar();
	}
}

/*
 *��Ф��ʾ��������show_one��������
 *�������ṹ��ڵ��ַָ��
 */
void shengxiao(STU *p)
{
	switch (p->birth[0] % 12)
	{
	case 0: printf("��"); break;
	case 1: printf("��"); break;
	case 2: printf("��"); break;
	case 3: printf("��"); break;
	case 4: printf("��"); break;
	case 5: printf("ţ"); break;
	case 6: printf("��"); break;
	case 7: printf("��"); break;
	case 8: printf("��"); break;
	case 9: printf("��"); break;
	case 10: printf("��"); break;
	case 11: printf("��"); break;
	}
}

/*
 *������ʾ��������show_one��������
 *�������ṹ��ڵ��ַָ��
 */
void xingzuo(STU *p)
{
	if ((p->birth[1] == 3 && p->birth[2] >= 21 && p->birth[2] <= 31) || (p->birth[1] == 4 && p->birth[2] >= 1 && p->birth[2] <= 19))
		printf("������");
	else if ((p->birth[1] == 4 && p->birth[2] >= 20 && p->birth[2] <= 30) || (p->birth[1] == 5 && p->birth[2] >= 1 && p->birth[2] <= 20))
		printf("��ţ��");
	else if ((p->birth[1] == 5 && p->birth[2] >= 21 && p->birth[2] <= 31) || (p->birth[1] == 6 && p->birth[2] >= 1 && p->birth[2] <= 21))
		printf("˫����");
	else if ((p->birth[1] == 6 && p->birth[2] >= 22 && p->birth[2] <= 31) || (p->birth[1] == 7 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("��з��");
	else if ((p->birth[1] == 7 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 8 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("ʨ����");
	else if ((p->birth[1] == 8 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 9 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("��Ů��");
	else if ((p->birth[1] == 9 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 10 && p->birth[2] >= 1 && p->birth[2] <= 23))
		printf("�����");
	else if ((p->birth[1] == 10 && p->birth[2] >= 24 && p->birth[2] <= 31) || (p->birth[1] == 11 && p->birth[2] >= 1 && p->birth[2] <= 22))
		printf("��Ы��");
	else if ((p->birth[1] == 11 && p->birth[2] >= 23 && p->birth[2] <= 31) || (p->birth[1] == 12 && p->birth[2] >= 1 && p->birth[2] <= 21))
		printf("������");
	else if ((p->birth[1] == 12 && p->birth[2] >= 22 && p->birth[2] <= 31) || (p->birth[1] == 1 && p->birth[2] >= 1 && p->birth[2] <= 19))
		printf("Ħ����");
	else if ((p->birth[1] == 1 && p->birth[2] >= 20 && p->birth[2] <= 31) || (p->birth[1] == 2 && p->birth[2] >= 1 && p->birth[2] <= 18))
		printf("ˮƿ��");
	else
		printf("˫����");
}