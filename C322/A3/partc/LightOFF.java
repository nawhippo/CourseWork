package C322.homework3.partc;

public class LightOFF implements Command{
    private Light controlledlight;

    public LightOFF(Light controlledlight){
            this.controlledlight = controlledlight;
    }
    @Override
    public void execute() {
        controlledlight.turnOff();
    }
}
