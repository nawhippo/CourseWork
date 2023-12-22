package C322.homework6.partb;

import java.awt.*;

public class ImageEditor {
    private CompoundGraphic allshapes;
    public ImageEditor(){
        allshapes = new CompoundGraphic();
    }
    public void addShape(Graphic graphic){
        allshapes.addChild(graphic);
    }
    public void removeShape(Graphic graphic){
        allshapes.removeChild(graphic);
    }

    public void draw(Graphics graphics){
        allshapes.draw(graphics);
    }
}
