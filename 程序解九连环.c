#include<stdio.h>
///////////   函数声明  ///////////
void Space(void);
void if_continue(void);
void up(int);
void down(int);

//全局变量 
int N;//环数 
int Steps; //步数
char str_L[10]="00000000";
char str_R[10]="000000000";
char c;
///////////   主函数  ///////////
int main()
{
	system("cls");//清屏
	//确保接收的一定为u或d 
	printf("\n1.上环\n2.下环\n\n");
	while(1)
	{
		if(kbhit())
		{
			c = getch();
			if(c == '1')
			{
				printf("上环\n");
				//确保输入的数字为1~9 
				do{
					printf("\n请输入需要解的环(数字1~9):   ");
					scanf("%d",&N);
				}while(N<1||N>9); 
				Steps = 0;
				up(N);
				break;
			}
			else
			{
				printf("下环\n");
				do{
					printf("\n请输入需要解的环(数字1~9):   ");
					scanf("%d",&N);
				}while(N<1||N>9); 
				Steps = 0;
				down(N);
				break;
			}
		}
	}
	printf("\n\t步骤完毕！共 %d 步\n\n按 Enter 继续，按 Esc 退出",Steps);
	//是否继续判断
	if_continue();
	printf("\n\n感谢使用!!!");
	return 0;
} 
///////////   其他函数  ///////////

//只有按空格键才会继续 
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
//按 Enter 继续函数，按 Esc 退出程序 
void if_continue(void)
{
	while(1)
	{
		if(kbhit())
		{
			char ch=getch();
			if(ch==13)
				main();//继续 
			else if(ch==27)
				break;	//退出 
		}
	}
}
//下面两个函数输出的布局为：第n步  操作  左手解环  右手解环
//左手解环就是右手拿叉，左手上、下环时，你看到9个环的状态，右手解环同理 
void up(int n)
{
	//上前n=上(n-1),下(n-2),上 n,上(n-2);
	if(n>1)up(n-1);		//上前（n-1） 
	if(n>2)down(n-2);	//下前（n-2) 
	str_L[n-1]='1';		//左手解环 
	str_R[9-n]='1';		//右手解环 
	printf("第%4d步  上%d    %s    %s\n",++Steps,n,str_L,str_R); //上n
	Space();			//按空格继续 
	if(n>2)up(n-2);		// 上前（n-2） 
 } 
//同文中后来定义的 “下”
void down(int n)
{
	//这个正好与up（）函数中的步骤相反 
	//下前n=下前（n-2），下n，上前（n-2），下前（n-1）
	if(n>2) down(n-2);	//下前（n-2） 
	str_L[n-1]='0';		//左手解环 
	str_R[9-n]='0';		//右手解环 
	printf("第%4d步  下%d    %s    %s\n",++Steps,n,str_L,str_R); //下n
	Space();			//按空格继续 
	if(n>2)up(n-2);		//上前（n-2） 
	if(n>1)down(n-1);	//下前（n-1） 
}


