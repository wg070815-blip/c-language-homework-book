1.数列反向：
  要求用户输入一串数，然后按反向顺序输出一串数：
  方法是在读入数时将其存储在一个数组中，然后反向遍历数组，一个接一个地显示出数组元素。换句话说，该程序不会真的对数组中的元素进行反向输出，知识使用户这样认为。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10
int main(void){
	int a[N], i;
	printf("Enter 10 numbers:");
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	printf("In reverse order:");
	for (i = N - 1; i >= 0; i--) {
		printf("  %d", a[i]);
	}
	printf("\n");
	return 0;
}



2.检查数中重复出现的数字：这个程序用来检查数中是否有出现多余一次的数字。用户输入数后，程序显示信息Repeated digit或No Repeated digit:
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main(void) {
	bool digit_seen[10] = { false };
	int digit;
	long n;
	printf("Enter a number:");
	scanf("%ld", &n);
	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit]) {
			break;
		}
		digit_seen[digit] = true;
		n /= 10;
	}
	if (n > 0) {
		printf("Repeated digit\n");
	}
	else {
		printf("NO Repeated digit\n");
	}
	return 0;
}



3.对第2题进行优化，使其能够遍历所有数字，并说明有多少个重复数字以及重复数字分别是多少：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main(void) {
	bool digit_seen[10] = { false };
	int digit, num = 0;
	long n;
	printf("Enter a number:");
	scanf("%ld", &n);
	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit]) {
			num++;
		}
		digit_seen[digit] = true;
		n /= 10;
	}


优化：
int main(void){
	int count[10] = { 0 };
	int i, digit;
	long n;
	printf("Enter a number:");
	scanf("%ld", &n);
	while (n > 0) {
		digit = n % 10;
		count[digit]++;
		n /= 10;
	}
	int sum, seen = 0;
	printf("Repeated digit:");
	for (i = 0; i < 10; i++) {
		if (count[i] > 1) {
			seen++;
			printf("  %d(%d次)", i, count[i]);
		}
	}
	if (seen == 0) {
		printf("No Repeated digit!\n");
	}
	printf("\n");
	printf("      其中共有%d个重复数字\n", seen);
	return 0;
}



4.计算利息：下面这个程序显示一个表格，这个表格显示了在几年时间内100美元投资在不同利率下的价值。用户输入利率和要投资的年数。投资总价值每年计算一次，
  表格将显示出在输入利率和紧随其后的4个更高利率下的投资的总价值。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define num_rates ((int) (sizeof(value) / sizeof(value[0])))
#define initial_balance 100.00
int main(void) {
	int i, rate, num_years, year;
	double value[5];
	printf("Enter interest rate:");
	scanf("%d", &rate);
	printf("Enter number of years:");
	scanf("%d", &num_years);
	printf("\n");
	printf("Years");
	for (i = 0; i < num_rates; i++) {
		printf("%6d%%", rate + i);
		value[i] = initial_balance;
	}
	printf("\n");
	for (year = 1; year <= num_years; year++) {
		printf("%3d    ", year);
		for (i = 0; i < num_rates; i++) {
			value[i] += (rate + i) / 100.0 * value[i];
			printf("%7.2f", value[i]);
		}
		printf("\n");
	}
	return 0;
}



5.发牌：程序负责发一副标准纸牌。每张标准纸牌都有一种花色（梅花、方块、红桃或黑桃）和一个点数（2、3、4、5、6、7、8、9、10、J、Q、K或A）。程序需要用户指明手里应该握有几张牌：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define num_suits 4
#define num_ranks 13

int main(void) {
	srand((unsigned)time(NULL));
	printf("Enter number of cards in hand:");
	bool in_hand[num_suits][num_ranks] = { false };
	int num_cards, rank, suit;
	const char rank_code[] = { '2','3','4','5','6','7','8','9','10','j','q','k','a' };
	const char suit_code[] = { 'c','d','h','s' };
	scanf("%d", &num_cards);
	printf("Your hand:");
	while (num_cards > 0) {
		suit = rand() % num_suits;
		rank = rand() % num_ranks;
		if (!in_hand[suit][rank]) {
			in_hand[suit][rank] = true;
			num_cards--;
			printf("  %c%c", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n");
	return 0;
}



6.声明一个名为weekend的数组，其中包含7个bool值，要求用一个初始化器把第一个值和最后一个值设置为true，其他值都置为false：
#include<stdio.h>
#include<stdbool.h>
int main(void) {
	bool weekend[7] = { true,false,false,false,false,false,true };
}



7.重复第6题，但这次用指示器。要求初始化器尽可能简短：
#include<stdio.h>
#include<stdbool.h>
int main(void) {
bool weekend[7] = { [0] = true,[6] = true };
}



8.斐波那契数列：从第三个数开始，每个数是其前面两个数的和。编写一个程序片段，声明一个名为fib_number的长度为40的数组，并填入前40给斐波那契数。
  提示：先填入前两个数，然后用循环计算其余的数。
#include<stdio.h>
#define N 40
int main(void) {
	int i;
	long long fib_number[N];
	fib_number[0] = 0;
	fib_number[1] = 1;
	for (i = 2; i < N; i++) {
		fib_number[i] = fib_number[i - 1] + fib_number[i - 2];	
	}
	return 0;
}



9.为一个名为temperature_readings的二维数组编写声明。该数组存储一个月中每小时的温度读数。（简单起见，假定每个月有30天。）数组的每一行对应一个月的每一天，每一列对应一天的小时数。
  并通过编写此程序来计算一个月的平均温度（对每月中的每天和每天的每小时取平均）。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define days 30
#define hours 24
int main(void) {
	int temperature_readings[days][hours];
	double tem;
	for (int day = 0; day < days; day++) {
		for (int hour = 0; hour < hours; hour++) {
			//温度计算公式
		}
	}
	int total_data = days * hours;
	double sum = 0.0f;
	for (int day = 0; day < days; day++) {
		for (int hour = 0; hour < hours; hour++) {
			sum += tem;
		}
	}
	printf(",,,");
	return 0;
}



10.计算器、电子手表和其他电子设备经常依靠七段显示器进行数值的输出。为了组成数字，这类设备需要“打开”7 个显示段中的某些部分，同时“关闭”其他部分:




11.有一个名叫BIFF的人，是典型的网络新手，他有一种独特的编写消息的方式：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
int main(void) {
	printf("Enter message:");
	char msg[1000];
	int i = 0;
	fgets(msg, 1000, stdin);
	printf("In BIFF-speak:");
	while (msg[i] != '\0' && msg[i] != '\n') {
		char ch = toupper(msg[i]);
		switch (ch) {
		case'A':putchar('4'); break;
		case 'B': putchar('8'); break;
		case 'E': putchar('3'); break;
		case 'I': putchar('1'); break;
		case 'O': putchar('0'); break;
		case 'S': putchar('5'); break;
		default: putchar(ch); break;
		}
		i++;
	}
	for (i = 0; i < 10; i++) {
		printf("!");
	}
	printf("\n");
	return 0;
}



12.编写程序读取一个5x5的整数数组，然后显示出每行的和与每列的和。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int i, j;
	int row_sum[5] = { 0 };
	int col_sum[5] = { 0 };
	int arr[5][5];
	for (i = 0; i < 5; i++) {
		printf("Enter row %d:", i+1);
		for (j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
			row_sum[i] += arr[i][j];
		}
	}
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			col_sum[j] += arr[i][j];
		}
	}
	printf("Row totals:");
	for (i = 0; i < 5; i++) {
		printf("  %d", row_sum[i]);
	}
	printf("\nColumn totals:");
	for (j = 0; j < 5; j++) {
		printf("  %d", col_sum[j]);
	}
	printf("\n");
	return 0;
}



13.修改编程题7，使其提示用户输入每个学生5门测验的成绩，一共有5个学生。然后计算每个学生的总分和平均分，以及每门测验的平均分、高分和低分。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int i, j;
	double sum1 = 0, sum2 = 0;
	int student_sum[5] = { 0 };
	int col_sum[5] = { 0 };
	int arr[5][5];
	int col_max[5];
	int col_min[5];
	for (i = 0; i < 5; i++) {
		printf("Enter student %d:", i + 1);
		for (j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
			student_sum[i] += arr[i][j];
		}
	}
	for (j = 0; j < 5; j++) {
		col_max[j] = arr[0][j];
		col_min[j] = arr[0][j];
		for (i = 0; i < 5; i++) {
			col_sum[j] += arr[i][j];
			if (arr[i][j] > col_max[j]) {
				col_max[j] = arr[i][j];
			}
			if (arr[i][j] < col_min[j]) {
				col_min[j] = arr[i][j];
			}
		}
	}
	printf("student totals:");
	for (i = 0; i < 5; i++) {
		printf("  %d", student_sum[i]);
		sum1 += student_sum[i];
	}
	printf("The student res_totals:%.2f", sum1 / 5.0);
	printf("\nColumn totals:");
	for (j = 0; j < 5; j++) {
		printf("  %d", col_sum[j]);
		sum2 += col_sum[j];
	}
	printf("The test res_score:%.2f", sum2 / 5.0);
	printf("\n");
	return 0;
	//还有min与max待写...
}