package com.hw.sorts0512;
import java.util.Scanner;

public class SelectSort {
	public void run(){
		int length;
		int[] data = null;
		Scanner s = new Scanner(System.in);
		AllKindsOfSorts s2 = new AllKindsOfSorts();
		System.out.println("���������鳤�ȣ�");
		length = s.nextInt();
		data = new int[length];
		System.out.println("�������������������ݣ�");
		for(int i = 0;i < length;i++){
			data[i] = s.nextInt();
		}
		s2.selectSort(data);
		for(int i = 0;i < length;i++){
			System.out.print(data[i]+" ");
		}
	}
	
	public static void main(String[] args){
		SelectSort ss = new SelectSort();
		ss.run();
	}
}
