package C322.homework6.partc;

public class Printer {
    private PrinterState state;

    public Printer(PrinterState initialState) {
        state = initialState;
    }

    public void pushPrint() {
        state.handlePrint(this);
    }

    public void setState(PrinterState state) {
        this.state = state;
    }

    public PrinterState getState() {
        return state;
    }
}