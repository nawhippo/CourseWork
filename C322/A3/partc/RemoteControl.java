package C322.homework3.partc;

import javax.crypto.spec.PSource;
import java.util.ArrayList;

public class RemoteControl {
    //buttons are mapped to commands
    ArrayList<Object> buttons;
    ArrayList<Switch> onoffs;

    //objects have to be instantiated for actions to be performed on them, so we have to add them to a list of some kind.
    //commands possess objects but the remotecontrol doesn't.


    //we can add either switches or singular commands to our buttons.
    public void addButton(Command cmd) {
        if (buttons.size() > 7) {
            System.out.println("Buttons are full, please remove a button.");
        } else {
            buttons.add(cmd);
            System.out.println("Switch Function added to button " + buttons.indexOf(cmd));
        }
    }


    public void addButton(Command cmd, Command cmd2) {
        if (buttons.size() > 7) {
            System.out.println("Buttons are full, please remove a button.");
        } else {
            Switch myswitch = new Switch(cmd, cmd2);
            buttons.add(cmd);
            System.out.println("Switch Function added to button " + buttons.indexOf(cmd));
        }
    }

    //technically 14 on off buttons, but doing switches minimizes it.
    public void addSwitch(Command ON, Command OFF) {
        if (buttons.size() > 7) {
            System.out.println("Buttons are full, please remove a button.");
        } else {
            Switch myswitch = new Switch(ON, OFF);
            onoffs.add(myswitch);
            System.out.println("Switch Function added to button " + onoffs.indexOf(myswitch));
        }
    }

    public void pushonoff(int buttonno){
        onoffs.get(buttonno).flipswitch();
    }

    public void pushbutton(int buttonno) {
        if (buttons.get(buttonno) instanceof Switch) {
            ((Switch) buttons.get(buttonno)).flipswitch();
        } else if (buttons.get(buttonno) instanceof Command) {
            ((Command) buttons.get(buttonno)).execute();
        }
    }


    public static void main(String[] args) {
        RemoteControl remoteControl = new RemoteControl();
        Fan fan = new Fan();
        FanHIGH c1 = new FanHIGH(fan);
        FanLOW c2 = new FanLOW(fan);
        FanMED c3 = new FanMED(fan);
        //misc buttons for fan settings
        remoteControl.buttons.add(c1);
        remoteControl.buttons.add(c2);
        remoteControl.buttons.add(c3);
    }
}