#include <iostream>
#include <cstdbool>
#define N 1000
using namespace std;
int aikoin(int n)
{
	int flag[N] = { 0 };
	int count = 0;
	for (int i = 2; i < n; ++i) {
		if (!flag[i]) {
			++count;
			for (int j = i * i; j < n; j += i) {
				flag[j] = 1;
			}
		}
	}
	return count;
}
int main()
{
	int n;
	cout << "输入一个数:";
	cin >> n;
	int res = aikoin(n);
	cout << "从1到" << n << "共有" << res << "个素数" << endl;
	return 0;
}