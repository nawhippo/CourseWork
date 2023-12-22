package C322.homework6.partb;

import java.awt.*;

public class CompoundGraphic implements Graphic{
    Graphic[] children;
    int pos = 0;

    void addChild(Graphic child){
        for (int i = 0; i < children.length; i++) {
            if (children[i] == null) {
                //set that index to null
                children[i] = child;
                return;
            }
        }
        children[pos] = child;
        pos++;
            }

    void removeChild(Graphic child){
        for (int i = 0; i < children.length; i++){
            if(children[i] == child){
                //set that index to null
                children[i] = null;
                return;
            }
        }
    }
    @Override
    public void move(int x, int y) {
    for (Graphic shape : children){
        shape.move(x,y);
    }
    }

    @Override
    public void draw(Graphics graphics) {
    for (Graphic shape : children){
        shape.draw(graphics);
    }
    }
}
