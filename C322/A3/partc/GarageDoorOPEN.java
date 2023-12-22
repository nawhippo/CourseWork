package C322.homework3.partc;

public class GarageDoorOPEN implements Command{
    private GarageDoor controlledGarageDoor;

    public GarageDoorOPEN(GarageDoor controlledGarageDoor){
            this.controlledGarageDoor = controlledGarageDoor;
    }
    @Override
    public void execute() {controlledGarageDoor.up();}
}
