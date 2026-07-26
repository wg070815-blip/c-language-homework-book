1.编写程序，要求用户输入12小时制的时间，然后用24小时制显示该时间：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	while (1) {
		printf("Enter a 12-hour-time(输入q/Q退出):");
		int hour12, minute;
		char ch1, ch2;
		int ret = scanf("%d:%d %c%c", &hour12, &minute, &ch1, &ch2);
		if (ret != 4) {
			char ch3 = getchar();            // 读取缓冲区第一个字符看看是不是 q/Q
			if (ch3 == 'q' || ch3 == 'Q') {
				printf("See you next time!\n");
				break;
			}
			while (getchar() != '\n');// 不是q，清空缓冲区，提示错误
			printf("Wrong!\n");
			continue;
		}
		while (getchar() != '\n');// 清空回车,为下一次循环做准备
		int hour24;
		switch (ch1) {
		case'A':
		case'a':hour24 = (hour12 == 12) ? 0 : hour12;
			break;
		case'P':
		case'p':hour24 = (hour12 == 12) ? 12 : hour12 + 12;
			break;
		}
		if (ch1 != 'a' && ch1 != 'A' && ch1 != 'P' && ch1 != 'p') {
			printf("wrong!\n");
			continue;
		}
		printf("Equivalent 24-hour time:%d:%02d\n", hour24, minute);//%02d：不足两位前面自动补 0
	}
	return 0;
}



2.编写程序统计句子中元音字母（a、e、i、o、u）的个数：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	printf("Enter a sentence:");
	int sum = 0;
	char ch;
	ch = getchar();
	while (ch != '\n') {
		switch (ch) {
		case'a':
		case'A':
		case'e':
		case'E':
		case'i':
		case'I':
		case'o':
		case'O':
		case'u':
		case'U':sum++;
			break;
		}
		ch = getchar();//循环读取下一个字符
	}
	printf("Your sentence contains %d vowels.\n", sum);
	return 0;
}



3.编写一个程序，要求用户输入英文名和姓，并根据用户的输入先显示姓，其后跟一个逗号，然后显示名的首字母，最后加一个点：
  用户的输入中可能包含空格（名之前、名和姓之间、姓氏之后）。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	printf("Enter a first and last name:");
	char first[50];   // 存放完整的名：wugeng     //其中first和last是自己起的变量名
	char last[50];    // 存放完整的姓：Cheng

	// 自动忽略前后、中间所有空格
	scanf(" %s %s", first, last);//%s 读取紧接着一整个单词
	                             //%s 会读取一整个连续英文单词（遇到空格就停下)
								 // ***普通变量（int /char/double）：1.scanf 里一律写 &变量
	                             //                                  2.char 数组 / 字符串数组：scanf 直接写数组名字，不加 &***
	// last是姓，first[0]是名字第一个字母
	printf("%s, %c.\n", last, first[0]);
	return 0;
}



4.编写程序对表达式求值：
  表达式中的操作数是浮点数，运算符是+、-、*和/。表达式从左向右求值（所有运算符的优先级都一样）。
**实现思路:
           1.先读取第一个浮点值作为初始结果
           2.循环不断读取【运算符 + 下一个浮点数】
           3.根据运算符，从左往右更新结果
           4.无更多数据时输出最终值
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
    double res, num;//定义变量
    char op;//定义运算符

    printf("Please input your expression(such as: 3.5 + 2.0 * 4): ");
    
    scanf("%lf", &res);// 读取第一个数字

    // 循环读取 运算符+数字，读到文件末尾自动停止
    while (scanf(" %c %lf", &op, &num) == 2)//scanf(格式串, 参数列表) 的返回值 = 本次成功匹配并读取到的数据个数
    {                                       //读不到完整一组（比如输入回车结束、乱输字符）→ 返回值不等于 2，循环直接结束
        switch (op)
        {
        case '+':
            res = res + num;
            break;
        case '-':
            res = res - num;
            break;
        case '*':
            res = res * num;
            break;
        case '/':
            if (num == 0)
            {
                printf("Error: Divisor cannot be zero!\n");
                return 1;                                      //数学上不能除以 0，继续运行程序会直接崩溃。
            }                                                  //打印错误提示 → 执行return 1，立刻强制结束整个 main 函数、程序直接退出，不再执行后面的计算、输出结果代码。
            res = res / num;
            break;
        default:
            printf("Unknown operator!\n");
            return 1;
        }
    }

    printf("Calculation result = %.2lf\n", res);
	return 0;
}



5.编写程序计算句子的平均词长：
  简单起见，程序中把标点符号看作其前面单词的一部分。平均词长显示一个小数位。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
    printf("Enter a sentence:");
    char ch;
    int total_char = 0;// 所有单词的总字符（包含标点）
    int word_cnt = 0;// 单词总数
    int in_word = 0;// 标记：0=当前在空格区  1=当前在单词内部                   ***************

    while ((ch = getchar()) != '\n')
    {
        if (ch != ' ')                        //遍历每个字符ch：
                                              //               1.如果 ch != ' '（是字母 / 标点）:
                                              //                                                 total_char++ 字符总数累加
                                              //                                                 如果 in_word == 0 → 说明刚进入一个新单词
                                              //                                                 word_cnt++; in_word = 1;
                                              //               2.如果 ch == ' '（读到空格）:
                                              //                                            in_word = 0; 标记离开单词区域
                                              //               3. 读到换行\n结束遍历                         
        {
            total_char++;
            if (in_word == 0)
            {
                word_cnt++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
    }
    // 防止空句子除以0报错
    if (word_cnt == 0)
    {
        printf("No words input\n");
        return 0;
    }
    // 保留1位小数
    double avg = (double)total_char / word_cnt;
    printf("Average word length: %.1f\n", avg);
	return 0;
}



6.编写程序，用牛顿方法计算正浮点数的平方根：
  设x是用户输入的数。牛顿方法需要先给出x平方根的猜测值y（我们使用1）。后续的猜测值通过计算y和x/y的平均值得到。
  注意，y 的值逐渐接近 x 的平方根。为了获得更高的精度，程序中应使用 double 类型的变量代替float类型的变量。当y的新旧值之差的绝对值小于0.000 01和y的乘积时程序终止。
  提示：调用fabs函数求 double 类型数值的绝对值。（为了使用 fabs 函数，需要在程序的开头包含<math.h>头。）
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void) {
	printf("Enter a positive number:");
	int x;
	double y = 1, i, j, k, front_y;
	scanf("%d", &x);
	do {
		front_y = y;
		i = x / y;
		j = (i + y) / 2;
		y = j;
		k = fabs(y - front_y);
	} while (k >= 0.00001 * y);
	printf("Square root: %lf\n", y);
	return 0;
}



7.编程计算正整数的阶乘：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num;
	printf("Enter a positive integer: ");
	scanf("%d", &num);

	// ========== 这里更换类型即可对应a~g ==========
	long long res = 1;
	// short res=1;        输出%hd
	// int res=1;          输出%d
	// long res=1;         输出%ld
	// float res=1;        输出%f
	// double res=1;      输出%f
	// long double res=1;  输出%Lf

	for (int i = 1; i <= num; i++)
	{
		res = res * i;
	}
	printf("Factorial of %d: %lld\n", num, res);
	return 0;
}