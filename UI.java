package com.hw.image0708;
import javax.swing.*;
import java.awt.*;

public class UI {
    public static void main(String[] args) {
        UI ui = new UI();
        ui.showUI();
    }

    private void showUI(){
        JFrame jf = new JFrame();
        jf.setSize(700,700);
        jf.setTitle("图像处理工作室");
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setLayout(new FlowLayout());
        jf.setLocationRelativeTo(null);
        DrawMouse mouse = new DrawMouse();
        String[] function = {"绘制原图","马赛克","油画","灰度化","轮廓检测","图像融合"};
        for(String i : function){
            JButton button = new JButton(i);
            jf.add(button);
            button.addActionListener(mouse);
        }
        jf.addMouseListener(mouse);
        jf.setVisible(true);
        Graphics g = jf.getGraphics();
        mouse.g = g;
    }
}