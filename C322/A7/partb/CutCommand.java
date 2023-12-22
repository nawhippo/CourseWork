package C322.homework7.partb;

public class CutCommand extends Command {
    public CutCommand(Editor editor) {
        super(editor);
    }

    @Override
    public void execute() {
        //essentially deleting it.
        saveBackup();
        this.editor.copySelectedText();
        //copy it to clipboard and delete
        this.editor.deleteSelection(0,editor.getText().length());
        editor.getCommandHistory().push(this);
    }
}
