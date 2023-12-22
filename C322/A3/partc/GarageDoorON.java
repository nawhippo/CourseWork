package C322.homework3.partc;

public class GarageDoorON implements Command{
    private GarageDoor controlledGarageDoor;

    public GarageDoorON(GarageDoor controlledGarageDoor){
            this.controlledGarageDoor = controlledGarageDoor;
    }
    @Override
    public void execute() {controlledGarageDoor.lightOn();}
}
