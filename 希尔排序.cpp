#include <iostream>
#define N 100
using namespace std;
class ShellSort
{
public:
	void shellSort(int arr[], int length)
	{
		for (increment = length / 2; increment > 0; increment /= 2) {  //低级错误以后请不要再犯了，这里不是increment/2.
			for (int i = increment; i < length; i++) {
				int j = i;
				while (j - increment >= 0)
				{
					if (arr[j] < arr[j - increment]) {
						swap(&arr[j], &arr[j - increment]);
						j -= increment;
					}
					else {
						break;
					}
				}
			}
		}
	}

private:
	int increment; //设置一个增量
	void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
};

int main()
{
	int data[N], len;
	cout << "请输入数组长度：";
	cin >> len;
	cout << "请输入数组元素：";
	for (int i = 0; i < len; i++) {
		cin >> data[i];
	}
	ShellSort ss;
	ss.shellSort(data, len);
	cout << "采用希尔排序后的数组是：";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	return 0;
}