package com.hw.sorts0512;

public class AllKindsOfSorts {
	private int pivot,index;
	private int gap;
	private boolean change,flag;
	
	public void bubbleSort(int[] arr){  //冒泡排序
		for(int i = arr.length - 1;i>=0;i--){
			flag = false;
			for(int j = 0;j < i;j++){
				if(arr[j] > arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					flag = true;
				}
			}
			if(flag == false){
				break;
			}
		}
	}
	
	private int partition(int[] arr,int low,int high)  //快速排序分割方法
	{
		pivot = arr[low];
		while(low < high)
		{
			while(low<high && pivot<=arr[high])
			{
				high--;
			}
			arr[low] = arr[high];
			
			while(low<high && pivot>=arr[low])
			{
				low++;
			}
			arr[high] = arr[low];
		}
		arr[low] = pivot;
		return low;
	}
	
	public void quickSort(int[] arr,int low,int high)  //快速排序
	{
		if(low < high){
			index = partition(arr,low,high);
			quickSort(arr,low,index-1);
			quickSort(arr,index+1,high);
		}
	}
	
	public void insertSort(int[] arr){  //插入排序
		for(int i = 1;i < arr.length;i++){
			int j = i;
			while(j > 0 && arr[j] < arr[j-1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
			}
		}
	}
	
	public void shellSort(int[] arr){  //希尔排序
		for(gap = arr.length/2;gap > 0;gap /= 2){
			for(int i = gap;i < arr.length;i++){
				int j = i;
				while(j-gap >= 0 && arr[j] < arr[j-gap])
				{
					int temp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = temp;
					j -= gap;
				}
			}
		}
	}
	
	public void mergeSort(int[] arr){  //归并排序
		int[] temp = new int[arr.length];
		divide(arr,0,arr.length-1,temp);
	}
	
	private void divide(int[] arr,int left,int right,int[] temp){
		if(left < right){  //递归结束条件
			int mid = (left + right) / 2;  //取arr数组的中间值
			divide(arr,left,mid,temp);
			divide(arr,mid+1,right,temp);
			merge(arr,left,mid,right,temp);
		}
	}
	
	private void merge(int[] arr,int left,int mid,int right,int[] temp){  //把分割的数一个一个合并
		int pLeft = left,pRight = mid+1,pTemp = 0;
		while(pLeft<=mid && pRight<=right)
		{
			if(arr[pLeft] <= arr[pRight]){
				temp[pTemp++] = arr[pLeft++];
			}else{
				temp[pTemp++] = arr[pRight++];
			}
		}
		while(pLeft <= mid)
		{
			temp[pTemp++] = arr[pLeft++];
		}
		while(pRight <= right)
		{
			temp[pTemp++] = arr[pRight++];
		}
		
		pTemp = 0;
		while(left <= right)
		{
			arr[left++] = temp[pTemp++];
		}
	}
	
	public void selectSort(int[] arr){  //选择排序
		for(int i = 0;i < arr.length - 1;i++){
			int index = i;
			for(int j = i + 1;j < arr.length;j++){
				if(arr[j] < arr[index]){
					index = j;
					change = true;
				}
			}
			if(change == true){
				int temp = arr[index];
				arr[index] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	private void createHeap(int[] arr,int i,int length){  //堆排序
		int temp = arr[i];  //A
		for(int k = i*2 + 1;k<length;k=k*2+1){  //从当前结点的叶子结点开始
			if(k+1<length && arr[k]<arr[k+1]){  //这一步是找出当前结点的左右孩子结点中比较大的那一个
				k++;
			}
			
			if(arr[k] > temp){   //孩子比父亲大，就得交换
				arr[i] = arr[k];  //B
				i = k;  //C  //这一步交换如果看不懂模拟程序运行，一下就懂了
			}else{
				break;
			}
		}
		arr[i] = temp;  //D
	}
	 //以上A,B,C,D四步就是交换两个元素的过程
	private void swap(int[] arr,int a,int b){
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	
	public void heapSort(int[] arr){
		for(int i = arr.length/2-1;i>=0;i--){
			createHeap(arr,i,arr.length);
		}
		
		for(int j = arr.length-1;j>0;j--){
			swap(arr,0,j);
			createHeap(arr,0,j);
		}
	}
}
