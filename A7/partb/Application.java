package C322.homework7.partb;

import java.util.ArrayList;
import java.util.Stack;

public class Application {
    private ArrayList<Editor> editors;
    //combinations of commands, though an arraylist of commands could be used as well

    //both of these are aggregates of commands
    private ArrayList<Shortcuts> shortcuts;
    private ArrayList<Button> buttons;

    
    private Editor activeEditor;

    //clipboard is in editor, and command history is also in editor
    public Application() {
        editors = new ArrayList<Editor>();
        shortcuts = new ArrayList<Shortcuts>();
    }

    public void createUI() {
        System.out.println("UI CREATED");
    }
}