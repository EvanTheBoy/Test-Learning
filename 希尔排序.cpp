#include <iostream>
#define N 100
using namespace std;
class ShellSort
{
public:
	void shellSort(int arr[], int length)
	{
		for (increment = length / 2; increment > 0; increment /= 2) {  //�ͼ������Ժ��벻Ҫ�ٷ��ˣ����ﲻ��increment/2.
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
	int increment; //����һ������
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
	cout << "���������鳤�ȣ�";
	cin >> len;
	cout << "����������Ԫ�أ�";
	for (int i = 0; i < len; i++) {
		cin >> data[i];
	}
	ShellSort ss;
	ss.shellSort(data, len);
	cout << "����ϣ�������������ǣ�";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	return 0;
}