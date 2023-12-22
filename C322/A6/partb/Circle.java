package C322.homework6.partb;

import java.awt.*;

public class Circle extends Dot{
    int radius;
    public Circle(int x, int y,int radius, Color color) {
        super(x, y);
        radius = radius;
    }

    @Override
    public void draw(Graphics graphics) {
        System.out.println("Drawing a circle at " + x + " " + " " + y + " with radius " + radius);
    }
    public void move(int x, int y){
        super.move(x,y);
    }
}
