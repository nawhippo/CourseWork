package C322.homework3.partc;

public class FanLOW implements Command{
    private Fan controlledfan;

    public FanLOW(Fan controlledfan){this.controlledfan = controlledfan;}

    @Override
    public void execute() {controlledfan.low();}
}
