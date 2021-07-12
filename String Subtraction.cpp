#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char str1[100000];
char str2[100000];
char ch, c;
int flag[10000] = { 0 };
int main()
{
	while (gets(str1))
	{
		gets(str2);
		for (int i = 0; i < strlen(str2); ++i) {
			ch = str2[i];
			flag[ch] = 1;
		}
		for (int i = 0; i < strlen(str1); ++i) {
			c = str1[i];
			if (flag[c] == 0) {
				printf("%c", c);
			}
		}
		memset(flag, 0, sizeof(flag));
		printf("\n");
	}
	return 0;
}