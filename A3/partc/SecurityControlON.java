package C322.homework3.partc;

public class SecurityControlON implements Command {
    SecurityControl securityControl;
    @Override
    public void execute() {
        securityControl.arm();
    }
}
