package com.hw.sorts0512;

import java.util.Scanner;

public class BubbleSort {
	private void run(){
		int len;
		int[] data = null;
		AllKindsOfSorts th = new AllKindsOfSorts();
		Scanner s = new Scanner(System.in);
		System.out.println("���������鳤�ȣ�");
		len = s.nextInt();
		data = new int[len];
		System.out.println("�����������е�Ԫ�أ�");
		for(int i = 0;i < len;i++){
			data[i] = s.nextInt();
		}
		th.bubbleSort(data);
		System.out.println("����ð�������������ǣ�");
		for(int i = 0;i < len;i++){
			System.out.print(data[i]+" ");
		}
	}
	
	public static void main(String[] args){
		BubbleSort bs = new BubbleSort();
		bs.run();
	}
}
