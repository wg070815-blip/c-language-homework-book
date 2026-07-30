1.编写程序，生成一种贯穿10x10的字符数组（初始时全为字符‘.’）的‘随机步法’。程序必须随机的从一个元素“走到”另一个元素，每次都向上、向下、向左或向右移动一个元素位置。
  已访问过的元素按访问顺序用字母A~Z进行标记。
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define map_size 10
int main(void) {
	// ===================== 1. 配置随机数种子 =====================
	// time(NULL)获取系统当前时间，每次运行数值都不一样
	// srand搭配time，保证每次运行生成的路径不重复
	srand((unsigned)time(NULL));
	int i, j, k;
	char arr[map_size][map_size];
	// ===================== 4. 初始化整张地图全部填充为 '.' =====================
	for (i = 0; i < map_size; i++) {
		for (j = 0; j < map_size; j++) {
			arr[i][j] = '.';
		}
	}
	// ===================== 2. 定义方向数组【4行2列】 =====================
	// dir[方向编号][0] = 行偏移量（控制上下）
	// dir[方向编号][1] = 列偏移量（控制左右）
	// 0:上  1:下  2:左  3:右
	int dir[4][2] = { { 1, 0},
					  {-1, 0},
					  { 0, 1},
					  { 0,-1} };
	int now_x = 0, now_y = 0, new_x, new_y; // 当前所在行，起点固定左上角(0,0)
	char ch = 'A'; // 行走标记字母，从A开始，依次往后A→B→C...→Z
	arr[now_x][now_y] = ch++; // 起点(0,0)放入第一个字母A，随后字母自增变成B
	// ===================== 5. 核心走路循环 =====================
	// 终止条件1：字母写到Z，直接停止行走
	while (ch <= 'Z') {
		int have_way = 0;// 标记本轮是否找到可走的路，0=无路，1=有路
		int start_dir = rand() % 4;// 随机选出第一个尝试的方向（0~3）
		for (k = 0; k < 4; k++) {// 循环尝试4个所有方向，从随机方向开始依次轮询
			// 从随机起点向后依次取方向，%4防止数字超过0~3范围
			int d = (k + start_dir) % 4;
			new_x = now_x + dir[d][1];
			new_y = now_y + dir[d][0];
			// 移动合法性双重判断
		   // 条件1：新坐标不能小于0、不能大于9（不跑出10*10地图）
		   // 条件2：目标格子必须是'.'空白，不能是已经走过的字母
			if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10 && arr[new_x][new_y] == '.') {
				now_x = new_x;
				now_y = new_y;
				arr[now_x][now_y] = ch++; // 当前格子写入字母，字母+1准备下一次使用
				have_way = 1; // 标记成功走到下一步
				break;// 找到合法方向，不用继续试别的方向，跳出for循环
			}
		}
		// 四次方向全部遍历完毕，have_way依旧是0 = 四面全部堵死
		if (have_way == 0) {
			break;
		}
	}
	// ===================== 6. 遍历打印最终10×10地图 =====================
	printf("生成的随机步法地图：\n");
	for (int i = 0; i < map_size; i++)
	{
		for (int j = 0; j < map_size; j++)
		{
			printf("%c ", arr[i][j]); // 每个字符空格隔开，排版整齐
		}
		printf("\n"); // 一行打印完成，换行打印下一行
	}
	return 0;
}



2.修改第5章的编程题8，用一个数组存储航班起飞时间，另一个数组存储航班起飞时间。（时间用整数表示，表示从午夜开始的分钟数。）程序用一个循环搜索起飞
  时间数组，以找到与用户输入的时间最接近的起飞时间。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void) {
	int start_time[] = { 8 * 60,9 * 60 + 43,11 * 60 + 19,12 * 60 + 47,14 * 60,15 * 60 + 45,19 * 60,21 * 60 + 45 };
	int arrive_time[] = { 10 * 60 + 16,11 * 60 + 52,13 * 60 + 31,15 * 60,16 * 60 + 8,17 * 60 + 55,21 * 60 + 20,23 * 60 + 58 };
	printf("Enter your forward starting time:");
	int hour24, minute, i, j, target;
	scanf("%d:%d", &hour24, &minute);
	int z_time = hour24 * 60 + minute;
	int min_time = fabs(z_time - start_time[0]);
	for (i = 1; i < 8; i++) {
		int dcl_time = fabs(z_time - start_time[i]);
		if (dcl_time < min_time) {
			min_time = dcl_time;
			target = i;
		}
	}
	int start_total = start_time[target];
	int h24 = start_total / 60;
	int mte = start_total % 60;
	int show_h12;
	char ch[3];
	if (h24 == 0) {
		show_h12 = 12;
		ch[0] = 'A'; ch[1] = 'M'; ch[2] = '\0';// 字符串封口!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	else if (h24 > 0 && h24 < 12)
	{
		// 1~11点 上午 AM
		show_h12 = h24;
		ch[0] = 'A'; ch[1] = 'M'; ch[2] = '\0';
	}
	else if (h24 == 12)
	{
		// 正午12点 PM
		show_h12 = 12;
		ch[0] = 'P'; ch[1] = 'M'; ch[2] = '\0';
	}
	else
	{
		// 13~23点 下午PM，换算12小时：h24 -12
		show_h12 = h24 - 12;
		ch[0] = 'P'; ch[1] = 'M'; ch[2] = '\0';
	}
	printf("Closest departure time is %d:%02d %s\n", show_h12, mte, ch);
	return 0;
}



3.修改第7章的编程题4，给输出加上标签：
  在显示电话号码之前，程序需要将其（以原始格式或数值格式）存储在一个字符数组中。可以假定电话号码的长度不超过15个字符。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 15
int main(void) {
	printf("Enter phone number:");
	char ph[N];
	fgets(ph, N, stdin);                                    //fgets 函数会自动帮你在读取的字符串末尾补上 \0，不用你手动写代码封口
	printf("Original phone number:%s\n", ph);                //手动挨个给数组元素赋值的写法，系统不会自动加结束符，才需要手动封口。(如第2题需要ch[2]='\0')
	int i, j;
	printf("In numeric form: ");
	for (i = 0;ph[i]!='\0'; i++) { // 只遍历到字符串结束符\0为止，不要写i<N
		switch (ph[i]) {
		case'A':
		case'B':
		case'C':putchar('2'); break;
		case'D':
		case'E':
		case'F':putchar('3'); break;
		case'G':
		case'H':
		case'I':putchar('4'); break;
		case'J':
		case'K':
		case'L':putchar('5'); break;
		case'M':
		case'N':
		case'O':putchar('6'); break;
		case'P':
		case'Q':
		case'R':
		case'S':putchar('7'); break;
		case'T':
		case'U':
		case'V':putchar('8'); break;
		case'W':
		case'X':
		case'Y':
		case'Z':putchar('9'); break;
		default:putchar(ph[i]); break;
		}
	}
	return 0;
}



4.修改第7章的编程题5，用数组存储字母的面值。数组有26个元素，对应字母表中的26个字母。例如，数组元素0存储1（因为字母A的面值为1），数组元素1存储
  3（因为字母B的面值为3），等等。每读取输入单词中的一个字母，程序都会利用该数组确定字符的拼字值。使用数组初始化器来建立该数组。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#define N 26
int main(void) {
	printf("Enter a word:");
	int arr[N] = { 1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };
	int i, j;
	char ch;
	int sum = 0, num;
	while ((ch = getchar()) != '\n') {//要加大括号！！！！！！！
		ch = (char)toupper(ch); //toupper 返回值是 int 类型！！！！！！故要修改返回类型！！！
		num = ch - 65;
		sum += arr[num];
	}
	printf("Scrabble value:");
	printf("%d\n", sum);
	return 0;
}



5.修改第7章的编程题11，给输出加上标签：
  在显示姓（不是名）之前，程序需要将其存储在一个字符数组中。可以假定姓的长度不超过20个字符。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 20
int main(void) {
	printf("Enter a first and last name:");
	char first[N];
	char second[N];
	scanf("%s  %s", first, second);
	printf("You entered the name: %s, %c.", second, first[0]);
	return 0;
}



6.编写程序颠倒句子中单词的顺序：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 100
int main(void) {
	printf("Enter a sentence:");
	char jz[N];
	char ch;
	char end_mark;
	int i = 0;
	for (; ;) {
		ch = getchar();
		if (ch == '?' || ch == '.' || ch == '!') {
			end_mark = ch;
			break;
		}
		jz[i] = ch;
		i++;
}
	jz[i] = '\0';//系统里所有处理字符串的逻辑（遍历字符、判断读到哪结束），全靠识别 \0 停止运行。
	             //执行 buf[i] = '\0' 也就是 buf[最后一值] = '\0'
				 //所有字符串必须用 \0 当做末尾 “终止暗号”。
				 //scanf("%s")、fgets 这类函数，往数组存内容时，系统会自动帮你在末尾补上\0；
				 //现在是自己用getchar()手动一个个赋值给数组，系统不会自动加，必须自己手动写这一行!!!!!!!!!!!!!!!!!!!!!!
				 
				 
			
	//getchar() 不会过滤任何普通字符:空格、字母、单引号'全部原样放进 jz 数组!!!!!!!!!!!!!!!!!!!!
	int right = i - 1;
	printf("Reversal of sentence:");
	int left;
	while (right >= 0) {
		while (right >= 0 && jz[right] == ' ') {
			right--;
		}
		left = right;
		while (left >= 0 && jz[left] != ' ') {
			left--;
		}
		for (int k = left + 1; k <= right; k++) {
			putchar(jz[k]);
		}
		putchar(' ');
		right = left - 1;
	}
	putchar(end_mark);
	printf("\n");
	return 0;
}



