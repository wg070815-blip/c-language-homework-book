1.凯撒加密：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 81
int main(void) {
	printf("Enter message to be encrypted:");
	char jz[N];
	fgets(jz, N, stdin);
	for (int k = 0; jz[k] != '\0'; k++) {          //用 \0 遍历（推荐），提前把换行\n抹掉!!!!!!!!!!
		if (jz[k] == '\n') {
			jz[k] = '\0';
			break;
		}
	}
	printf("Enter shift amount (1-25):");
	int shift;
	scanf("%d", &shift);
	printf("Encrypted message: ");
	int i;
	for (i = 0; jz[i] != '\0'; i++) {          //依靠\0遍历整个字符串，更标准!!!!!!!!!!!!!!
		if (jz[i] >= 'A' && jz[i] <= 'Z') {
			jz[i] = ((jz[i] - 'A') + shift) % 26 + 'A';
			putchar(jz[i]);
		}
		else	if (jz[i] >= 'a' && jz[i] <= 'z') {
			jz[i] = ((jz[i] - 'a') + shift) % 26 + 'a';
			putchar(jz[i]);
		}
		else {
			putchar(jz[i]);
		}
	}
	printf("\n");
	return 0;
}



2.编程测试两个单词是否为变位词（相同字母的重新排序）：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 26
int main(void) {
	int num[N] = { 0 };
	char ch;
	printf("Enter first word:");
	while ((ch = getchar()) != '\n') {
		if (ch >= 'A' && ch <= 'Z') {
			num[ch - 65] += 1;
		}
		else if (ch >= 'a' && ch <= 'z') {
			num[ch - 97] += 1;
		}
	}
	//getchar();                             //读到回车\n时，循环条件不成立，循环直接结束，回车这个字符已经被 getchar 读取并丢弃了
	                                         //此时输入缓冲区已经干干净净，没有残留的回车了。故不需要再加上getchar（）;
	printf("Enter second word:");
	while ((ch = getchar()) != '\n') {
		if (ch >= 'A' && ch <= 'Z') {
			num[ch - 65] -= 1;
		}
		else if (ch >= 'a' && ch <= 'z') {
			num[ch - 97] -= 1;
		}
	}
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (num[i] != 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("The words are anagrams.");
	}
	else {
		printf("The words are not anagrams.");
	}
	return 0;
}



3.编写程序打印nxn的幻方（1，2，... ，n的平方 的方阵排列，且每行、每列和每条对角线上的和都相等）。由用户指定n的值：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 99  // 题目最大n=99

int main(void)
{
    int n;
    int magic[MAX][MAX] = { 0 }; // 数组初始全部为0
    int row, col;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    // 1放在第0行，中间列
    row = 0;
    col = n / 2;//数组下标从零开始
    magic[row][col] = 1;

    // 依次填充数字 2 ~ n*n
    for (int num = 2; num <= n * n; num++)
    {
        // 先计算左上位置
        int new_r = row - 1;
        int new_c = col + 1;

        // 行越界绕到最后一行
        if (new_r < 0)
            new_r = n - 1;
        // 列越界绕到第0列
        if (new_c >= n)
            new_c = 0;

        if (magic[new_r][new_c] == 0)
        {
            // 空位，放入数字
            row = new_r;
            col = new_c;
        }
        else
        {
            // 被占用，放到原数字正下方
            row = row + 1;
        }
        magic[row][col] = num;
    }

    // 打印幻方
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", magic[i][j]);
        }
        printf("\n");
    }

    return 0;
}