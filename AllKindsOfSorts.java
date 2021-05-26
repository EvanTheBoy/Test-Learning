package com.hw.sorts0512;

public class AllKindsOfSorts {
	private int pivot,index;
	private int gap;
	private boolean change,flag;
	
	public void bubbleSort(int[] arr){  //ð������
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
	
	private int partition(int[] arr,int low,int high)  //��������ָ��
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
	
	public void quickSort(int[] arr,int low,int high)  //��������
	{
		if(low < high){
			index = partition(arr,low,high);
			quickSort(arr,low,index-1);
			quickSort(arr,index+1,high);
		}
	}
	
	public void insertSort(int[] arr){  //��������
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
	
	public void shellSort(int[] arr){  //ϣ������
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
	
	public void mergeSort(int[] arr){  //�鲢����
		int[] temp = new int[arr.length];
		divide(arr,0,arr.length-1,temp);
	}
	
	private void divide(int[] arr,int left,int right,int[] temp){
		if(left < right){  //�ݹ��������
			int mid = (left + right) / 2;  //ȡarr������м�ֵ
			divide(arr,left,mid,temp);
			divide(arr,mid+1,right,temp);
			merge(arr,left,mid,right,temp);
		}
	}
	
	private void merge(int[] arr,int left,int mid,int right,int[] temp){  //�ѷָ����һ��һ���ϲ�
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
	
	public void selectSort(int[] arr){  //ѡ������
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
	
	private void createHeap(int[] arr,int i,int length){  //������
		int temp = arr[i];  //A
		for(int k = i*2 + 1;k<length;k=k*2+1){  //�ӵ�ǰ����Ҷ�ӽ�㿪ʼ
			if(k+1<length && arr[k]<arr[k+1]){  //��һ�����ҳ���ǰ�������Һ��ӽ���бȽϴ����һ��
				k++;
			}
			
			if(arr[k] > temp){   //���ӱȸ��״󣬾͵ý���
				arr[i] = arr[k];  //B
				i = k;  //C  //��һ���������������ģ��������У�һ�¾Ͷ���
			}else{
				break;
			}
		}
		arr[i] = temp;  //D
	}
	 //����A,B,C,D�Ĳ����ǽ�������Ԫ�صĹ���
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
