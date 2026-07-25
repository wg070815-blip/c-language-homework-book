1.编写可以把字母格式的电话号码翻译成数值格式的程序：
  如果没有电话在身边，参考这里给出的字母在键盘上的对应关系：2=ABC , 3=DEF , 4=GHI , 5=JKL , 6=MNO , 7=PQRS , 8=TUV , 9=WXYZ.
  原始电话号码中的非字母字符（例如数字或标点符号）保持不变：
  可以假设用户输入的字母都是大写字母。
#define _CRT_SRCURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	char num;
	printf("Enter phone number:");
    // 循环读取每一个字符，直到按下回车结束输入
	while (num = getchar() != '\n') {
		if (num >= 'A' && num <= 'C') {
			putchar('2');
		}
        else if (num >= 'D' && num <= 'F')
            putchar('3');
        else if (num >= 'G' && num <= 'I')
            putchar('4');
        else if (num >= 'J' && num <= 'L')
            putchar('5');
        else if (num >= 'M' && num <= 'O')
            putchar('6');
        else if (num >= 'P' && num <= 'S')
            putchar('7');
        else if (num >= 'T' && num <= 'V')
            putchar('8');
        else if (num >= 'W' && num <= 'Z')
            putchar('9');
        else
            // 不是大写字母，原样打印（数字、横杠、标点都走这里）
            putchar(num);
	}
	return 0;
}



2.在十字拼字游戏中，玩家利用小卡片组成英文单词，每张卡片包含一个英文字母和面值。面值根据字母稀缺程度的不同而不同。
  编写程序，通过对单词中字母的面值求和来计算单词的值：
  编写程序应该允许单词中混合出现大小写字母。
  提示：使用toupper库函数。
#define _CRT_SRCURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
int main(void) {
	printf("Enter a word:");
	char ch;
	int sum = 0;
	ch = getchar();
	while (ch != '\n') {
		char up_ch = toupper(ch);//定义大写字母
		int score = 0;// 一堆if只匹配大写字母***
                      // 空格、横杠、数字、标点全都进不去任何if分支(此时score=0，对结果无害）
        if (up_ch == 'A' || up_ch == 'E' || up_ch == 'I' || up_ch == 'L' || up_ch == 'N'
            || up_ch == 'O' || up_ch == 'R' || up_ch == 'S' || up_ch == 'T' || up_ch == 'U')
        {
            score = 1;
        }
        else if (up_ch == 'D' || up_ch == 'G')
        {
            score = 2;
        }
        else if (up_ch == 'B' || up_ch == 'C' || up_ch == 'M' || up_ch == 'P')
        {
            score = 3;
        }
        else if (up_ch == 'F' || up_ch == 'H' || up_ch == 'V' || up_ch == 'W' || up_ch == 'Y')
        {
            score = 4;
        }
        else if (up_ch == 'K')
        {
            score = 5;
        }
        else if (up_ch == 'J' || up_ch == 'X')
        {
            score = 8;
        }
        else if (up_ch == 'Q' || up_ch == 'Z')
        {
            score = 10;
        }
        sum += score;
		ch = getchar();//继续读取第二个字符参与循环
	}
    printf("Scrabble value: %d\n", sum);
	return 0;
}



3.编写程序显示 sizeof(int),sizeof(short),sizeof(long),sizeof(float),sizeof(double),sizeof(long double)的值。
#define _CRT_SRCURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	printf("size of int:%zu\n",sizeof(int));
	printf("size of short:%zu\n",sizeof(short));
	printf("size of long:%zu\n",sizeof(long));
	printf("size of float:%zu\n",sizeof(float));
	printf("size of double:%zu\n",sizeof(double));
	printf("size of long double:%zu\n",sizeof(long double));
	return 0;
}



4.修改第三章的编程题6，使得用户可以对两个分数进行加、减、乘、除运算（在两个分数之间输入+、-、*或/符号）。
#define _CRT_SRCURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include<stdio.h>
// 求最大公约数（辗转相除法）
int gcd(int a, int b) //函数头部标准格式(gcd:自己起的函数名字)     这个函数的作用：接收两个整数，算出它们的最大公约数并返回。
{
    while (b != 0)// 只要余数b不是0，就继续算
    {
        int temp = a % b;// 算出a除以b的余数
        a = b;           // 把原来的b赋值给新的a
        b = temp;        // 把余数赋值给新的b
    }
    return a < 0 ? -a : a; // 保证公约数为正数(三目运算符）
}

int main(void)
{
    printf("Enter two fractions separated by a sign(eg:1/2 + 3/4):");
    int num1, den1, num2, den2;  // num分子 den分母
    char op;//op储存符号
    // 匹配格式：数字/数字 符号 数字/数字
   int ret = scanf("%d/%d %c %d/%d", &num1, &den1, &op, &num2, &den2);       //1.混合格式：% d/% d % c % d/% d 这种带符号匹配的写法
                                                                             //2.格式更复杂，很容易输错格式（少打 /、少打空格、运算符输错），读取极易失败。
                                                                             //3.VS 的静态安全检查会盯紧这种复杂 scanf，强制提醒你：最好接收返回值，判断输入有没有读对，于是冒出了 C6031 波浪警告。
                                                                             //4.这个接收返回值到底有什么实际用处：（1）不加判断的隐患：用户胡乱输入 1+2 # 5/6（把斜杠打成加号）
                                                                             //                                    （2）此时 scanf 匹配失败，5 个数据读不全，返回值不会等于 5，你的num、den变量会是随机垃圾值，后续计算直接乱套。
                                                                             //                                    （3）加上判断就能拦截错误输入！！！！！！
   if (ret != 5)                                                             
   {
       printf("你输入格式不对！");
       return 1;                                              //***//return 非0数字（return 1、return 2…） → 程序遇到错误，异常终止退出
   }
    int res_num, res_den; // 结果分子、分母

    // 分母合法性校验
    if (den1 == 0 || den2 == 0)
    {
        printf("错误：分母不能为0！\n");
        return 1;
    }

    switch (op)           //switch语句还可以选择符号！！！
    {
    case '+':
        res_num = num1 * den2 + num2 * den1;
        res_den = den1 * den2;
        break;
    case '-':
        res_num = num1 * den2 - num2 * den1;
        res_den = den1 * den2;
        break;
    case '*':
        res_num = num1 * num2;
        res_den = den1 * den2;
        break;
    case '/':
        if (num2 == 0)
        {
            printf("错误：被除数不能为0！\n");
            return 1;
        }
        res_num = num1 * den2;
        res_den = den1 * num2;
        break;
    default:
        printf("输入的运算符非法！仅支持 + - * /\n");
        return 1;
    }

    // 约分处理
    int greatest_common_divisor = gcd(res_num, res_den);//前面设置好了公约数如何去求
    int final_num = res_num / greatest_common_divisor;
    int final_den = res_den / greatest_common_divisor;

    // 统一分母为正数（负号放分子）///////////***************！！！！！！！！！！一定要统一分母为正数！！！
    if (final_den < 0)
    {
        final_num = -final_num;
        final_den = -final_den;
    }

    // 输出结果
    printf("运算结果 = %d/%d\n", final_num, final_den);

    return 0;
}



5.对第4题进行修改，使其有计算器的部分功能：
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include<stdio.h>

// 求最大公约数
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a < 0 ? -a : a;
}

int main(void)
{
    // 外层死循环，包裹所有计算逻辑
    while (1)                                     //制造无限循环
    {
        int num1, den1, num2, den2;
        char op;
        int res_num, res_den;

        printf("\n=====分数四则计算器（输入q退出程序）=====\n");
        printf("输入格式示例：1/2 + 3/4\n");
        int ret = scanf("%d/%d %c %d/%d", &num1, &den1, &op, &num2, &den2);

        // 用户输入q，结束整个程序
        if (ret != 5)
        {
            printf("输入格式错误或主动退出程序\n");
            break;                                            //break 的作用：直接跳出最外层的 while(1) 大循环
        }

        // 分母非法，本次计算结束，回到循环开头
        if (den1 == 0 || den2 == 0)
        {
            printf("错误：分母不能为0！本次计算作废\n");
            // 清空缓冲区垃圾字符，防止死循环乱刷屏
            while (getchar() != '\n');
            continue;                                         //continue 只是放弃本次这一轮计算，立刻回到循环最顶部重新等待用户输入，程序没有退出，下一轮马上就要执行 scanf 读取新内容。
                                                              //如果缓冲区留着上次错误输入的脏数据，下一次的scanf会直接读取缓冲区里的旧垃圾，不会等待你键盘打字，疯狂无限报错刷屏，所以必须用 while(getchar()!='\n'); 清空一行所有残留字符。
        }

        // 四则运算分支
        switch (op)
        {
        case '+':
            res_num = num1 * den2 + num2 * den1;
            res_den = den1 * den2;
            break;
        case '-':
            res_num = num1 * den2 - num2 * den1;
            res_den = den1 * den2;
            break;
        case '*':
            res_num = num1 * num2;
            res_den = den1 * den2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("错误：被除数不能为0！本次计算作废\n");
                while (getchar() != '\n');
                continue;
            }
            res_num = num1 * den2;
            res_den = den1 * num2;
            break;
        default:
            printf("运算符非法，仅支持 + - * /\n");
            while (getchar() != '\n');
            continue;
        }

        // 分数约分 + 统一分母为正数
        int g = gcd(res_num, res_den);
        int final_num = res_num / g;
        int final_den = res_den / g;
        if (final_den < 0)
        {
            final_num = -final_num;
            final_den = -final_den;
        }

        printf("计算最简结果 = %d/%d\n", final_num, final_den);
        // 清空缓冲区残留换行，避免下一轮scanf读取异常
        while (getchar() != '\n');
    }
    printf("计算器已关闭\n");
    return 0;
}



6.修改第5章的编程题8，要求用户输入12小时制的时间。输入时间的格式为时：分后跟A、P、AM或PM（大小写均可）。数值时间和AM/PM之间允许有空白（但不强制要求有空白）。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    // 8个航班起飞的总分钟数，纯普通int变量，无数组
    int d1 = 480, d2 = 583, d3 = 679, d4 = 767;
    int d5 = 840, d6 = 945, d7 = 1140, d8 = 1365;

    int hour12, minute;
    char ch1, ch2 = 0;
    // 自动兼容空格、A/a、P/p、AM/PM各种输入格式
    scanf("%d:%d %*[ \t]%c%c", &hour12, &minute, &ch1, &ch2); //scanf 输入格式讲解：
                                                              //                   1.%d:%d：读取 时:分
                                                              //                   2.%*[ \t]：自动跳过中间任意数量的空格，有没有空格都能正常读
                                                              //                   3.后面两个%c：接收 A/P，如果输入是 AM/PM，第二个 c 会读取 M，不影响逻辑
    // 12小时制转为24小时制小时
    int hour24;
    if (ch1 == 'A' || ch1 == 'a')
    {
        hour24 = (hour12 == 12) ? 0 : hour12;
    }
    else
    {
        hour24 = (hour12 == 12) ? 12 : hour12 + 12;
    }
    int userTotal = hour24 * 60 + minute;

    // 挨个对比，找到最接近的航班序号
    int minAbs = fabs(userTotal - d1);//////fabs函数：计算一个数字的绝对值（负数变正数，正数保持原样）即fabs（-28）=28.
    int num = 1;

    int tempGap = fabs(userTotal - d2);                         //这样的比较方式值得学习。
    if (tempGap < minAbs) { minAbs = tempGap; num = 2; }

    tempGap = fabs(userTotal - d3);
    if (tempGap < minAbs) { minAbs = tempGap; num = 3; }

    tempGap = fabs(userTotal - d4);
    if (tempGap < minAbs) { minAbs = tempGap; num = 4; }

    tempGap = fabs(userTotal - d5);
    if (tempGap < minAbs) { minAbs = tempGap; num = 5; }

    tempGap = fabs(userTotal - d6);
    if (tempGap < minAbs) { minAbs = tempGap; num = 6; }

    tempGap = fabs(userTotal - d7);
    if (tempGap < minAbs) { minAbs = tempGap; num = 7; }

    tempGap = fabs(userTotal - d8);
    if (tempGap < minAbs) { minAbs = tempGap; num = 8; }

    // 直接在printf填写文字，全程没有定义任何字符数组
    printf("Closest departure time is ");
    if (num == 1)
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (num == 2)
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (num == 3)
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (num == 4)
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (num == 5)
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (num == 6)
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (num == 7)
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else if (num == 8)
        printf("9:45 p.m., arriving at 11:58 p.m.\n");

    return 0;
}