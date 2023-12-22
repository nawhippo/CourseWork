package C322.homework3.partc;

public class GarageDoorCLOSE implements Command{
    private GarageDoor controlledGarageDoor;

    public GarageDoorCLOSE(GarageDoor controlledGarageDoor){
            this.controlledGarageDoor = controlledGarageDoor;
    }


    @Override
    public void execute() {controlledGarageDoor.down();}
}
