package C322.homework3.partc;

public class SprinklerOFF implements Command{
    Sprinkler sprinkler;
    @Override
    public void execute() {
        sprinkler.waterOff();
    }
}
