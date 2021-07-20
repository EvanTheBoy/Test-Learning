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
	int visited[100] = { 0 };  //ȫ����ʼ��Ϊ0����ʾ��û�б����ʹ�
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
	printf("���볤��:");
	int len;
	scanf("%d", &len);
	printf("��������:\n");
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			cin >> citiesConnected[i][j];
		}
	}
	int res1 = getProvincesByDepth(citiesConnected, len);
	printf("ͨ���������:����%d��ʡ��.\n", res1);
	int res2 = getProvincesByWidth(citiesConnected, len);
	printf("ͨ���������:����%d��ʡ��.\n", res2);
	return 0;
}