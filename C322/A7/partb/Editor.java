package C322.homework7.partb;
public class Editor {
    public CommandHistory getCommandHistory() {
        return commandHistory;
    }

    public String getClipboard() {
        return clipboard;
    }

    public String getText() {
        return text;
    }

    private String clipboard = "";
    private String text;
    private CommandHistory commandHistory;


    public Editor() {
        this.text = "";
    }

    public String getSelection() {
        return text;
    }

    public void insertText(String newText) {
        this.text += newText;
    }

    public void deleteSelection(int startIndex, int endIndex) {
        this.text = this.text.substring(0, startIndex) + this.text.substring(endIndex);
    }

    public void replaceSelection(int startIndex, int endIndex, String replacementText) {
        this.text = this.text.substring(0, startIndex) + replacementText + this.text.substring(endIndex);
    }

    public void copySelectedText() {
        String selectedText = getSelection();
        if (selectedText != null && !selectedText.isEmpty()) {
            //copy it for later use
            clipboard = selectedText;
        }
    }
}