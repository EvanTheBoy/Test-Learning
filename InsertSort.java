package com.hw.sorts0512;

import java.util.Scanner;

public class InsertSort {
	private void run(){
		int len;
		int[] data = null;
		AllKindsOfSorts iss = new AllKindsOfSorts();
		Scanner s = new Scanner(System.in);
		System.out.println("���������鳤�ȣ�");
		len = s.nextInt();
		data = new int[len];
		System.out.println("�����������е�Ԫ�أ�");
		for(int i = 0;i < len;i++){
			data[i] = s.nextInt();
		}
		iss.insertSort(data);
		System.out.println("���ò��������������ǣ�");
		for(int i = 0;i < len;i++){
			System.out.print(data[i]+" ");
		}
	}
	
	public static void main(String[] args){
		InsertSort isd = new InsertSort();
		isd.run();
	}
}
