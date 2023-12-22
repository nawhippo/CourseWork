package C322.homework7.partc;

public class EmailAlertsListener implements EventListener{
    String filename;
    @Override
    public void update(String filename) {
        System.out.println("EmailAlert Listener filename: "+ filename);
        this.filename = filename;
    }
    public void sentEmailAlert(){
        System.out.println("Sending out alert for file: " + filename);
    }
}
