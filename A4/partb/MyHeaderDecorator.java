package C322.homework4.partb;

public class MyHeaderDecorator extends MyPrinterDecorator{
    @Override
    public void flushBuffer() {
        System.out.println("header: " + header);
        super.flushBuffer();
    }

    private String header;
    public MyHeaderDecorator(MyPrinter decoratedmyPrinter, String header) {
        super(decoratedmyPrinter);
        this.header = header;
    }
}
