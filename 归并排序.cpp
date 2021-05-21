#include <iostream>
#define N 800
using namespace std;
class MergeSort
{
public:
	void mergeSort(int arr[], int length)
	{
		int temp[N];
		divide(arr, 0, length - 1, temp);
	}

private:
	void divide(int arr[], int left, int right, int temp[])
	{
		if (left < right) {
			int mid = (left + right) / 2;
			divide(arr, left, mid, temp);
			divide(arr, mid + 1, right, temp);
			merge(arr, left, mid, right, temp);
		}
	}

	void merge(int arr[], int left, int mid, int right, int temp[])
	{
		int i = left, j = mid + 1, t = 0;
		while (i <= mid && j <= right)
		{
			if (arr[i] <= arr[j]) {
				temp[t++] = arr[i++];
			}
			else {
				temp[t++] = arr[j++];
			}
		}
		while (i <= mid)
		{
			temp[t++] = arr[i++];
		}
		while (j <= right)
		{
			temp[t++] = arr[j++];
		}

		t = 0;
		while (left <= right)
		{
			arr[left++] = temp[t++];
		}
	}
};

int main()
{
	MergeSort ms;
	int data[N], length;
	cout << "请输入数组长度：";
	cin >> length;
	cout << "请输入数组中的所有数：";
	for (int i = 0; i < length; i++) {
		cin >> data[i];
	}
	ms.mergeSort(data, length);
	cout << "采用归并排序后的数组是：";
	for (int i = 0; i < length; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	return 0;
}