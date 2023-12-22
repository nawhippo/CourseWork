package C322.homework3.partc;

public class FanHIGH implements Command{
    private Fan controlledfan;

    public FanHIGH(Fan controlledfan){this.controlledfan = controlledfan;}

    @Override
    public void execute() {controlledfan.high();}
}
