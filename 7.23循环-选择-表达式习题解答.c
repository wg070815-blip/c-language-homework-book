//1.编写程序，找出用户输入的一串数中的最大数。程序需要提示用户一个一个地输入数。当用户输入0或负数时，程序必须显示出已输入的最大非负数：（输入的数不一定是整数）
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	float num , max = 0;
	for (; ;) {
		printf("Enter a number:");
		scanf("%f", &num);
		if (num <= 0) 
			break;
		while (num > 0) {                  //不需要双层循环嵌套，while的内层嵌套可以改为:if(num>max){
			                               //                                                 max = num;}
			if (num >= max) {
				max = num;
			}
			else {
				max = max;
			}
			break;
		}
	}
		printf("The largest number entered was:%.2f", max);
	return 0;
}



//2.编写程序，要求用户输入两个整数，然后计算并显示这两个整数的最大公约数 （GCD) ：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {                                              //此代码错误。
	int num1, num2;
	printf("Enter two integers:");
	scanf("%d  %d", &num1, &num2);
	for (; num2 > 0; num1 %= num2) {
		num1 = num2;
		num2 = (num1 %= num2);
	}
	printf("Greateast common divisor:%d\n", num1);
	return 0;
}                                                              //逻辑混乱。且未考虑输入数为负数的情况。
 
 
//订正：
int main(void) {
	int num1, num2, rem;
	printf("Enter two integers:");
	scanf("%d  %d", &num1, &num2);
	if (num1 < 0) {
		num1 = -num1;
	}
	if (num2 < 0) {
		num2 = -num2;
	}
	while (num2 != 0) {
		rem = num1 % num2;
		num1 = num2;
		num2 = rem;
	}
	printf("Greast common divisor:%d\n", num1);
	return 0;
}



//3.编写程序，要求用户输入一个分数，然后将其约分为最简分式：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int i, j, a, b, k;
	printf("Enter a fraction:");
	scanf("%d / %d", &i, &j);
	a = i, b = j;                                        //!!!***:其实还不够完善，还要添加输入数为负数的情况。
	if (j == 0) {                                        //而这可以用条件表达式：int m = i < 0 ? -i : i;		                                                 //  
		printf("False!");                                //                      int n = j < 0 ? -j : j; 
		return 0;
	}
	while (j != 0) {
		k = i % j;
		i = j;
		j = k;
	}
	printf("In lowest terms:%d / %d\n", a / i, b / i);
	return 0;
}



//4.在某个程序添加循环，以便用户可以输入多笔交易，并且可以计算每次的佣金。程序在用户输入的交易额为零时终止。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
    float commission, value;
    for (; ;) {
        printf("Enter value of trade: ");
        scanf("%f", &value);
        if (value < 2500.00f) {
            commission = 30.00f + .017f * value;
            
        }
        if (value < 6250.00f) {
            commission = 56.00f + .0066f * value;
            
        }
        if (value < 20000.00f) {
            commission = 76.00f + .0034f * value;                    //此题要注意：容易搞混嵌套。需要勤加思考。！！！！！
            
        }
        if (value < 50000.00f) {
            commission = 100.00f + .0022f * value;
            
        }
        if (value < 500000.00f) {
            commission = 155.00f + .0011f * value;
           
        }
        if (value >= 500000.00f) {
            commission = 255.00f + .0009f * value;
            
        }
        if (commission < 39.00f) {
            commission = 39.00f;
            
        }
        printf("Commission: $%.2f\n", commission);
        
    }


	return 0;
}



//5.第四章的编程题1要求编写程序显示出两位数的逆序。设计一个更具一般性的程序，可以处理一位、两位、三位或者更多位的数。
  提示：使用do循环将输入的数重复除以10，直到值达到0为止。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	//int num1, num2;
	//printf("Enter a two-digit number:");
	//scanf("%d", &num1);
	//do {
	//	num1 /= 10;                                                  //思路错误！！！
	//	num2 = (num1%=10;
	//} while (num1 != 0);
	//printf("The reversal is:%d",num1*10 + num2)
	//
	//订正：
	int  num1, num2;
	printf("Enter a two-digit number:");
	scanf("%d", &num1);
	printf("The reversal is:");//关键点
	do {
		printf("%d", num1 % 10);//先取出最后一位打印
		num1 = num1 / 10;//去掉最后一位
	} while (num1 != 0);



	return 0;
}



//6. 编写程序，提示用户输入一个数n，然后显示出1~n的所有偶数平方值。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	printf("Enter a number:");
	int n, i = 0;
	scanf("%d", &n);
	for (; i <= n; i++) {
		if (i % 2 == 0) {              //注意：判等是"两个="！！！
			printf("%d\n", i * i);
		}
		if (i * i > n) {
			break;
		}
		
	}


	return 0;
}



//8.编写一个程序显示单月的日历。用户显示这个月的天数和该月起始日是星期几：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int days, starting_day, i, k, change;
	printf("Enter number of days in month:");
	scanf("%d", &days);
	printf("Enter starting day of the week ( 1=Sun, 7=Sat ):");
	scanf("%d", &starting_day);
	for (k = 1; k < starting_day; k++) {
		printf("   ");                                //将第一个数前面的空白打印出来
	}
	change = starting_day;                             //需要换行的变量
	for (i = 1; i <= days; i++) {
		printf("%3d", i);                             //%3d中的3符合题目格式，同时满足右对齐。
		if (change == 7) {
			printf("\n");
			change = 1;
		}
		else {
			change++;
		}
	}
	printf("\n");
	return 0;
}



//9.第二章的编程题8要求编程计算第一、第二、第三个月还贷后剩余的贷款金额。修改该程序，要求用户输入还贷次数并显示每次还贷后剩余的贷款金额。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	float loan, rate, payment, balance, j;
	int times, i=1;
	printf("Enter amount of loan:");
	scanf("%f", &loan);
	printf("Enter interest rate:");
	scanf("%f", &rate);
	printf("Enter monthly payment:");
	scanf("%f", &payment);
	printf("Enter the paying-times:");
	scanf("%d", &times);
	j = (rate / 100.0) / 12;
	for (; i <= times; i++) {
		if (loan <= 0) {
			break;
		}
		printf("Balance remaining after %d payment:$", i);
		printf("%.2f\n", (loan - payment) + loan * j);
		loan = (loan - payment) + loan * j;		
	}
	return 0;
}



//10.第5章的编程题9要求编写程序判断哪个日期更早。泛化该程序，使用户可以输入任意个日期。用0/0/0指示输入结束，不再输入日期。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int month, day, year, min_month, min_day, min_year;
	//for (; ;) {
	//	printf("Enter a date (mm/dd/yy):");
	//	scanf("%2d/%2d/%2d", &month, &day, &year);
	//	if (min_year <= year) {
	//		min_year = min_year;                                  // 思路出现问题！！！
	//	}
	//	if (min_year > year) {
	//		min_year = year;
	//	}
	//订正：
    min_month = 12;
    min_day = 31;                               //***//    // 存储当前最小日期，初始值设为一个很大的日期，保证第一个输入必然覆盖
    min_year = 99;

    while (1)
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);

        // 输入0/0/0，退出循环
        if (month == 0 && day == 0 && year == 0)
            break;

        // 比较逻辑：判断当前日期是否比记录的最小日期更早
        if (year < min_year)
        {
            min_month = month;                        //第一次输入的就会同步储存好
            min_day = day;
            min_year = year;
        }
        else if (year == min_year && month < min_month)
        {
            min_month = month;
            min_day = day;
        }
        else if (year == min_year && month == min_month && day < min_day)
        {
            min_month = month;
            min_day = day;
        }
    }

    // 输出结果，和题目格式保持一致
    printf("%d/%d/%02d is the earliest date\n", min_month, min_day, min_year);
	return 0;
}



//11.数学常量e的值可以用一个无穷级数表示：e=1+1/1！+1/2！+1/3！+···
//   编写程序，用下面的公式计算e的近似值：1+1/1！+1/2！+1/3！+···+1/n!      这里n是用户输入的整数。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int n, i;
	double e = 1;
	double term = 1;
	printf("Enter the n:");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		term = term / i;                       //极其巧妙，写的时候没想到
		e = e + term;
	}
	printf("e的近似值:%.10f\n", e);
	return 0;
}



//12.修改编程题11，使得程序能够持续进行加法运算，直到当前项小于某个数为止，其中某个数是用户输入的较小的（浮点）数。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int n, i=1;
	double e = 1, term = 1, min_term;
	printf("Please input precision min_term: ");
	scanf("%lf", &min_term);
	for (; ;) {
		term = term / i;
		if (term < min_term) {
			break;
		}
		e = e + term;
		i++;
	}
	printf("Approximate e = %.10f\n", e);
	return 0;
}