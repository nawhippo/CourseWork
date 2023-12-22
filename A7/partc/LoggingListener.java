package C322.homework7.partc;

public class LoggingListener implements EventListener{
    String filename;

    @Override
    public void update(String filename) {
        //functionally the same as the alerts listener
        System.out.println("Logging Listener filename: "+ filename);
        this.filename = filename;
    }
    public void logEvent(){
        System.out.println("Logging event to system for file: " + filename);
    }
}
