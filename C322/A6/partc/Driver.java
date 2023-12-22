package C322.homework6.partc;

public class Driver {
        public static void main(String[] args) {

            PrinterOffline initialPrinterState = new PrinterOffline();

            Printer printer = new Printer(initialPrinterState);

            System.out.println("\n");

            printer.pushPrint();

            printer.pushPrint();

            printer.pushPrint();

            System.out.println("\n\n");

        }

    }
