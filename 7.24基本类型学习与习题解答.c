*数列求和（改进版）：
6.1节编写了一个程序，对用户输入的整数数列求和。该程序的一个问题就是所求出的和（或其中某个输入数）可能会超出int型变量允许的最大值。
     如果程序运行在整数长度为16位的机器上，可能会发生输出结果与预期严重不符的情况（即整数溢出），此时结果是未定义的。为了改变这个
     程序，可以把变量改换成long型。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	long n, sum = 0;
	printf("This program sums a series of integers.\n");
	for (; ;) {
		printf("Enter integers (0 to terminate):");
		scanf("%ld", &n);
		if (n == 0) {
			break;
		}
		else {
			sum += n;
		}
	}
	printf("The sum is:%ld\n", sum);
	return 0;
}



*确定消息的长度：
为了说明字符的读取方式，下面编写一个程序来计算消息的长度。在用户输入消息后，程序显示长度：
消息的长度包括空格和标点符号，但是不包括消息结尾的换行符。
注意：程序需要采用循环结构来实现读入字符和计数器自增操作，循环在遇到换行符时立刻终止。我们既可以采用scanf函数也可以采用getchar函数读取字符，但大多数C程序员更愿意采用getchar函数。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	printf("Enter a message:");
	char ch;
	int length = 0;
	ch = getchar();                                       //*:ch = getchar();完全等价于scanf（"%c",&ch);
	                                                      //***二者共性：
	                                                      //1.不会自动跳过空格、回车、Tab，缓冲区里是什么字符，就读什么字符
														  //2.回车\n、普通空格都会被正常读取存入变量 ch
														  //3.都能拿到键盘输入的任意单个字符                           
	while (ch != '\n') {
		length++;
		ch = getchar();
	}
	printf("Your message was %d character(s) long.\n", length);
	return 0;
}



**编程题：


1.修改6.3节的程序square2.c，每24次平方运算后暂停，并显示下列信息：
  Press Enter to continue. . .
  显示完上述信息后，程序应该使用getchar函数读入一个字符。getchar函数读到用户输入的回车键才允许程序继续。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int i, n;
	char ch;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table:");
	scanf("%d", &n);


	getchar();                             //吸收scanf遗留的换行符，防止getchar直接读取空回车*******!!!!!!



	for (i = 1; i <= n; i++) {
		printf("%10d%10d\n", i, i * i);
		if (i % 24 == 0) {
			printf("Press Enter to continue. . .\n");
			getchar();                                             //之所以在此处会停住的原因：
			                                                       //1.程序运行到这一行，主动去系统的键盘缓冲区拿一个字符
			                                                       //2.如果缓冲区是空的（还没敲任何按键）：程序阻塞（冻结、停下不走下一步代码），不会继续执行循环打印平方表
			                                                       //3.直到在键盘按下按键、按下回车，字符进入缓冲区，getchar()读到字符，函数才执行完毕，代码继续往下跑
			                                                       //4.逻辑是：每打印 24 行平方 → 走到 if 里面 → 触发 getchar () 卡住，只有按回车（其实也不一定非要回车，其他单字符也行，这里刚好题目要求） → 放行，才能继续打印后面内容。
		}
	}
	return 0;
}