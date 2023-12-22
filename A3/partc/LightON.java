package C322.homework3.partc;

public class LightON implements Command{
    private Light controlledlight;

    public LightON(Light controlledlight){
            this.controlledlight = controlledlight;
    }
    @Override
    public void execute() {
        controlledlight.turnOn();
    }
}
