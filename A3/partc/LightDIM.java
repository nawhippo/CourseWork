package C322.homework3.partc;

public class LightDIM implements Command{
    private Light controlledlight;

    public LightDIM(Light controlledlight){
            this.controlledlight = controlledlight;
    }
    @Override
    public void execute() {
        controlledlight.dim();
    }
}
