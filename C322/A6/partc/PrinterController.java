package C322.homework6.partc;

import c322.homework.homework6.partc.Printer;
import c322.homework.homework6.partc.PrinterOffline;
import c322.homework.homework6.partc.PrinterOnline;

public class PrinterController {
    private Printer printer;

    public PrinterController(Printer printer) {
        this.printer = printer;
    }

    public void receivePrintJob() {
        printer.getState().handlePrint(printer);
        }

    public void resumePrintJob() {
        if(printer.getState() instanceof PrinterOffline){
            System.out.println("Printer offline...print job cannot be resumed");
        }
        if(printer.getState() instanceof PrinterOnline){
            System.out.println("Printing resumed!");
        }
    }
}