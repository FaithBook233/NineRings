#include<stdio.h>
///////////   ��������  ///////////
void Space(void);
void if_continue(void);
void up(int);
void down(int);

//ȫ�ֱ��� 
int N;//���� 
int Steps; //����
char str_L[10]="00000000";
char str_R[10]="000000000";
char c;
///////////   ������  ///////////
int main()
{
	system("cls");//����
	//ȷ�����յ�һ��Ϊu��d 
	printf("\n1.�ϻ�\n2.�»�\n\n");
	while(1)
	{
		if(kbhit())
		{
			c = getch();
			if(c == '1')
			{
				printf("�ϻ�\n");
				//ȷ�����������Ϊ1~9 
				do{
					printf("\n��������Ҫ��Ļ�(����1~9):   ");
					scanf("%d",&N);
				}while(N<1||N>9); 
				Steps = 0;
				up(N);
				break;
			}
			else
			{
				printf("�»�\n");
				do{
					printf("\n��������Ҫ��Ļ�(����1~9):   ");
					scanf("%d",&N);
				}while(N<1||N>9); 
				Steps = 0;
				down(N);
				break;
			}
		}
	}
	printf("\n\t������ϣ��� %d ��\n\n�� Enter �������� Esc �˳�",Steps);
	//�Ƿ�����ж�
	if_continue();
	printf("\n\n��лʹ��!!!");
	return 0;
} 
///////////   ��������  ///////////

//ֻ�а��ո���Ż���� 
void Space(void)
{
	while(1)
	{
		if(kbhit())
		{
			char ch=getch();
			if(ch==32) 
				break;
		}
	}
}
//�� Enter ������������ Esc �˳����� 
void if_continue(void)
{
	while(1)
	{
		if(kbhit())
		{
			char ch=getch();
			if(ch==13)
				main();//���� 
			else if(ch==27)
				break;	//�˳� 
		}
	}
}
//����������������Ĳ���Ϊ����n��  ����  ���ֽ⻷  ���ֽ⻷
//���ֽ⻷���������ò棬�����ϡ��»�ʱ���㿴��9������״̬�����ֽ⻷ͬ�� 
void up(int n)
{
	//��ǰn=��(n-1),��(n-2),�� n,��(n-2);
	if(n>1)up(n-1);		//��ǰ��n-1�� 
	if(n>2)down(n-2);	//��ǰ��n-2) 
	str_L[n-1]='1';		//���ֽ⻷ 
	str_R[9-n]='1';		//���ֽ⻷ 
	printf("��%4d��  ��%d    %s    %s\n",++Steps,n,str_L,str_R); //��n
	Space();			//���ո���� 
	if(n>2)up(n-2);		// ��ǰ��n-2�� 
 } 
//ͬ���к�������� ���¡�
void down(int n)
{
	//���������up���������еĲ����෴ 
	//��ǰn=��ǰ��n-2������n����ǰ��n-2������ǰ��n-1��
	if(n>2) down(n-2);	//��ǰ��n-2�� 
	str_L[n-1]='0';		//���ֽ⻷ 
	str_R[9-n]='0';		//���ֽ⻷ 
	printf("��%4d��  ��%d    %s    %s\n",++Steps,n,str_L,str_R); //��n
	Space();			//���ո���� 
	if(n>2)up(n-2);		//��ǰ��n-2�� 
	if(n>1)down(n-1);	//��ǰ��n-1�� 
}


