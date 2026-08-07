快速排序：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10

void quicksort(int a[], int low, int high);
int spilt(int a[], int low, int high);

int main(void) {
	printf("Enter %d numbers to be sorted:", N);
	int a[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, N - 1);
	printf("In sorted order:");
	for (int i = 0; i < N; i++) {
		printf("  %d", a[i]);
	}
	printf("\n");
	return 0;
}


int spilt(int a[], int low, int high) 
{
	int fj_num = a[low];
	
	for ( ; ; ) {
		while (low < high && a[high] >= fj_num) {
			high--;
		}
		if (low >= high) {
			break;
		}
		a[low++] = a[high];

		while (low < high && a[low] <= fj_num) {
			low++;
		}
		if (low >= high) {
			break;
		}
		a[high--] = a[low];
	}
	a[high] = fj_num;
	return high;
}


void quicksort(int a[], int low, int high) 
{
	int middle;
	if (low >= high) return;
	middle = spilt(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}



编写函数，使得函数返回特定值：

(1):返回数组a中最大的元素：
int sort(int a[], int n)
{
	int max_ele;
	max_ele = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] >= max_ele) {
			max_ele = a[i];
		}
	}
	return max_ele;
}

(2):返回数组a中所有元素的平均值：
double pj(int a[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	double pj_num = sum / n;
	return pj_num;
}

(3):返回数组a中正数元素的数量：
int z_num(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0){
			sum += 1;
		}
	}
	return sum;
}



编写函数：
float compute_GPA(char grades[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++) {
		char ch = toupper(grades[i]);
		switch (ch) {
		case'A':sum += 4; break;
		case'B':sum += 3; break;
		case'C':sum += 2; break;
		case'D':sum += 1; break;
		case'F':sum += 0; break;
		}
	}
	return sum / n;
 }



编写函数：
double inner_product(double a[], double b[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}



编写函数对棋盘位置求值：
int evaluate_position(char board[8][8])
{
	int white = 0, black = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char ch = board[i][j];
			switch (ch)
			{
			case 'Q': white += 9; break;
			case 'R': white += 5; break;
			case 'B': white += 3; break;
			case 'N': white += 3; break;
			case 'P': white += 1; break;
			case 'q': black += 9; break;
			case 'r': black += 5; break;
			case 'b': black += 3; break;
			case 'n': black += 3; break;
			case 'p': black += 1; break;
			}
		}
	}
	return white - black;
}



编程题：

1.编写程序，要求包含函数进行特定操作：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 100
void selection_sort(int a[], int n)
{
	if (n <= 1) return;
	int max_idx = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[max_idx]) {
			max_idx = i;
		}
	}
	int temp = a[max_idx];
	a[max_idx] = a[n - 1];
	a[n - 1] = temp;

	selection_sort(a, n - 1);
}

int main(void) {
	int a[N], n;
	printf("Enter your n:");
	scanf("%d", &n);
	printf("Enter n numbers:");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	selection_sort(a, n);
	printf("The number is:");
	for (int j = 0; j < n; j++) {
		printf("  %d", a[j]);
	}
	printf("\n");
	return 0;
}



2.修改第8章的编程题9，使其包含函数来计算：
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define N 10

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main(void) {
	srand((unsigned)time(NULL));
	char walk[N][N];
	generate_random_walk(walk);
	print_array(walk);
	system("pause");
	return 0;
}

void generate_random_walk(char walk[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			walk[i][j] = '.';
		}
	}
	int row = 0, col = 0;
	char ch = 'A';
	walk[row][col] = ch;
	ch++;
	int yd[4][2] = { { 1, 0},
				   {-1, 0},
				   { 0, 1},
				   { 0,-1} };
	int new_row, new_col;
	while (ch <= 'Z') {
		int initial_dir = rand() % 4;
		int final_dir, have_way = 0;
		// 不要提前全局new_row new_col，在循环内临时存放合法坐标
		int temp_r, temp_c;
		for (int i = 0; i < 4; i++) {
			final_dir = (initial_dir + i) % 4;
			temp_r = row + yd[final_dir][0];
			temp_c = col + yd[final_dir][1];
			if (temp_r >= 0 && temp_r < N && temp_c >= 0 && temp_c < N && walk[temp_r][temp_c] == '.')
			{
				// 找到合法路径
				new_row = temp_r;
				new_col = temp_c;
				have_way = 1;
				break;
			}
		}
		if (have_way == 0) {
			break;
		}
		walk[new_row][new_col] = ch;
		row = new_row;
		col = new_col;
		ch++;
	}
}
void print_array(char walk[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			putchar(walk[i][j]);
			putchar(' ');
		}
		printf("\n");
	}
}



修改第8章的编程题16，使其包含下列函数：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// 函数声明（题目指定原型）
void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int count1[26] = { 0 };
    int count2[26] = { 0 };

    printf("请输入第一个单词：");
    read_word(count1);

    printf("请输入第二个单词：");
    read_word(count2);

    if (equal_array(count1, count2))
    {
        printf("两个单词是变位词！\n");
    }
    else
    {
        printf("两个单词不是变位词！\n");
    }

    return 0;
}

// 读取单词，统计字母频次存入counts数组（忽略大小写）
void read_word(int counts[26])
{
    char ch;
    // 循环读取字符直到换行
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch)) // 判断是否是字母
        {
            ch = tolower(ch); // 统一转为小写
            counts[ch - 'a']++;
        }
    }
}

// 对比两个字母计数数组，全部相等返回true，否则false
bool equal_array(int counts1[26], int counts2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (counts1[i] != counts2[i])
        {
            return false;
        }
    }
    return true;
}



修改第八章编程题17：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 题目指定：不支持变长数组时使用此原型
void create_magic_square(int n, int magic_square[99][99]);
void print_magic_square(int n, int magic_square[99][99]);

int main(void)
{
    int n;
    int magic[99][99] = { 0 }; // 最大支持99阶幻方

    printf("请输入幻方阶数(奇数): ");
    scanf("%d", &n);

    // 简单校验：必须是奇数
    if (n % 2 == 0 || n <= 0 || n >= 99)
    {
        printf("请输入1~99之间的奇数！\n");
        return 1;
    }

    create_magic_square(n, magic);
    print_magic_square(n, magic);

    return 0;
}

// 构造幻方：罗伯法（奇数幻方算法）
void create_magic_square(int n, int magic_square[99][99])
{
    int row = 0;
    int col = n / 2;  // 第一行中间位置放1

    for (int num = 1; num <= n * n; num++)
    {
        magic_square[row][col] = num;

        // 右上移动
        int new_r = row - 1;
        int new_c = col + 1;

        // 越界处理
        if (new_r < 0) new_r = n - 1;
        if (new_c >= n) new_c = 0;

        // 如果目标位置为空，移动；否则向下走一格
        if (magic_square[new_r][new_c] == 0)
        {
            row = new_r;
            col = new_c;
        }
        else
        {
            row = row + 1;
        }
    }
}

// 打印幻方
void print_magic_square(int n, int magic_square[99][99])
{
    printf("\n%d阶幻方：\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", magic_square[i][j]);
        }
        printf("\n");
    }
}



编写函数计算下面多项式的值：
#include <stdio.h>

// 计算多项式的函数
double calc_poly(double x)
{
    // 直接展开计算
    double res = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
    return res;
}

int main(void)
{
    double x, result;
    printf("请输入x的值：");
    scanf("%lf", &x);

    result = calc_poly(x);
    printf("多项式结果 = %.4lf\n", result);

    return 0;
}



编写计算x的n次方:
#include <stdio.h>

// 递归快速幂函数 power(x, n) 计算 x^n
double power(double x, int n)
{
    // 递归终止条件
    if (n == 0)
        return 1.0;
    // n偶数
    else if (n % 2 == 0)
    {
        double half = power(x, n / 2);
        return half * half;
    }
    // n奇数
    else
    {
        return x * power(x, n - 1);
    }
}

int main(void)
{
    double x;
    int n;
    printf("请输入底数x：");
    scanf("%lf", &x);
    printf("请输入指数n（非负整数）：");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("指数不能为负数！\n");
        return 1;
    }

    double result = power(x, n);
    printf("%.2lf^%d = %.4lf\n", x, n, result);
    return 0;
}



//编写函数模拟掷骰子(两个骰子):
#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int roll_dice(void)
{
	int num1 = (rand() % 6) + 1;
	int num2 = (rand() % 6) + 1;
	return num1 + num2;
}

bool play_game(void) {
	int sum = roll_dice();
	printf("You rolled:%d\n", sum);
	if (sum == 7 || sum == 11) {
		printf("You win!\n");
		return true;
	}
	else if (sum == 2 || sum == 3 || sum == 12) {
		printf("You lose!\n");
		return false;
	}
	else {
		int point = sum;
		printf("Your point is %d\n", point);
		for ( ; ; ) {
			sum = roll_dice();
			printf("You rolled:%d\n", sum);
			if (sum == point)
			{
				printf("You win!\n");
				return true;
			}
			if (sum == 7)
			{
				printf("You lose!\n");
				return false;
			}
		}
	}
}

int main(void) {
	srand((unsigned)time(NULL));
	int Wins = 0, Losses = 0;
	char again;
	do {
		bool win = play_game();
		if (win) {
			Wins++;
		}
		if (!win) {
			Losses++;
		}
		printf("Play again?\n");
		scanf(" %c", &again);
	} while (again == 'Y' || again == 'y');
	printf("Wins: %d  Losses: %d\n", Wins, Losses);
	return 0;
}