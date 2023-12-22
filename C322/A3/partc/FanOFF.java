package C322.homework3.partc;

public class FanOFF implements Command{
    private Fan controlledfan;

    public FanOFF(Fan controlledfan){this.controlledfan = controlledfan;}

    @Override
    public void execute() {controlledfan.turnOff();}
}
