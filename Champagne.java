package com.hw.list0710;

import java.util.Scanner;

public class Champagne {
    private static double getNum(int poured, int row, int col) {
        double[][] storage = new double[100][100];
        storage[0][0] = poured;  //初始倒了几杯酒
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j <= i; ++j) {
                double d = (storage[i][j] - 1.0) / 2;  //当前杯子。大于0即溢出了，否则还没满
                if(d > 0){  //所以这里只考虑溢出的情况
                    storage[i+1][j] += d;
                    storage[i+1][j+1] += d;
                }
            }
        }
        return Math.min(1, storage[row][col]);//大于1那就是1了，因为大于1就满了，满了就要往下溢出
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("输入已倒杯数:");
        int poured = s.nextInt();
        System.out.println("输入查找的行:");
        int row = s.nextInt();
        System.out.println("输入查找的列:");
        int col = s.nextInt();
        s.close();
        double res = getNum(poured, row-1, col-1);
        System.out.println(res);
    }
}
