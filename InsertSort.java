package com.hw.sorts0512;

import java.util.Scanner;

public class InsertSort {
	private void run(){
		int len;
		int[] data = null;
		AllKindsOfSorts iss = new AllKindsOfSorts();
		Scanner s = new Scanner(System.in);
		System.out.println("请输入数组长度：");
		len = s.nextInt();
		data = new int[len];
		System.out.println("请输入数组中的元素：");
		for(int i = 0;i < len;i++){
			data[i] = s.nextInt();
		}
		iss.insertSort(data);
		System.out.println("采用插入排序后的数组是：");
		for(int i = 0;i < len;i++){
			System.out.print(data[i]+" ");
		}
	}
	
	public static void main(String[] args){
		InsertSort isd = new InsertSort();
		isd.run();
	}
}
