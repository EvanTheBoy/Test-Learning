#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
int citiesConnected[100][100];
queue<int>q;
void dfs(int i, int visited[], int demo[][100], int len)
{
	for (int j = 0; j < len; ++j) {
		if (demo[i][j] == 1 && visited[j] == 0) {
			visited[j] = 1;
			dfs(j, visited, demo, len);
		}
	}
}

void bfs(int i, int visited[], int demo[][100], int len)
{
	q.push(i);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		visited[temp] = 1;
		for (int j = 0; j < len; ++j) {
			if (demo[i][j] == 1 && visited[j] == 0) {
				q.push(j);
			}
		}
	}
}

int getProvincesByDepth(int demo[][100], int len)
{
	int visited[100] = { 0 };  //全部初始化为0，表示都没有被访问过
	int provinces = 0;
	for (int i = 0; i < len; ++i) {
		if (visited[i] == 0) {
			dfs(i, visited, demo, len);
			++provinces;
		}
	}
	return provinces;
}

int getProvincesByWidth(int demo[][100], int len)
{
	int visited[100] = { 0 };
	int provinces = 0;
	for (int i = 0; i < len; ++i) {
		if (visited[i] == 0) {
			bfs(i, visited, demo, len);
			++provinces;
		}
	}
	return provinces;
}

int main()
{
	printf("输入长度:");
	int len;
	scanf("%d", &len);
	printf("输入数据:\n");
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			cin >> citiesConnected[i][j];
		}
	}
	int res1 = getProvincesByDepth(citiesConnected, len);
	printf("通过深度优先:共有%d个省份.\n", res1);
	int res2 = getProvincesByWidth(citiesConnected, len);
	printf("通过广度优先:共有%d个省份.\n", res2);
	return 0;
}