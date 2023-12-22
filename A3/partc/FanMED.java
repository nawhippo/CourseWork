package C322.homework3.partc;

public class FanMED implements Command{
    private Fan controlledfan;

    public FanMED(Fan controlledfan){this.controlledfan = controlledfan;}

    @Override
    public void execute() {controlledfan.medium();}
}
