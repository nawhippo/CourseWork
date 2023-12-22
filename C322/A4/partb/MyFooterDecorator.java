package C322.homework4.partb;

public class MyFooterDecorator extends MyPrinterDecorator{
    @Override
    public void flushBuffer() {
        System.out.println("footer: " + footer);
        super.flushBuffer();
    }

    private String footer;
    public MyFooterDecorator(MyPrinter decoratedmyPrinter, String footer) {
        super(decoratedmyPrinter);
        this.footer = footer;
    }
}
