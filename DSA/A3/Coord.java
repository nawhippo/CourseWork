public class Coord{
    private int x,y;

    public Coord(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX(){
        return this.x;
    }

    public int getY(){
        return this.y;
    }

    public String toString(){
        return this.x + " " + this.y;
    }

    // TODO: This should be straightforward. This is a softball
    public boolean equals(Object o){
        if(o instanceof Coord){
            Coord coord = (Coord) o;
            if(coord.getX() == this.getX() && coord.getY() == this.getY()){
                return true;
            }
        }
        return false;
    }
}
