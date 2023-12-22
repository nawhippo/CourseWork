package C322.homework3.partc;

public class GarageDoorOFF implements Command{
    private GarageDoor controlledGarageDoor;

    public GarageDoorOFF(GarageDoor controlledGarageDoor){
            this.controlledGarageDoor = controlledGarageDoor;
    }
    @Override
    public void execute() {controlledGarageDoor.lightOff();}
}
