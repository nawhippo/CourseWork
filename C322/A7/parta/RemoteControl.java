package C322.homework7.parta;

public class RemoteControl {
    TV tv;
    RemoteControl(TV tv){
        this.tv = tv;
    }
    void PressSwitch(){
        this.tv.pressButton();
    }
}
