package com.hw.sorts0512;

import java.util.Scanner;

public class ShellSort {
	public void run(){
		int length;
		int[] data = null;
		Scanner s = new Scanner(System.in);
		AllKindsOfSorts shell = new AllKindsOfSorts();
		System.out.println("���������鳤�ȣ�");
		length = s.nextInt();
		data = new int[length];
		System.out.println("�������������������ݣ�");
		for(int i = 0;i < length;i++){
			data[i] = s.nextInt();
		}
		shell.shellSort(data);
		for(int i = 0;i < length;i++){
			System.out.print(data[i]+" ");
		}
	}
	
	public static void main(String[] args){
		ShellSort sst = new ShellSort();
		sst.run();
	}
}
