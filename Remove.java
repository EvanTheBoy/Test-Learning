package com.hw.list0710;

import java.util.Scanner;

public class Remove {
    private static int removeDuplicates(int[] arr){
        if(arr.length == 0){
            return 0;
        }
        int i = 0; //定义一个慢指针
        for(int j = 1;j < arr.length;++j){
            //如果相等就让j往后移，这没影响，所以j是一个快指针
            if(arr[i] != arr[j]){
                arr[++i] = arr[j];  //如果不相等，把j位置的元素赋给i的下一位
            }
        }
        return i+1;
    }

    public static void main(String[] args) {
        int[] nums = null;
        Scanner s = new Scanner(System.in);
        System.out.println("数组长度:");
        int len = s.nextInt();
        nums = new int[len];
        System.out.println("请按照从小到大的顺序输入数据:");
        for(int i = 0;i < len;i++){
            nums[i] = s.nextInt();
        }
        s.close();
        int length = removeDuplicates(nums);
        System.out.println("去重后的数组长度是:"+length);
    }
}