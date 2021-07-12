package com.hw.image0708;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;


public class DrawMouse implements MouseListener, ActionListener {
    public Graphics g;
    public String name;
    PixelMouse pixel = new PixelMouse();

    @Override
    public void actionPerformed(ActionEvent e) {
        name = e.getActionCommand();
        if(name.equals("绘制原图")){
            pixel.drawImage(g);
        }else if(name.equals("马赛克")){
            pixel.getImageMosaic(g);
        }else if(name.equals("油画")){
            pixel.oilPaintImage(g);
        }else if(name.equals("灰度化")){
            pixel.getImageGrayScale(g);
        }else if(name.equals("轮廓检测")){
            pixel.testContour(g);
        }else if(name.equals("图像融合")){
            pixel.combiningImages(g);
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}