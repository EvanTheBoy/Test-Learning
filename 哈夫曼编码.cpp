#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class QuickSort {
	private:
		int index, pivot;
		int partition(int arr[], int low, int high)
		{
			pivot = arr[low];
			while (low < high)
			{
				while (low < high && pivot <= arr[high])
				{
					high--;
				}
				arr[low] = arr[high];
				while (low < high && pivot >= arr[low])
				{
					low++;
				}
				arr[high] = arr[low];
			}
			arr[low] = pivot;
			return low;
		}

	public:
		void quickSort(int arr[], int low, int high)
		{
			if (low < high) {
				index = partition(arr, low, high);
				quickSort(arr, low, index - 1);
				quickSort(arr, index + 1, high);
			}
		}
};
int n;
int p[10000];
int main()
{
	QuickSort qs;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
		}
		qs.quickSort(p, 0, n - 1);
		int sum = 0;
		while (n > 1)
		{
			int i = 0;
			p[i] = p[i] + p[i + 1];
			sum += p[i];
			p[i + 1] = -1;  //这里是处理的一点小技巧，赋值为一个负数，排完序后就肯定是最小的，然后再去掉就可以了
			qs.quickSort(p, 0, n - 1);
			for (int j = 0; j < n - 1; ++j) {
				p[j] = p[j + 1];
			}
			n--;
		}
		printf("%d\n", sum);
	}
	return 0;
}