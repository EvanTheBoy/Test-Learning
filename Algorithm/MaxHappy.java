package com.hw.algorithm;

import java.util.ArrayList;

public class MaxHappy {
    private static class Employee {
        public int happy;
        //员工的所有直接下属员工，若员工为基层员工，则该列表为空
        public ArrayList<Employee> subordinates;
        public Employee(int happy) {
            this.happy = happy;
            subordinates = new ArrayList<>();
        }
    }

    private static class Info {
        public int comeMaxHappy; //来的最大快乐值
        public int goMaxHappy; //不来的最大快乐值

        public Info(int comeMaxHappy, int goMaxHappy) {
            this.comeMaxHappy = comeMaxHappy;
            this.goMaxHappy = goMaxHappy;
        }
    }

    private static Info process(Employee node) {
        if (node.subordinates.isEmpty()) {
            return new Info(node.happy, 0);
        }
        int come = node.happy; //该员工来的情况下，整棵树的最大收益
        int go = 0; //该员工不来的情况下，整棵树的最大收益
        for (Employee next : node.subordinates) {
            Info nextInfo = process(next);
            go += Math.max(nextInfo.comeMaxHappy, nextInfo.goMaxHappy);
            come += nextInfo.goMaxHappy;
        }
        return new Info(come, go);
    }

    public static int maxHappy(Employee boss) {
        Info headInfo = process(boss);
        return Math.max(headInfo.comeMaxHappy, headInfo.goMaxHappy);
    }

    public static void main(String[] args) {
        Employee employee46 = new Employee(46);
        Employee employee12 = new Employee(12);
        Employee employee30 = new Employee(30);
        Employee employee1 = new Employee(1);
        Employee employee3 = new Employee(3);
        Employee employee7 = new Employee(7);
        Employee employee90 = new Employee(90);
        Employee employee40 = new Employee(40);
        Employee employee25 = new Employee(25);
        Employee employee8 = new Employee(8);
        employee8.subordinates.add(employee25);
        employee8.subordinates.add(employee40);
        employee40.subordinates.add(employee1);
        employee40.subordinates.add(employee3);
        employee40.subordinates.add(employee7);
        employee25.subordinates.add(employee90);
        employee7.subordinates.add(employee12);
        employee7.subordinates.add(employee30);
        employee1.subordinates.add(employee46);
        int maxHappyValue = maxHappy(employee8);
        System.out.println(maxHappyValue);
    }
}
