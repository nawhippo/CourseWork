package C322.homework3.partc;

public class Fan{
    String setting;
    //fans will work for any type of fan
    public void turnOn(){
        System.out.println("Fan is spinning");
    }
    public void turnOff(){
        System.out.println("Fan has stopped spinning");
    }
    public void high(){
        System.out.println("Fan is on high.");
        this.setting = "High";
    }
    public void medium(){
        System.out.println("Fan is on medium.");
        this.setting = "Medium";
    }
    public void low(){
        System.out.println("Fan is on low.");
        this.setting = "Low";
    }
    public void getState(){
        System.out.println("Fan is "+ this.setting);
    }
}
