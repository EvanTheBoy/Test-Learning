package com.hw.sorts0512;

import java.util.Scanner;

public class QuickSort {
	private void run()
	{
		int length;
		int[] data = null;
		Scanner s = new Scanner(System.in);
		AllKindsOfSorts q = new AllKindsOfSorts();
		System.out.println("���������鳤�ȣ�");
		length = s.nextInt();
		data = new int[length];
		System.out.println("�������������������ݣ�");
		for(int i = 0;i < length;i++){
			data[i] = s.nextInt();
		}
		q.quickSort(data, 0, length-1);
		System.out.println("���ÿ���������������:");
		for(int i = 0;i < length;i++){
			System.out.print(data[i]+" ");
		}
	}
	
	public static void main(String[] args){
		QuickSort solution = new QuickSort();
		solution.run();
	}
}


