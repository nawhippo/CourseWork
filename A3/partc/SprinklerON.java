package C322.homework3.partc;

public class SprinklerON implements Command{
    Sprinkler sprinkler;
    @Override
    public void execute() {
        sprinkler.waterOn();
    }
}
