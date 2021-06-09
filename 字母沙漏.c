#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;
	while (scanf("%d", &n) > 0)
	{
		for (int i = 0; i < 2 * n + 1; i++) {
			if (i < n + 1) {   //沙漏的上半部分
				for (int j = 0; j < i; j++) {  //首先打印空格
					printf(" ");
				}
				for (int k = 0, t = i + 65; k < n - i + 1; t++, k++) {  //在打印前半部分的字母
					printf("%c", t);
				}
				for (int m = 0, ii = 64 + n; m < n - i; m++, ii--) {  //最后打印这一行的后半部分的字母
					printf("%c", ii);
				}
			}
			else if (i >= n + 1) {   //沙漏的下半部分，下面三个for循环的作用与上面是一样的
				for (int j = 0; j < n * 2 - i; j++) {
					printf(" ");
				}
				for (int k = 0, t = 65 + 2 * n - i; k < i - n + 1; k++, t++) {
					printf("%c", t);
				}
				for (int m = 0, jj = 64 + n; m < i - n; m++, jj--) {
					printf("%c", jj);
				}
			}
			printf("\n");
		}
		n = 0;
	}
	return 0;
}