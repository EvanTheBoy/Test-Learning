#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

struct store {
	int left;
	int right;
};
char str[100000];

int main()
{
	stack<store>s1;
	store temp, result;
	stack<int>s2;
	while (scanf("%s", str) > 0)
	{
		for (int i = strlen(str) - 1; i >= 0; i--) {
			if (str[i] == ')') {
				s2.push(i + 1);
			}
			else if (!s2.empty()) {
				temp.left = i + 1;
				temp.right = s2.top();
				s1.push(temp);
				s2.pop();
			}
		}
		int size = s1.size();
		for (int j = 0; j < size; j++) {
			result = s1.top();
			printf("%d %d\n", result.left, result.right);
			s1.pop();
		}
	}
	return 0;
}