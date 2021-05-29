#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#define N 800
using namespace std;
class SelectSort
{
public:
	void selectSort(int arr[], int length)
	{
		for (int i = 0; i < length - 1; i++) {
			int index = i;
			for (int j = i + 1; j < length; j++) {
				if (arr[j] < arr[index]) {
					index = j;
					change = true;
				}
			}
			if (change == true) {
				swap(&arr[index], &arr[i]);
			}
		}
	}

private:
	bool change;
	void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
};

int main()
{
	int length, data[N];
	cout << "数组长度：";
	cin >> length;
	cout << "数组元素：";
	for (int i = 0; i < length; i++) {
		cin >> data[i];
	}
	SelectSort ss;
	ss.selectSort(data, length);
	cout << "采用选择排序后的数组是：";
	for (int i = 0; i < length; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	return 0;
}