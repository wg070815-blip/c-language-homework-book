//1.快速排序（递归）：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10
void quicksort(int a[], int low, int high);
int spilt(int a[], int low, int high);
int main(void) {
	printf("Enter %d numbers to be sorted:", N);
	int i;
	int a[N];
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	quicksort( a, 0, N - 1);
	printf("In sorted order:");
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

//函数1说明：
int spilt(int a[], int low, int high) {
	int fg_ele = a[low];
	for (; ;) {
		while (low < high && a[high] >= fg_ele) {
			high--;
		}
		if (low >= high) {
			break;
		}
		a[low++] = a[high];
		
		while (low < high && a[low] <= fg_ele) {
			low++;
		}
		if (low >= high) {
			break;
		}
		a[high--] = a[low];
	}
	a[high] = fg_ele;
	return high;
}

//函数2说明
void quicksort(int a[], int low, int high) {
	int middle;
	if (low >= high) {
		return;
	}
	middle = spilt(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}



//2.
int check(int x, int y, int n) {
	return ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1)) ? 1 : 0;
}



