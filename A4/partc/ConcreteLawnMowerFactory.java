package C322.homework4.partc;

public class ConcreteLawnMowerFactory extends LawnMowerFactory{
    @Override
    public LawnMower getLawnMowerType(String lawnmowertype) {
        if(lawnmowertype.equals("Riding")){
            return new RidingMower();
        }else if(lawnmowertype.equals("Push")){
            return new PushMower();
        }
        return null;
    }
}
