  计算利息：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 5
#define initial_balance 100.0
int main(void) {
	printf("Enter interest rate:");
	int rate, years;
	scanf("%d", &rate);
	printf("Enter number years:");
	scanf("%d", &years);
	double value[N];
	printf("\nYears   ");
	for (int i = 0; i < N; i++) {
		printf("%7d%%", rate + i);
		value[i] = initial_balance;
	}
	printf("\n");
	for (int year = 1; year <= years; year++) {
		printf("%3d     ", year);
		for (int i = 0; i < N; i++) {
			value[i] += (rate + i) / 100.0 * value[i];
			printf("%7.2f", value[i]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}



发牌：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

#define num_hs 4
#define num_ds 13

int main(void) {
	printf("Enter number of cards in hand:");
	int num_cards;
	scanf("%d", &num_cards);
	srand((unsigned)time(NULL));
	bool in_hand[num_hs][num_ds] = { false };
	char ds[num_ds] = { '2','3','4','5','6','7','8','9','t','j','q','k','a'};
	char hs[num_hs] = { 'c','d','h','s' };
	printf("Your hand:");
	int c_ds, c_hs;
	while (num_cards > 0) {
		 c_ds = rand() % num_ds;
		 c_hs = rand() % num_hs;
		if (!in_hand[c_hs][c_ds]) {
			in_hand[c_hs][c_ds] = true;
			printf("  %c%c", ds[c_ds], hs[c_hs]);
			num_cards--;
		}
	}
	printf("\n");
	return 0;
}



“随机步法”：
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 10

int main(void) {
	int i, j;
	char ch[N][N];
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			ch[i][j] = '.';
		}
	} 
	char cr = 'A';
	
	srand((unsigned)time(NULL));
	int yd[4][2] = { {  1,0 },
					 { -1,0 },
					 {  0,1 },
					 {  0,-1 } };
    int start_dir = rand() % 4 , find_ok, new_row, new_col, row = 0, col = 0, dir;
    while(cr<='Z'){
    for (i = 0; i < 4; i++)
    {
        dir = (start_dir + i) % 4;
        new_row = row + yd[dir][0];
        new_col = col + yd[dir][1];

        //判断：不越界，并且是未访问过的点 '.'
        if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N
            && ch[new_row][new_col] == '.')
        {
            //可以走，更新位置，写入字母
            row = new_row;
            col = new_col;
            ch[row][col] = cr;
            cr++;
            find_ok = 1;
            break;
        }
    }

    //四个方向全部走不通，结束游走
    if (find_ok == 0)
    {
        break;
    }
}  
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%c ", ch[i][j]);
        }
        printf("\n");
    }
	return 0;
}



颠倒句子顺序：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 100
int main(void) {
	printf("Enter a sentence:");
	char ch;
	char jz[N];
	int i = 0, end_mark;
	for (; ;) {
		ch = getchar();
		if (ch == '?' || ch == '.' || ch == '!') {
			end_mark = ch;
			break;
		}
		jz[i] = ch;
		i++;
	}
	jz[i] = '\0';
	int right = i - 1;
	while (right >= 0) {
		while (jz[right] == ' ' && right > 0) {
			right--;
		}
		int left = right;
		while (jz[left] != ' ' && left > 0) {
			left--;
		}
		for (i = left + 1; i <= right; i++) {
			putchar(jz[i]);
		}
		putchar(' ');
		right = left - 1;
	}
	putchar(end_mark);
	printf("\n");
	return 0;
}



打印幻方：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 99
int main(void) {
	printf("This program create a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square:");
	int n;
	scanf("%d", &n);
	int hf[N][N] = { 0 };
	hf[0][n / 2] = 1;
	int row = 0, col = n / 2;
	for (int num = 2; num <= n * n; num++) {
		int new_r = row - 1;
		int new_c = col + 1;
		if (new_r < 0) {
			new_r = n - 1;
		}
		if (new_c >= n) {
			new_c = 0;
		}
		if (hf[new_r][new_c] == 0) {
			row = new_r;
			col = new_c;
		}
		else {
			row = row + 1;
		}
		hf[row][col] = num;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", hf[i][j]);
		}
		printf("\n");
	}
	return 0;
}