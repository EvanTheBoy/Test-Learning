package com.hw.image0708;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Random;

public class PixelMouse{
    private String path = "F:\\魔法世界.jpg";
    private String anotherPath = "F:\\盖亚.png";

    private int[][] getImagePixel(String path){
        File file = new File(path);
        BufferedImage buffImage = null;
        try {
            buffImage = ImageIO.read(file);
        } catch (IOException e) {
            e.printStackTrace();
        }

        int width = buffImage.getWidth();
        int height = buffImage.getHeight();
        int[][] arrpixel = new int[width][height];
        for(int i = 0;i < width;i++){
            for(int j = 0;j < height;j++){
                int pixel = buffImage.getRGB(i,j);
                arrpixel[i][j] = pixel;
            }
        }
        return arrpixel;
    }

    /**
     * 绘制原图
     */
    public void drawImage(Graphics gr){
        int[][] arrpixel = getImagePixel(path);
        for(int i = 0;i < arrpixel.length;++i){
            for(int j = 0;j < arrpixel[i].length;++j){
                int rgbValue = arrpixel[i][j];
                Color color = new Color(rgbValue);
                gr.setColor(color);
                gr.fillRect(45+i,150+j,1,1);
            }
        }
    }

    /**
     * 绘制原图的马赛克效果
     */
    public void getImageMosaic(Graphics gr){
        int[][] arrpixel = getImagePixel(path);
        for(int i = 0;i < arrpixel.length;i += 10){
            for(int j = 0;j < arrpixel[i].length;j += 10){
                int rgbValue = arrpixel[i][j];
                Color color = new Color(rgbValue);
                gr.setColor(color);
                gr.fillRect(45+i,150+j,10,10);
            }
        }
    }

    /**
     * 绘制原图的油画效果
     */
    public void oilPaintImage(Graphics gr){
        Random rand = new Random();
        int[][] arrpixel = getImagePixel(path);
        for(int i = 0;i < arrpixel.length;i += 3){
            for(int j = 0;j < arrpixel[i].length;j += 3){
                int rgbValue = arrpixel[i][j];
                int size = rand.nextInt(5)+5;
                Color color = new Color(rgbValue);
                gr.setColor(color);
                gr.fillOval(45+i,150+j,size,size);
            }
        }
    }

    /**
     * 绘制原图的灰度图
     */
    public void getImageGrayScale(Graphics gr){
        int[][] arrpixel = getImagePixel(path);
        for(int i = 0;i < arrpixel.length;++i){
            for(int j = 0;j < arrpixel[i].length;++j){
                int rgbValue = arrpixel[i][j];
                Color color = new Color(rgbValue);
                int red = color.getRed();
                int green = color.getGreen();
                int blue = color.getBlue();
                int average = (red + green + blue) / 3;
                Color col = new Color(average,average,average);
                gr.setColor(col);
                gr.fillRect(45+i,150+j,1,1);
            }
        }
    }

    /**
     * 实现图片的轮廓检测
     * @param gr
     */
    public void testContour(Graphics gr){
        int[][] arrpixel = getImagePixel(path);
        for(int i = 0;i < arrpixel.length - 1;++i){
            for(int j = 0;j < arrpixel[i].length - 2;++j){
                int rgbValue = arrpixel[i][j];
                Color color = new Color(rgbValue);
                int red = color.getRed();
                int green = color.getGreen();
                int blue = color.getBlue();
                int gray = (red + green + blue) / 3;

                int rgbValueNext = arrpixel[i+1][j+2];
                int redNext = (rgbValueNext >> 16) & 0xFF;
                int greenNext = (rgbValueNext >> 8) & 0xFF;
                int blueNext = (rgbValueNext >> 0) & 0xFF;
                int grayNext = (redNext + greenNext + blueNext) / 3;

                if(Math.abs(gray-grayNext) >20){
                    gr.setColor(Color.BLACK);
                }else{
                    gr.setColor(Color.WHITE);
                }
                gr.fillRect(45+i,150+j,1,1);
            }
        }
    }

    /**
     * 融合两张图片
     * @param gr
     */
    public void combiningImages(Graphics gr){
        int[][] first = getImagePixel(path);
        int[][] second = getImagePixel(anotherPath);
        for(int i = 0,k = 0;i < first.length && k < second.length;++i,++k){
            for(int j = 0,t = 0;j < first[i].length && t < second[k].length;++j,++t){
                int rgb1 = first[i][j];
                int rgb2 = second[k][t];
                Color color = new Color(rgb1);
                Color col = new Color(rgb2);
                int red1 = color.getRed();
                int green1 = color.getGreen();
                int blue1 = color.getGreen();
                int red2 = col.getRed();
                int green2 = col.getGreen();
                int blue2 = col.getBlue();
                if(i < second.length && j < second[i].length){
                    Color res = new Color((int)(red1*0.5+red2*0.5),(int)(green1*0.5+green2*0.5),(int)(blue1*0.5+blue2*0.5));
                    gr.setColor(res);
                    gr.fillRect(45+i,150+j,1,1);
                }else if(i >= second.length || j >= second[i].length){
                    System.out.println("只画魔法世界");
                    Color res = new Color((int)(red1*0.5),(int)(green1*0.5),(int)(blue1*0.5));
                    gr.setColor(res);
                    gr.fillRect(45+i,150+j,1,1);
                }
            }
        }
    }
}