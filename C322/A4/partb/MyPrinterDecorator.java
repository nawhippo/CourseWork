package C322.homework4.partb;

public abstract class MyPrinterDecorator implements Printer{
    protected MyPrinter printer;

    public MyPrinterDecorator(MyPrinter decoratedmyPrinter){
        this.printer = decoratedmyPrinter;
    }
    @Override
    public void flushBuffer() {
    printer.flushBuffer();
    }
}
