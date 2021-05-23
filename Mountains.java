package Practice;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.util.Random;
import javax.swing.JFrame;

public class Mountains{

	public static void main(String[] args) {
		Mountains m = new Mountains();
		m.show();
	}
	
	public void show(){
		Board board = new Board();
		board.setTitle("绘制山脉");
		board.setSize(1200,800);
		board.setLocationRelativeTo(null);
		board.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		board.setVisible(true);
		try {
			Thread.sleep(100);  //画图板也是绘制的，这里是为了等画图板全部绘制完成后再画山脉
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Graphics g = board.getGraphics();
		Color c1 = new Color(12,62,88);
		Color c2 = new Color(14,70,101);
		Color c3 = new Color(7,38,54);
		g.setColor(new Color(109,191,235));
		g.fillRect(0, 0, 1200, 800);
		g.drawArc(100,40,90,50,0,180);  //这里画个太阳
		g.setColor(Color.yellow); g.fillArc(100,100,40,40,0,-360);
		drawMountains(0, 580, 1200, 580, 2,10,g,c3);
		drawMountains(0, 580, 1200, 580, 2,10,g,c2);
		drawMountains(0, 580, 1200, 580, 2,10,g,c1);
	}
	
	public void drawMountains(int x1,int y1,int x2,int y2,double k,int times,Graphics g,Color c){
		Random rand = new Random();
		int range=0;
		if(times > 0){
			range = (int)((rand.nextInt(400)-200)*k);  //纵坐标取值的范围
			k*=0.5;   //缩小的比例
			int middleX = (x1+x2)/2; //中点横坐标
			int middleY = (y1+y2)/2 + range;  //中点纵坐标
			drawMountains(x1,y1,middleX,middleY,k,times-1,g,c);  //这里开始就是递归
			drawMountains(middleX,middleY,x2,y2,k,times-1,g,c);
		}else{
			g.drawLine(x1,y1,x2,y2);  //递归结束，画直线
			g.setColor(c);  //同时设置颜色
			Polygon p1 = new Polygon();  //使用这个类来填充颜色
			p1.addPoint(x1, 800);	
			p1.addPoint(x1, y1);
			p1.addPoint(x2, y2);
			p1.addPoint(x2, 800);
			Graphics2D g2 = (Graphics2D)g;
			g2.fillPolygon(p1);
		}
	}
}
