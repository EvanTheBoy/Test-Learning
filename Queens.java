package com.hw.list0710;

import java.util.Scanner;

public class Queens {
    private int[][] attack = new int[10][10];
    private char[][] queen = new char[10][10];
    public static int count;
    /**
     * 拷贝数组，用来备份
     * @param arr
     * @param val
     * @param n
     */
    private void copy(int[][] arr, int[][] val, int n){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                arr[i][j] = val[i][j];
            }
        }
    }

    /**
     * 打印放置了皇后的棋盘
     * @param n
     */
    private void print(int n){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                System.out.print(queen[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * 设置皇后的攻击方向
     * @param x
     * @param y
     * @param n
     */
    private void updataAttack(int x, int y, int n){  
        int[] dx = {-1, -1, -1, 0, 1, 1, 1, 0};  //行方向
        int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};  //列方向
        attack[x][y] = 1;
        for(int i = 1;i < n;++i){
            for(int j = 0;j < 8;++j){
                int nx = x + i * dx[j];
                int ny = y + i * dy[j];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    attack[nx][ny] = 1;
                }
            }
        }
    }

    /**
     * 初始化棋盘
     * @param n
     */
    public void init(int n){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                attack[i][j] = 0;
                queen[i][j] = '.';
            }
        }
    }

    /**
     * 放置皇后的核心代码
     * @param k
     * @param n
     */
    public void dfs(int k, int n){
        if(k == n){
            print(n);
            count++;
            return;
        }
        for(int i = 0;i < n;++i){  //这个for循环可以保证程序尝试各种可能的摆法
            if(attack[k][i] == 0){
                int[][] temp = new int[10][10];
                copy(temp, attack, n); //先备份
                queen[k][i] = 'Q'; //在这个位置放置皇后
                updataAttack(k, i, n); // 因为上一步放置了皇后，所以需要更新attack数组
                dfs(k + 1, n); //递归下一行，继续放置皇后
                copy(attack, temp, n); //递归完成后，需要回溯，因此需要回到原来的状态
                queen[k][i] = '.';
            }
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Queens queen = new Queens();
        count = 0;
        int n = s.nextInt();
        s.close();
        queen.init(n);
        queen.dfs(0, n);
        System.out.println("摆法共有:"+count+"种");
    }
}
