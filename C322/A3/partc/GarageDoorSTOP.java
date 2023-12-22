package C322.homework3.partc;

public class GarageDoorSTOP implements Command{
    private GarageDoor controlledGarageDoor;

    public GarageDoorSTOP(GarageDoor controlledGarageDoor){
            this.controlledGarageDoor = controlledGarageDoor;
    }
    @Override
    public void execute() {controlledGarageDoor.stop();}
}
