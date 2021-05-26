package com.hw.sorts0512;

import java.util.Scanner;

public class QuickSort {
	private void run()
	{
		int length;
		int[] data = null;
		Scanner s = new Scanner(System.in);
		AllKindsOfSorts q = new AllKindsOfSorts();
		System.out.println("请输入数组长度：");
		length = s.nextInt();
		data = new int[length];
		System.out.println("请输入待排序的所有数据：");
		for(int i = 0;i < length;i++){
			data[i] = s.nextInt();
		}
		q.quickSort(data, 0, length-1);
		System.out.println("采用快速排序后的数组是:");
		for(int i = 0;i < length;i++){
			System.out.print(data[i]+" ");
		}
	}
	
	public static void main(String[] args){
		QuickSort solution = new QuickSort();
		solution.run();
	}
}


