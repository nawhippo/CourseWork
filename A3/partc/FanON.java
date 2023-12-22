package C322.homework3.partc;

public class FanON implements Command{
    private Fan controlledfan;

    public FanON(Fan controlledfan){
        this.controlledfan = controlledfan;
    }
    @Override
    public void execute() {
        controlledfan.turnOn();
    }
}
