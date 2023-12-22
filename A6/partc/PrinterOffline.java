package C322.homework6.partc;

public class PrinterOffline implements PrinterState {
    public void handlePrint(Printer printer) {
        System.out.println("Powering on printer please wait..");
        printer.setState(new PrinterOnline());
    }
}
