package C322.homework6.partb;

import java.awt.*;

public class Dot implements Graphic{
    int x;
    int y;

    public Dot(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public void move(int x, int y) {
    this.x = x;
    this.y = y;
    }

    @Override
    public void draw(Graphics graphics) {
        System.out.println("Drawing a dot at " + x + " " + " " + y);
    }

}
