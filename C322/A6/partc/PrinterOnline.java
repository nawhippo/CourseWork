package C322.homework6.partc;

public class PrinterOnline implements PrinterState {

    public void handlePrint(Printer printer) {
        System.out.println("Processing print job...");
        System.out.println(" . . . . ");
        System.out.println("Print job completed.");
        printer.setState(new PrinterOffline());
    }
}