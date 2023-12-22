package C322.homework3.partc;

public class Switch {
    int state = 1;
    public Switch(Command flipup, Command flipdown){
        up = flipup;
        down = flipdown;
    }
    private Command up;
    private Command down;
    //a switch does one of two things, depending on what its set to.
    //it carries two functions which are bound to its up and down
    //it performs a command on an object, but doesn't technically possess it
    //this doesn't necessarily mean it's only an on/off switch.

    void flipswitch(){
        if(state == 1){
            state = 0;
            up.execute();
    } else {
            state = 1;
            down.execute();
            }
        }
        }
