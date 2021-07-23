package com.hw.list0710;

public class Rob {
    private static int getBest(int[] data, int index) {  //用递归的方式
        if(data == null || index < 0){
            return 0;
        }
        if(index == 0){
            return 1;
        }
        data[index] = Math.max(getBest(data, index-1),getBest(data, index-2)+data[index]);
        return data[index];
    }

    //拥有最优子结构
    private static int maxMoney(int[] data){  //用迭代的方式
        int len = data.length;
        int[] dp = new int[len];  //这个数组里面存最优解
        if(len == 0 || data == null){
            return 0;
        }else if(len == 1){
            return data[0];
        }
        dp[0] = data[0];
        dp[1] = Math.max(data[0], data[1]);
        for(int i = 2; i < len; ++i) {
            dp[i] = Math.max(dp[i-1], dp[i-2]+data[i]);
        }
        return dp[len-1];
    }

    //可以降低算法的空间复杂度
    private static int betterMaxMoney(int[] data) {
        int len = data.length;
        if(data == null || len == 0) {
            return 0;
        }else if(len == 1){
            return data[0];
        }
        int first = data[0];
        int second = Math.max(data[0], data[1]);
        for(int i = 2; i < len; ++i) {
            int temp = second;
            second = Math.max(second, first+data[i]);
            first = temp;
        }
        return second;
    }

    //房屋之间圆形分布
    private static int moreMoney(int[] data, int start, int end) {
        int length = data.length;
        if(data == null || length == 0){
            return 0;
        }else if(length == 1){
            return 1;
        }
        int first = data[start];
        int second = Math.max(data[start], data[start+1]);
        for(int i = start+2; i <= end; ++i) {
            int temp = second;
            second = Math.max(data[i]+first, second);
            first = temp;
        }
        return second;
    }

    public static void main(String[] args) {
        int[] val = new int[]{2,7,9,3,1};
        System.out.println(Math.max(moreMoney(val, 0, val.length-2), moreMoney(val, 1, val.length-1)));
        int res3 = betterMaxMoney(val);
        System.out.println(res3);
        int res2 = maxMoney(val);
        System.out.println(res2);
        int res1 = getBest(val, val.length-1);
        System.out.println(res1);
    }
}
